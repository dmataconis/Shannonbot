# Shannonbot
Run code faster by creating different child processes with fork and then calling excecv to parent.  Create file in parent, write into file, and then wait for child processes to finish in parent. Once finished, open back up file and compute the average.
Sim.c can run by itself but manager.c needs sim.c in order to run correctly.

Purpose:
There is a robot that is placed in the middle of a table with a length(in cm) inputed by user. The robot then moves 10 cm in any random direction until it falls off the table. Compute the average.

Sim.c:
Runs code of the robot moving 10 cm in any direction. Creates a single file and prints the average of all robots into that file.


Manager.c:
Accepts 3 arguments. #1 length of table(in cm), #2 number of robots, #3 number of processes/simulation.
Managers job is to call Sim.c and then print the average of all the files made.
