#include <stdio.h>


void createFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error creating file.\n");
        return;
    }
    printf("File '%s' created successfully.\n", filename);
    fclose(file);
}

void readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    
    fclose(file);
}

void updateFile(const char *filename, const char *content) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    
    fprintf(file, "%s\n", content);
    printf("Content added to '%s'.\n", filename);
    
    fclose(file);
}

void deleteFile(const char *filename) {
    if (remove(filename) == 0) {
        printf("File '%s' deleted successfully.\n", filename);
    } else {
        printf("Error deleting file.\n");
    }
}

