

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>


volatile int done = 0;
//int done = 0;

//#define IS_SIG



#ifdef IS_SIG
void example_handler(int sig) {
    if (sig == SIGINT) {
        printf("Signal reseiverd ..\n");
        done = 1;
        signal(sig, SIG_DFL);
    }
}
#else
void * tfunc(void *arg) {
    printf("\tStarted 'thread1' ...\n");
    sleep(1);
    done = 1;
    printf("\tUpdated global variable\n");
    return NULL;
}
#endif // IS_SIG


int main() {

#ifdef IS_SIG
    signal(SIGINT, example_handler);
    printf("Execute 'signal' example ...\n");
#else
    pthread_t t1;
    pthread_create(&t1, NULL, tfunc, NULL);
#endif // IS_SIG

    printf("Waiting to 'done' becomes 'True' ...\n");

    while(!done) {}

    printf("Ok. Moving on ...\n");


    printf("DEFINE_VALUE: %d\n", DEF_VALUE);  // DEV_VALUE will be passed throug the compile option


    return 0;
}