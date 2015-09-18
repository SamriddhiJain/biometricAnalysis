# clear
# date +"%T"
# aa=`wc -l L4.txt`
# ./q1 $a > test_q1.txt
# date +"%T"
# b=`tail -1 test_q1.txt`
# ./q11 $a $b > test_q11.txt
# date +"%T"
# # cat test_q1.txt
# # cat test_q11.txt

# echo "Total number of Data Values $aa (File Name)"
echo "**************************************************************************************"
a=`tail -1 test_q11.txt | head -1`
echo "Performance Parameters
==========================="
echo "Correct Recognition Rate (CRR) =   	~$a"
# echo "**************************************************************************************"
b=`tail -3 test_q1.txt | head -1`
c=`tail -1 test_q1.txt | head -1`
d=`tail -5 test_q1.txt |head -1`
echo "Equal Error Rate         (EER) = 	 ($b)  $c with Difference = $d"
echo "**************************************************************************************************************************************"
echo "Failed Subject in Identification (CRR Failure)"
echo "==========================="
cat NCRR.txt
echo "+++++++++++++++++++++++++++++++++++++++++++++++++++++"
e=`tail -3 test_q11.txt | head -1`  
f=`tail -5 test_q11.txt | head -1`
g=$((e+f))
echo "Total Failed Subject =   $e (out of $g)"
echo "+++++++++++++++++++++++++++++++++++++++++++++++++++++
**************************************************************************************************************************************
+++++++++++++++++++++++++++++++++++++++++++++++++++++"
h=`tail -13 test_q1.txt |head -1`
i=`tail -7 test_q11.txt | head -1`
echo "Total No. of Falsely Reject Matching =   $i out of total $h genuine matching
+++++++++++++++++++++++++++++++++++++++++++++++++++++
**************************************************************************************************************************************
+++++++++++++++++++++++++++++++++++++++++++++++++++++"
j=`head -2 test_q11.txt |tail -1`
k=`head -4 test_q1.txt | tail -1`
echo "Total No. of Falsely Accept Matching =   $j out of total $k imposter matching
+++++++++++++++++++++++++++++++++++++++++++++++++++++
**************************************************************************************************************************************"
l=`head -6 test_q1.txt | tail -1`
m=`head -8 test_q1.txt | tail -1`
echo "Actual Performance Parameters
===========================
False Acceptance Rate        (FAR) = 		~$m
False Rejection  Rate        (FAR) = 		~$l
**************************************************************************************************************************************"


