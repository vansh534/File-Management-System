#include "header.h"
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main() {
    int users[ ] = {1505,1522,1552};
    int size= sizeof(users)/sizeof(int);
    
    int user_id;
    printf("Enter your UserId: ");
    scanf("%d",&user_id);
    bool allowed=false;
    for(int i=0;i<size;i++){
        if((users[i]^user_id) == 0){
            allowed=true;
        }
    }
    
    char filename[100], content[100];
    int choice;
    clock_t start_time, end_time;
    double cpu_time_used;
    struct rusage usage_start;
    getrusage(RUSAGE_SELF, &usage_start);
 
    start_time= clock();

    while (1) {
        printf("\nFile Management System\n");
        printf("1. Create File\n");
        printf("2. Read File\n");
        printf("3. Update File\n");
        printf("4. Delete File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if(allowed){
                    printf("Enter filename: ");
                    scanf("%s", filename);
                    createFile(filename);
                    break;
                }
                else{
                    printf("You cannot create a file, you only have permission to read.\n");
                    break;
                }
            case 2:
                    printf("Enter filename: ");
                    scanf("%s", filename);
                    readFile(filename);
                    break;
            case 3:
                if(allowed){
                    printf("Enter filename: ");
                    scanf("%s", filename);
                    printf("Enter content: ");
                    getchar();  // Clear newline character from buffer
                    fgets(content, sizeof(content), stdin);
                    updateFile(filename, content);
                    break;
                }
                else{
                    printf("You cannot update a file, you only have permission to read.\n");
                    break;
                }
                
            case 4:
                if(allowed){
                    printf("Enter filename: ");
                    scanf("%s", filename);
                    deleteFile(filename);
                    break;
                }
                else{
                    printf("You cannot delete a file, you only have permission to read.\n");
                    break;
                }
                
            case 5:
                end_time = clock();
                cpu_time_used = ((double)(end_time-start_time))/CLOCKS_PER_SEC;
                struct rusage usage_end;
                getrusage(RUSAGE_SELF, &usage_end);

                long memory_used= usage_end.ru_maxrss - usage_start.ru_maxrss;
                printf("CPU Time Used: %f seconds\n", cpu_time_used);
                printf("CPU Memory Consumption: %ld KB\n",(memory_used/1024));
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

