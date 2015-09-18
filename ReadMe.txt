To use the files and get the results, do as follows,

Requirements:
1> The folder should be having a Data File named "L4.txt" in the directory for proper execution of the script
2> GNUPlot must be configured in your OS

Normal Mode:
1--Go to Terminal, go to the directory where the code and files are stored and type the command >>>bash final.sh 
2--This will clear the screen and start a Timer, which will mean the code is now in execution and as the code works out (in about ~120 secs) the screen will have a output on screen with required parameters.

Advanced:
1-- If you modify the C-Code inside the folder, then compile it with the output file of q1.c being q1 >[gcc -o q1 q1.c]< and that of q11_sam.c as q11 
>[gcc -o q11 q11_sam.c]<.
2-- The run the script using command  >bash final.sh

The same return values and procedure is followed as in Normal Mode here forth.
The Outputs are stored in various files in the folder, the most important being with all the stats names >>>L4.sts 
The graphs will also be available in the same folder as original data as .png file.