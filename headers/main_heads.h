#ifndef MAIN_HEADS_H
#define MAIN_HEADS_H

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <math.h>

#define MAX_KEY_SIZE 20
#define MAX_FILE 100
#define MAX_THREAD 100
#define MAX_LINE_LEN 1024
#define INITIAL_SIZE 100

// structure for result variable
typedef struct result{
    char *buff;
    size_t count;
    size_t size;
    size_t capacity;
}result;

// global result variable
result my_result;

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
