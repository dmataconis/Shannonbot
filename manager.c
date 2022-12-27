/*
 * manager.c
 *
 * David Mataconis
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>



int main(int argc, char **argv){
 //make sure theres correct amount of arguments
 if (argc != 4){
    printf("%s num\n", argv[0]);
    exit(-1);
}
 int length = atoi (argv[1]);
 int robots = atoi(argv[2]);
 int processors = atoi(argv[3]);
 //num of robots per simulation & if theres a remainder
 int remainder = robots % processors;
 int robots_per_sim = robots / processors;
 char hi[300];
 char bye[300];
 char yo[300];
 //change comand line arguments that will go into sim
 for (int i = 0; i < processors; i++){
    pid_t pid = fork();
    if (i == processors-1){
     robots_per_sim += remainder;
}
    if (pid == 0){
      argv[0] = "./sim";
      sprintf(bye, "%d", robots_per_sim);
      sprintf(yo, "%d", length);
      argv[1] = yo;
      argv[2] = bye;
      sprintf(hi, "%d", i+1);
      argv[3] = hi;
      execv("./sim", argv);

}
}
 //wait for children
 for (int i = 0; i < processors; i++){
  wait(NULL);
}
 double num;
 int count = 1;
 double sum = 0;
 char sup[100];
 //read from files and add sum
 while (count <= processors){
  sprintf(sup, "robot-output-%d.txt", count);
  FILE *fd = fopen(sup, "r");
  fscanf(fd, "%lf", &num);
  sum += num;
  fclose(fd);
  count++;
}
 //compute average
 double average = sum / robots;
 printf("Simulation Complete.\nSTAD: %lf cm\n", average);
 }

      
