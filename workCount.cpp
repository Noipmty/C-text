#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILENAME_LENGTH 1000
#define MAX_WORD_LENGTH 100

int count_characters(FILE *file) {
    int count = 0;
    char c;
    
    while ((c = fgetc(file)) != EOF) {
        count++;
    }
    
    return count;
}

int count_words(FILE *file) {
    int count = 0;
    char word[MAX_WORD_LENGTH];
    
    while (fscanf(file, "%s", word) == 1) {
        count++;
    }
    
    return count;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [-c | -w] [input_file_name]\n", argv[0]);
        return 1;
    }
    
    char *option = argv[1];
    char *filename = argv[2];
    
    FILE *file = fopen(filename, "r");
    
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
    int count;
    
    if (strcmp(option, "-c") == 0) {
        count = count_characters(file);
        printf("×Ö·ûÊý: %d\n", count);
    } else if (strcmp(option, "-w") == 0) {
        count = count_words(file);
        printf("µ¥´ÊÊý: %d\n", count);
    } else {
        printf("Invalid option. Please use -c for counting characters or -w for counting words.\n");
        return 1;
    }
    
    fclose(file);
    
    return 0;
}
