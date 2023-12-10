#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

void exit_shell() {
    exit(0);
}

int main() {
    char input[MAX_INPUT_LENGTH];

    while (1) {
        printf("Enter a command: ");
        fgets(input, sizeof(input), stdin);
        
        // Remove newline character if present
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0) {
            exit_shell();
        } else {
            printf("Command not recognized: %s\n", input);
        }
    }

    return 0;
}
