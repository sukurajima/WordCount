#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int countCharacters(const char *filePath) {
    FILE *file = fopen(filePath, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    int count = 0;
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        count++;
    }
    fclose(file);
    return count;
}
int countWords(const char *filePath) {
    FILE *file = fopen(filePath, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }
    int inWord = 0; // Flag to indicate if we are inside a word
    int count = 0;
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        if (isspace(ch)) {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            count++;
        }
    }
    fclose(file);
    return count;
}
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s [-c|-w] <input_file_name>\n", argv[0]);
        return 1;
    }

    const char *param = argv[1];
    const char *filePath = argv[2];

    if (strcmp(param, "-c") == 0) {
        printf("Characters: %d\n", countCharacters(filePath));
    } else if (strcmp(param, "-w") == 0) {
        printf("Words: %d\n", countWords(filePath));
    } else {
        fprintf(stderr, "Invalid parameter. Use '-c' for character count or '-w' for word count.\n");
        return 1;
    }

    return 0;
}
