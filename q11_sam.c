// ASSIGNMENT 1
// Due Date 28 Aug, 2015 
//Authors : Samriddhi Jain | Ayush Yadav
//CS 307
//File 1.4

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define precision 0.000001
#define mult 1000000


float abs1(float x){
	return (x>0)? x:(-1*x);
}

int main(int argc,char** argv){
	FILE *fp,*fp2,*fp3,*crr,*ncrr;
	// time_t t=time(NULL);
	int No_val=atoi(argv[1]);
	fp=fopen(argv[2], "r");
	// fp=fopen("L4.txt", "r");
	fp2=fopen("FA.txt", "w");
	fp3=fopen("FR.txt","w");
	crr=fopen("CRR.dat","w");
	ncrr=fopen("NCRR.txt","w");
	float thresh=atof(argv[3]);
	int facnt=0,frcnt=0;
	int flag=0;
	int i=0;
	int true_val=0;
	float score=0.;
	int a,b,c,d;
	int cntcrr=0,cntncrr=0;
	int s1prev=0,p1prev=0,sgprev=0,pgprev=0,siprev=0,piprev=0;
	float scorei=1,scoreg=1;
	
	for (i=0;i<(No_val);i++){
		fscanf(fp, "%d %d %d %d %d %f", &a, &b, &c, &d, &true_val, &score);
		//falsely accepted and rejected
		if((true_val==0) && (score<thresh)){//Falsely Accepted
			facnt++;
			fprintf(fp2,"%3d \t%2d \t%3d \t%2d \t%1d \t%.6f\n",a,b,c,d,true_val,score);
		}else if((true_val==1)&&(score>thresh)){//Falsely Rejected
			frcnt++;
			fprintf(fp3,"%3d \t%2d \t%3d \t%2d \t%1d \t%.6f\n",a,b,c,d,true_val,score);
		}	

		//for crr and ncrr
		if(s1prev==a && p1prev==b){
			if(true_val==1){
				if(score<scoreg){
					sgprev=c;
					pgprev=d;
					scoreg=score;
				}
			}else{
				if(score<scorei){
					siprev=c;
					piprev=d;
					scorei=score;
				}
			}
		}else{
			if(flag){
				if(scorei>scoreg){
					fprintf(crr,"%3d %3d\t\t[(%d, %d)%.6f]\t\t\t[(%d, %d)%.6f]\t%.6f\t1\n",s1prev,p1prev,sgprev,pgprev,scoreg,siprev,piprev,scorei,(scoreg/scorei));
					cntcrr++;
				}
				else{
					fprintf(ncrr,"%3d %3d\t\t[(%d, %d)%.6f]\t\t[(%d, %d)%.6f]\t%.6f\t0\n",s1prev,p1prev,sgprev,pgprev,scoreg,siprev,piprev,scorei,(scoreg/scorei));
					cntncrr++;
				}
			}
			else
				flag=1;

			s1prev=a;
			p1prev=b;
			sgprev=0;
			pgprev=0;
			siprev=0;
			piprev=0;
			scorei=1;
			scoreg=1;

			if(true_val==1){
				sgprev=c;
				pgprev=d;
				scoreg=score;	
			}else{
				siprev=c;
				piprev=d;
				scorei=score;
			}
		}
	}
	cntcrr++;
	float crrp=(((float)cntcrr)/((float)cntcrr+(float)cntncrr))*100;
	printf("Imposter matchings falsely accepted >>\n%d\n",facnt);
	printf("Genuine matchings falsely rejected >>\n%d\n",frcnt);
	printf("Correctly recognised >>\n%d\n",cntcrr);
	printf("Failed Recognition >>\n%d\n",cntncrr);
	printf("Correct Recognition Rate>>\n%f\n",crrp);
	// t=time(NULL)-t;
	// printf("%ld\n",t);
	fclose(fp);
	fclose(fp2);
	fclose(fp3);
	fclose(crr);
	fclose(ncrr);
	return 0;
}      
