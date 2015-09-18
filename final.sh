clear
date +"%T"
a=`wc -l L4.txt`
./q1 $a > test_q1.txt
date +"%T"
b=`tail -1 test_q1.txt`
./q11 $a $b > test_q11.txt
date +"%T"
echo "************************************************************************************************"
echo "================================================================================================"
# cat test_q1.txt
# cat test_q11.txt
# date +"%T"
bash fvs.sh
bash g.sh
bash outp.sh > L4.sts
cat L4.sts
