#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_INPUT 1024

int main() {
    char *args[MAX_ARGS + 1]; // Additional space for the NULL terminator
    char input[MAX_INPUT];
    size_t len = MAX_INPUT;
    ssize_t read;

    // Read the command line input
    write(STDOUT_FILENO, "Enter command: ", 15);
    read = getline(&input, &len, stdin);
    if (read == -1) {
        perror("Error reading input");
        exit(EXIT_FAILURE);
    }

    // Tokenize the input into arguments
    int argc = 0;
    char *token = strtok(input, " \n");
    while (token != NULL && argc < MAX_ARGS) {
        args[argc++] = token;
        token = strtok(NULL, " \n");
    }
    args[argc] = NULL; // Set the last element to NULL for execve

    // Execute the command
    if (argc > 0) {
        if (execve(args[0], args, NULL) == -1) {
            perror("Execution error");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
