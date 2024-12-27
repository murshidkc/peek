#ifndef MAIN_HEADS_H
#define MAIN_HEADS_H

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>

#define MAX_KEY_SIZE 20
#define MAX_FILE 100
#define MAX_THREAD 100
#define MAX_LINE_LEN 1024

// global varial to store result
char result[1000];
// mutex lock to ensure the synchronization of result
pthread_mutex_t lock;

// argument structure of pthread function
typedef struct arg{
    char *filename;
    char *keyword;
    int word_size;// if needed
}arg;

// function definition of basic pthread function
void *search(void *);

#endif
