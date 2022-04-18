# Systems-Programing-HW4

#homework 4

Write a C program to implement a simple job scheduler that executes non-interactive jobs (e.g., jobs that 
do not have direct user interaction, jobs that can run in the background).  

#description

In this project we will implement a simple job scheduler that will execute non-
interactive jobs (for example, jobs that do not have direct user interaction, jobs that can 
run in the background).  
At any given time, only P jobs should be executing, and P is provided as an argument 
to your program.  
If you have more than P jobs submitted, then these additional jobs must wait until one 
of the P executing jobs are completed.  
You can assume that P is typically the number of cores that are available on a system 
and you are executing one process per core and if there are more jobs than the 
available number of cores these jobs must wait for one of the processes to complete.  
 When you launch the program with P as the command-line argument, the program 
should print a prompt and wait for the user to enter commands.  
As the jobs are non-interactive, the output and error streams from the job must be 
written to separate files - <jobid>.out and <jobid>.err, where <jobid> is the appropriate 
job id that is associated with a job.

#getting started

 We are considered to take four jobs to run in a process and when another job we call it as fifth job is about to run, one of the job should complete its running inorder to run the fifth job one of the above should done its process and till then, this job should be in waiting process. In doing this process, we are using threads, fork and execvp along with command-line arguments. And in later we display the jobs with the status.

# installing

 A step by step series of examples that tell you how to get a development environment running
1. open the text editor
2. create a c programming file
3. save the file with .c extension.
  
# Running the tests

 got the input with getline and tokenized the first argument wsubmit 
  
In general a c program is executed in this way:
1. To compile the file, type the command 'gcc filename.c'
2. To run the file, type './a.out'

To test our program, follow the below steps

1. gcc homework3.c
2. ./a.out 

 
#output: gcc homework4.c```
Enter command  submit sleep 40                                                                                                                                         Enter command  submit sleep 30                                                                                                                                          Enter command  submit 50                                                                                                                                                Enter command  submit sleep 50                                                                                                                                                         Enter command  showjobs                                                                                                                                                                                            0 sleep 40 Running                                                                                                                                                                                                 1 sleep 30 Running                                                                                                                                                                                                 2 50 Waiting                                                                                                                                                                                                       3 sleep 50 Waiting 
 ```

 
 
