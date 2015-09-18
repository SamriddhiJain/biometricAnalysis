// ASSIGNMENT 1
// Due Date 28 Aug, 2015 
//Authors : Samriddhi Jain | Ayush Yadav
//CS 307
//File 1.5

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define mult 1000000


float abs1(float x){
	return (x>0)? x:(-1*x);
}

int main(int argc,char** argv){
	int ar_gen[mult+2];
	int ar_imp[mult+2];

	FILE *fp,*fp2,*imph,*genh;

	// time_t t=time(NULL);
	int No_val=atoi(argv[1]);

	fp=fopen(argv[2], "r");
	fp2=fopen("FRR_FAR_Data.dat", "w");
	imph=fopen("L4_I_Hist.dat", "w");
	genh=fopen("L4_G_Hist.dat", "w");

	int i=0;
	int true_val=0;
	float score=0.;
	int a,b,c,d;
	float temp=0.,temp2=0.;
	int imp=0,gen=0;
	int ar_addr=0;
	for (i=0;i<=(mult+1);i++){
		ar_gen[i]=0;
		ar_imp[i]=0;
	}
	for (i=0;i<(No_val);i++){
		fscanf(fp, "%d %d %d %d %d %f", &a, &b, &c, &d, &true_val, &score);
		ar_addr=(int) mult*score;
		if(true_val==1){
			ar_gen[ar_addr]++;
			gen++;
		}	
		else{
			ar_imp[ar_addr]++;
			imp++;
		}	
	}
	for(i=0;i<=mult;i++){
		if(ar_imp[i]){
			temp=(((float)ar_imp[i])/((float)imp))*100;
			fprintf(imph, "%d  %.6f\n", i,temp);
		}
		if(ar_gen[i]){
			temp2=(((float)ar_gen[i])/((float)gen))*100;
			fprintf(genh, "%d  %.6f\n", i,temp2);
		}
	}
	for (i=1;i<=mult;i++){
		ar_imp[i]+=ar_imp[i-1];
		ar_gen[mult-i]+=ar_gen[mult-(i-1)];
	}
	float g1=0.,i1=0.,thresh1=0.,thresh2=0.;
	float min=100.0;
	float te=0.;
	ar_gen[mult]=0;
	for (i=0;i<=mult;i++){
		g1=(((float)ar_gen[i])/((float)gen))*100;
		i1=(((float)ar_imp[i])/((float)imp))*100;	
		if(abs1(g1-i1)<min){
			min=abs1(g1-i1);
			thresh1=g1;
			te=(float)i/mult;
			thresh2=i1;
		}
		fprintf(fp2,"%d    %d     %f    %d    %f\n",i,(ar_gen[0]-ar_gen[i]),g1,ar_imp[i],i1);
	}	
	float eer = (thresh1+thresh2)/2.0;
	// t=time(NULL)-t;
	// printf("Time Taken(s) >> %ld\n",t);
	printf("# of Gen >>\n%d\n# of Imp >>\n%d\n",gen, imp);
	printf("FRR>>\n%.6f\nFAR>>\n%.6f\nDifference>>\n%.6f\nEER>>\n%.6f\nThresh-Hold>>\n%.6f\n",thresh1,thresh2,min,eer,te);
	fclose(fp);
	fclose(fp2); 
	return 0;
}