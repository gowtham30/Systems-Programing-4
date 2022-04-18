#include "queue.h"

int counter =0;
int jobid = 0;
// thread2 executer
void *thread2(void *arg)
{

    pid_t pid;
    int status;
    pid = fork();
    counter++;



    arr_cmds[jobid-1].status = "Running";
    
    if (pid == 0)
    { /* this is child process */

        char fd[100];
        sprintf(fd, "%d.out", getpid());
        int fd1 = open(fd, O_WRONLY | O_CREAT, 0755);
        dup2(fd1, 1);

        // char fd[100];
        sprintf(fd, "%d.err", getpid());
        int fd2 = open(fd, O_WRONLY | O_CREAT,0755);
        dup2(fd2, 2);

        execvp(command[0], command);
        perror("exec");

        exit(-1);
    }
    else if (pid > 0)
    {   

        // strcpy(arr_cmds[jobid].status, "RUnn");  
        //printf("hi");
        //printf("%d",jobid);
        
        

        wait(&status);
        arr_cmds[jobid-1].status = "Done";



    }
    counter--;

    return NULL;

   // printf("thread2");
}

// thread1 checkong the p value with jobs running
void *thread1(void *arg)
{
    // struct cmds *thread1_cmds = (struct cmds *)arg;
    //int pval;

    pthread_t tid1;

    // fflush(stdout);
    // int val = 0;
    while (1)
    {
        // if (jobid < p && val < 1) // check if and else condition
        if (counter < p && q->count > 0) // check if and else condition
        {

            // printf("%s", tkn1);
            // printf("iu");
            int id = queue_delete(q);

            pthread_create(&tid1, NULL, thread2, NULL);
            // val++;
        }
        // else printf("exit");
    }
    return NULL;
}

int main(int argc, char **argv)
{
    int job = 0;

    int i = 0, j = 0;
    p = atoi(argv[1]);

    
    q = queue_init(1000);

    arr_cmds = malloc(1000 * sizeof(struct cmds));

    pthread_t tid;
    char *line = NULL;
    size_t maxlen = 0;
    ssize_t n;
    char *tkn;
    char *tkn1;
    char *tkn2;
    //arr_cmds[job].P = p;

    pthread_create(&tid, NULL, thread1, NULL);

    while (1)
    {
        printf("Enter command  ");
        if ((n = getline(&line, &maxlen, stdin)) > 0)
        {
            tkn = strtok(line, " ");

            // submit is stored in tkn
            tkn[strcspn(tkn, "\r\n")] = 0;


            if (strcmp(tkn, "submit") == 0)
            {
                // add jobid to queue, update structure
                tkn1 = strtok(NULL, "");
                queue_insert(q, jobid);

                int j = 0;
                tkn1[strcspn(tkn1, "\r\n")] = 0;

                // update strcuture value
                strcpy(arr_cmds[jobid].command, tkn1);
                arr_cmds[jobid].jobid = jobid;
                arr_cmds[jobid].status = "Waiting";
                // strcpy(arr_cmds[jobid].status, "Waiting");  
    
                jobid++;

                char *newtoken = strtok(tkn1, " ");
                while (newtoken != NULL)
                {  
                    
                    command[j++] = newtoken;
                    
                    newtoken = strtok(NULL, "");
                }


                         
                         
            }

             if(strcasecmp(tkn, "showjobs") == 0)
            {
                queue_display(q,"showjobs");
            }
            else if(strcmp(tkn, "submithistory") == 0)
            {
                // if(strcmp(arr_cmds[jobid].status, "Done"))
                // {
                  queue_display(q,"submithistory");
                // }
                
            }


        }
    }
    

    return 0;
}