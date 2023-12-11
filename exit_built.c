#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

int main() {
    char *input = NULL;
    size_t len = 0;
    ssize_t read;

    while (1) {
        write(STDOUT_FILENO, "$ ", 2); // Display prompt
        read = getline(&input, &len, stdin); // Read input

        if (read == -1) {
            perror("getline");
            exit(EXIT_FAILURE);
        }

        input[strcspn(input, "\n")] = '\0'; // Remove newline character

        if (strcmp(input, "exit") == 0) {
            write(STDOUT_FILENO, "Exiting shell...\n", 17);
            free(input);
            exit(EXIT_SUCCESS);
        }

        // If the command is not exit, you can add other functionalities or commands here
        write(STDOUT_FILENO, "Command not found. Try 'exit' to quit the shell.\n", 50);
    }

    return 0;
}
