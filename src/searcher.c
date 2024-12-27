#include "../headers/main_heads.h"

void *search(void *param){
    arg *my_arg = (arg *)param;

    int line_num = 0;// line number in a file
    char line[MAX_LINE_LEN];// string to hold the each line in a file

    FILE *file = fopen(my_arg->filename, "r");// file we are reading from
    
    if(!file){
        perror("Error opening file\n");
        pthread_exit(NULL);
    }

    while(fgets(line, sizeof(line), file)){// reading each line from 
        line_num++;
        if(strstr(line, my_arg->keyword)){
            pthread_mutex_lock(&lock);
            sprintf(result + strlen(result), "FILE: %s - line number: %d\n", my_arg->filename, line_num);
            pthread_mutex_unlock(&lock);
        }
    }
    fclose(file);
    free(my_arg->filename);
    free(my_arg);
    pthread_exit(NULL);
    return NULL;
}
