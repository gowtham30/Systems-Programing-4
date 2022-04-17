#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
int job = 0;

struct cmds{
    int jobid, P;
    char command[100];
    char status;
    char tkn[100];
    char tkn1[100];
    char tkn2[100];

};
//thread2 executer
void *thread2(void *arg)
{
    // struct cmds thread2_cmds = (struct cmds) arg;
    // tkn1 = thread2_cmds->tkn1;
    // tkn2 = strtok(tkn1, " "); //ls
    // tkn3 = strtok(tkn2, " "); //l

    // execvp(tkn2, tkn3);

    printf("hu 324");

}

//thread1 checkong the p value with jobs running
void *thread1(void *arg)
{
    struct cmds thread1_cmds = (struct cmds) arg;
    int jobid, pval;
    char *tkn1;
    // char *tkn2;
    // char *tkn3;
    // tkn1 = thread1_cmds -> tkn1;
    // tkn2 = strtok(NULL, " ");
    // tkn3 = strtok(NULL, " ");

    // execvp(tkn2, tkn3);
    jobid = thread1_cmds->jobid;
    //printf("%d", jobid);
    pval = thread1_cmds->P;
    //printf("%d", pval);
    tkn1 = thread1_cmds->tkn1;
    //printf("jhg");
    //fflush(stdout);


    while(1)
    {
        if(jobid<pval) //check if and else condition
        {
            // printf("%s", tkn1);
            pthread_t *tid1;
            // printf("iu");

            pthread_create(&tid1[job], NULL, thread2, (void *)&thread1_cmds[job]);

            
        }
        else exit;
    }


}
int main(int argc, char **argv)
{

    int jobid = 0, i=0, j=0, p;
    p = atoi (argv[1]);
    
    struct cmds *arr_cmds = malloc(1000 * sizeof (struct cmds));
    

    pthread_t *tid;
    char *line=NULL;
    size_t maxlen=0;
    ssize_t n;
    char *tkn;
    char *tkn1;
    char *tkn2;
    arr_cmds[job].P = p;
    while (1){
        printf("Enter command  ");
        if ( (n = getline(&line, &maxlen, stdin)) > 0)
        {
            tkn = strtok(line, " ");
            printf("%s\n", tkn);
            

            //printf("%s\n",tkn);
            //printf("%d\n", strcmp(tkn, "submit"));
            if(strcmp(tkn, "submit") == 0)
            {
                tkn1 = strtok(NULL, "");
                arr_cmds[job].jobid = jobid;
                //tkn2 = strtok(NULL, "");
                
                strcpy(arr_cmds[job].tkn1, tkn1);
                
                //printf("G");
                pthread_create(&tid[job], NULL, thread1, (void *)&arr_cmds[job]);
                
                
                
                //printf("%s %s", tkn1, tkn2);
            }
            //incrementing jobid after each submit
            jobid = jobid++; 

            //printf("%s\n",tkn);
            //printf("%s\n",tkn1);
            //arr_cmds[i].jobid = job;
            //printf("hi1");
            //printf("%s",tkn     );   

        }
    }


    return 0;
}