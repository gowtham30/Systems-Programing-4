#include"queue.h"
int job = 0;
int jobid = 0;
char *command[1000];

struct cmds
{
    int jobid;
    int P;
    char *command[100];
    char status;
};
// thread2 executer
void *thread2(void *arg)
{
    // struct cmds *thread2_cmds = (struct cmds*) arg;
    // tkn1 = thread2_cmds->tkn1;
    // tkn2 = strtok(tkn1, " "); //ls
    // tkn3 = strtok(tkn2, " "); //l
    pid_t pid;
    int status;
    pid = fork();
    if (pid == 0)
    {
        
        execvp(command[0], command);
        perror("exec");
        exit(-1);
    }
    else if(pid>0)
    {
        wait(&status);

    }
    // if (pid == 0)
    // { /* this is child process */

    //     // char fd[100];
    //     // sprintf(fd, "%d.out", getpid());
    //     // int fd1 = open(fd, O_WRONLY | O_CREAT, 0755);
    //     // dup2(fd1, 1);

    //     // // char fd[100];
    //     // sprintf(fd, "%d.err", getpid(), 0755);
    //     // int fd2 = open(fd, O_WRONLY | O_CREAT);
    //     // dup2(fd2, 2);

    // execvp(args[0], args);
    // perror("exec");
    // exit(-1);
    // }

    // execvp(tkn2, tkn3);

    printf("thread2");
}

// thread1 checkong the p value with jobs running
void *thread1(void *arg)
{
    // struct cmds *thread1_cmds = (struct cmds *)arg;
    int pval;
    // char *tcommand;
    pthread_t *tid1;
    // char *tkn2;
    // char *tkn3;
    // strcoy(tcommand, thread1_cmds -> command);
    // tkn2 = strtok(NULL, " ");
    // tkn3 = strtok(NULL, " ");
    // printf("%s", tcommand);

    // execvp(tkn2, tkn3);
    /// jobid = thread1_cmds->jobid;
    // printf("%d", jobid);
    // pval = thread1_cmds->P;
    // printf("%d", pval);
    // tkn1 = thread1_cmds->tkn1;
    // printf("%s", command);
    // fflush(stdout);
    int val = 0;
    // printf("iu");
    // printf("%s", tkn);

    // while (1)
    // {
    //     // printf("iu");
    //     if (jobid < pval && val ==0) // check if and else condition
    //     {
            // printf("%s", tkn1);
            // printf("iu");

            pthread_create(&tid1[jobid], NULL, thread2, NULL);
            // val++;
            // val = jobid - val;
    //     }
    //     // else printf("exit");
    // }
}
int main(int argc, char **argv)
{

    int i = 0, j = 0, jobid = 0, p;
    p = atoi(argv[1]);

    struct cmds *arr_cmds = malloc(1000 * sizeof(struct cmds));
    // arr_cmds->jobid = jobid

    pthread_t *tid;
    char *line = NULL;
    size_t maxlen = 0;
    ssize_t n;
    char *tkn;
    char *tkn1;
    char *tkn2;
    arr_cmds[job].P = p;
    while (1)
    {
        printf("Enter command  ");
        if ((n = getline(&line, &maxlen, stdin)) > 0)
        {
            tkn = strtok(line, " ");

            // tkn have submit

            if (strcmp(tkn, "submit") == 0)
            {
                //add jobid to queue, update structure
                tkn1 = strtok(NULL, "");
                // int j = 0;
                // printf("%s", tkn1);
                int j = 0;
                tkn1[strcspn(tkn1, "\r\n")] = 0;
                //update strcuture value
                char *newtoken = strtok(tkn1, " ");
                while (newtoken != NULL)
                {
                    // strcpy(command[j],tkn1[j]);
                    command[j++] = newtoken;
                    //  command = tkn
                    // strcpy(arr_cmds[jobid].command[j], tkn);
                    newtoken = strtok(NULL, "");
                }

                // strcpy(arr_cmds[jobid].tkn1, tkn1);

                // strcpy (arr_cmds[jobid].command, tkn1);
                // strcpy(command, tkn1);
                pthread_create(&tid[jobid], NULL, thread1, NULL);
                // printf("%s", command[0]);
                jobid++;
                // printf("%s %s", tkn1, tkn2);
            }

            // printf("%s\n",tkn);
            // printf("%s\n",tkn1);
            // arr_cmds[i].jobid = job;
            // printf("hi1");
            // printf("%s",tkn     );
        }
    }

    return 0;
}