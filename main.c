#include "monty.h"
#include <stdlib.h>

stack_t *stack = NULL;

int main(int argc, char *argv[]) {
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1) {
        int value = 0;
        execute_instruction(&stack, value);
    }

    free(line);
    fclose(file);
    return 0;
}

