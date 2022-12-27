/*
 * ShannonBot
 * David Mataconis
 *
 */
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <sys/types.h>
#include <unistd.h>

#define UNIT_STEP 10
#define RADIANS(x) x*(M_PI/180.0)


int robotSim(int len){
   double x = len / 2.0;  // find middle of table
   double y = len / 2.0;

   int num_steps = 0;

   while (1){  // infinite loop, 1 = true in C
      // randomly choose direction
      double direction = rand() % 360;

      // move the robot
      x += cos(RADIANS(direction)) * UNIT_STEP;
      y += sin(RADIANS(direction)) * UNIT_STEP;

      // took another step
      num_steps++;

      // did we fall off?
      if (x > len || y > len || x < 0 || y < 0){
         break;}
}
return num_steps * UNIT_STEP; }
int main(int argc, char **argv) {
  

   // error checking
   if (argc !=  4){
      printf("%s length iterations\n", argv[0]);
      exit(-1); }

   int length = atoi(argv[1]); // length of table
   int how_many = atoi(argv[2]); // how many times the robot is ran
   int processors = atoi(argv[3]);
   // seed the random number generator
   srand(getpid());

   // perform the simulations
   double sum = 0.0;
   for (int i = 0; i < how_many; i++) {
      int current = robotSim(length);
      sum += current;
  }
   //Create a file named robot-outputi{id}.txt
   char robottxt[100];
   sprintf(robottxt, "robot-output-%d.txt", processors);

   //Open the file and print Data into it
   FILE *fd = fopen(robottxt, "w");
   fprintf(fd, "%f\n",sum);
   fclose(fd);

}
