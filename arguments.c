#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ARGS 10
#define MAX_INPUT 1024

int main() {
    char input[MAX_INPUT];
    size_t len = MAX_INPUT;
    ssize_t bytes_read; // Renamed 'read' to 'bytes_read'

    // Read the command line input
    write(STDOUT_FILENO, "Enter command: ", 15);
    bytes_read = read(STDIN_FILENO, input, MAX_INPUT);
    if (bytes_read == -1) {
        perror("Error reading input");
        exit(EXIT_FAILURE);
    }
    input[bytes_read - 1] = '\0'; // Removing newline character

    // Tokenize the input into arguments
    int argc = 0;
    char *args[MAX_ARGS + 1]; // Additional space for the NULL terminator
    char *token = strtok(input, " ");
    while (token != NULL && argc < MAX_ARGS) {
        args[argc++] = token;
        token = strtok(NULL, " ");
    }
    args[argc] = NULL; // Set the last element to NULL for execve

    // Execute the command
    if (argc > 0) {
        if (execvp(args[0], args) == -1) {
            perror("Execution error");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
