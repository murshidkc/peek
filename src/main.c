#include "searcher.c"
#include "../headers/main_heads.h"

int main(int argc, char *argv[]){
    bool flag_a = false;
    if(argc < 3){
        print_usage(argv[0]);
        return 0;
    }

    // flag setting to search for files starting with dot(.)
    if(argc > 3) {
        if(!strncmp(argv[3], "-a", 2)){
            flag_a = true;
        }else{
            print_usage(argv[0]);
        }
    }

    int i = 0;
    
    pthread_t my_threads[MAX_THREAD];// threads available
    pthread_mutex_init(&lock, NULL);// initializing the mutex lock
    init_result(INITIAL_SIZE);
    
    DIR *dir = opendir(argv[1]);// opens the Directory from the directory path
    
    if(dir == NULL){// if fails to open
        printf("Error Opening Directory\n");
        free(my_result.buff);
        pthread_mutex_destroy(&lock);
        return EXIT_FAILURE;
    }
    struct dirent *entry;
    
    while((entry = readdir(dir)) != NULL){
        if(!flag_a && entry->d_name[0] == '.'){
            continue;
        }
        // if successfully added entry as a file
        arg *my_args = malloc(sizeof(arg));

        my_args->keyword = argv[2];
        int len_file_name = strlen(argv[1]);

        my_args->filename = malloc((strlen(entry->d_name) + len_file_name + 2) * sizeof(char));

        if(argv[1][len_file_name - 1] != '/'){
            sprintf(my_args->filename, "%s/%s", argv[1], entry->d_name);
        }else{
            sprintf(my_args->filename, "%s%s", argv[1], entry->d_name);
        }

        if(pthread_create(&my_threads[i], NULL, search, (void *)my_args) != 0){
            printf("Error creating thread %d", i);
            free(my_args->filename);
            free(my_args);
            closedir(dir);
            return EXIT_FAILURE;
        }
        // pthread_join(my_threads[i], NULL);
        i++;
        // thread limit reached
        if(i > MAX_THREAD){
            printf("maximum file limit reached\n");
            break;
        }
    }
    int max_thread = i;
    for(int j = 0; j < i; j++){
        pthread_join(my_threads[j], NULL);
    }

    closedir(dir);
    pthread_mutex_destroy(&lock);

    printf("%s", my_result.buff);
    printf("Total Matches = %ld\n", my_result.count);
    printf("Result buffer size = %ld\n", my_result.size);
    printf("Total storage used = %ld\n", my_result.capacity);
    printf("Total threads used = %d\n", max_thread);

    free(my_result.buff);

    return EXIT_SUCCESS;
}

