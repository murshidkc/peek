#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_FILE 100
#define MAX_THREAD 100

void *search(void *param){
    int ch;
    char *filename = (char *)param;
    FILE *file = fopen(filename, "r");
    if(!file){
        perror("Error opening files\n");
        pthread_exit(NULL);
    }
    while(fgetc(ch)){
        while(ch == ' '){

        }
    }
    return NULL
}

int main(){
    pthread_t my_threads[TOT_THREAD];
}
