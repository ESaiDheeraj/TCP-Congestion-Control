I have recorded a testing session with 'script' command in python.
In order to replay it type the following in terminal
$ scriptreplay file_time shell_record.md

The following are the things I have done in the recorded session:

The first command to run is
$ make
(Above command generate the executable for cw.cpp as cw and then gives following 2 lines)
Run the following command :
bash script.sh

Next, run the following command 
$ bash script.sh

The bash script will run the cw executable 2^5 = 32 times for the given input values.

For every K in [1,32] the output file is outputK.txt and the python program takes this
output file as input and gives figK.txt which contains the plot.

Once running of bash script ends, you can find the output files and their 
respective plots in the same folder which contains this README.md file.