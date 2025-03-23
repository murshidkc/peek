#include "../headers/main_heads.h"

// initializing the result structure
void init_result(int init_size){
    my_result.buff = malloc(init_size * sizeof(char));
    my_result.count = 0;
    my_result.size = 0;
    my_result.capacity = init_size;

    return;
}

// function to convert number to number of digits
int num_to_dig(int n){
    return (n == 0) ? 1 : log10(n) + 1;
}

// function to add to result
// if result buffer is full resizes it using realloc
void add_to_result(char filename[], int line_num){
    int rem = my_result.capacity - my_result.size;

    int add_on = 23 + strlen(filename) + num_to_dig(line_num);

    if(add_on >= rem){
        my_result.capacity *= 2;
        char *new_buff = realloc(my_result.buff, my_result.capacity);
        if(new_buff == NULL){
            printf("Memory allocation while adding a result failed\n");
            exit(EXIT_FAILURE);
        }
        my_result.buff = new_buff;
    }
    sprintf(my_result.buff + my_result.size, "FILE: %s - line number: %d\n", filename, line_num);
    my_result.size += add_on;

    return ;
}

void *search(void *param){
    arg *my_arg = (arg *)param;

    int line_num = 0;// line number in a file
    char line[MAX_LINE_LEN];// string to hold the each line in a file

    FILE *file = fopen(my_arg->filename, "r");// file we are reading from
    
    if(!file){
        perror("Error opening file\n");
        free(my_arg->filename);
        free(my_arg);
        pthread_exit(NULL);
    }

    while(fgets(line, sizeof(line), file)){// reading each line from 
        line_num++;
        if(strstr(line, my_arg->keyword)){
            pthread_mutex_lock(&lock);
            add_to_result(my_arg->filename, line_num);// function to add to result
            my_result.count++;
            pthread_mutex_unlock(&lock);
        }
    }
    fclose(file);
    free(my_arg->filename);
    free(my_arg);
    pthread_exit(NULL);
    return NULL;
}
