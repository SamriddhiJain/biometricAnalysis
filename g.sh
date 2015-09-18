out='g1.png'
gnuplot << PLOTTHIS
set term postscript eps enhanced color  "Helvetica" 32

set terminal png
set output "${out}"
set autoscale
unset log                              
unset label
set grid 
set title "FAR Vs FRR"
set key right top

#set ylabel "Frequency (%)"
#set xlabel "Score (%)"
#set format x "10^{%L}"

##########################
#set xrange [9100:9500]
#set yrange [0:0.8]
#########################

set logscale x
set xrange [:100]
#set yrange [:100]
set xtics (0.0001,0.001,0.01,0.1,1,10,100)
#set xtics (0.2,0.25,0.5,0.75,1)

#set xlabel "Threshold"
#set ylabel "FAR/FRR (%)"

set xlabel "FAR (%)"
set ylabel "FRR (%)"

##############################################################

plot "FRR_FAR_Data.dat" using 5:3 title 'FAR v/s FRR' w linespoints


##############################################################

##############################################################
pause mouse
PLOTTHIS


