#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int msum , csum;
void *runner(void *param);

int main() {
    pthread_t pid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    int number;
    
    printf("Enter your number : ");
    scanf("%d", &number);
    char n = number +'0';
   
    pthread_create(&pid, &attr, runner, &n);
    pthread_join(pid,NULL);
    
    for (int i = 1;i <= number; i++) {
        msum += i;
    }
    printf("csum = %d\n" , csum);
    printf("msum = %d\n" , msum);
    
    printf("difference = %d",csum-msum);
    return 0;
}

void *runner(void *param) {
    int number = atoi(param);
    int i;
    csum = 0;
    
    for (i = 0; i <= 2*number; i++) {
        csum += i;
    }

    pthread_exit(0);
}