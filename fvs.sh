out='score.png'
gnuplot << PLOTTHIS
set term postscript eps enhanced color  "Helvetica" 32

set terminal png
set output "${out}"
set autoscale
unset log                              
unset label
set grid 
set title "Frequency v/s Score"
set key right top

set ylabel "Frequency (%)"
set xlabel "Score (%)"

#set format x "10^{%L}"

##########################
#set xrange [9100:9500]
#set yrange [0:10]
set xtics (100000,1000000)
#########################
##############################################################

plot "L4_G_Hist.dat" title 'Genuine',"L4_I_Hist.dat" title 'Imposter' lc rgb 'green'
plot "L4_G_Hist.dat" title 'Genuine' with impulses lt 1,"L4_I_Hist.dat" title 'Imposter' with impulses lt 2 lc rgb 'green'


##############################################################

##############################################################
pause mouse
PLOTTHIS


