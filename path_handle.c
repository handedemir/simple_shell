#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024
#define MAX_COMMAND_LENGTH 128

int main() 
{
	char command[MAX_COMMAND_LENGTH];
	printf("Enter the command: ");
	fgets(command, MAX_COMMAND_LENGTH, stdin);

    /*Remove newline character if present*/
	size_t len = strlen(command);
	if (command[len - 1] == '\n')
	{
		command[len - 1] = '\0';
	}
	char* path = getenv("PATH");
	if (path == NULL)
	{
		printf("PATH environment variable not found\n");
		return 1;
	}
	
	char* token;
	char pathCopy[MAX_PATH_LENGTH];
	strcpy(pathCopy, path);

    /* Tokenize PATH variable*/
    token = strtok(pathCopy, ":");
    
    int commandFound = 0;
    while (token != NULL)
    {
	    char commandPath[MAX_PATH_LENGTH];
	    snprintf(commandPath, sizeof(commandPath), "%s/%s", token, command);
	    
	    /*Check if the command exists*/
	    if (access(commandPath, X_OK) != -1)
	    {
		    commandFound = 1;
            /*Execute the command*/
		    system(commandPath);
		    break;
	    }
	    
	    token = strtok(NULL, ":");
    }
    if (!commandFound)
    {
	    printf("Command '%s' not found in PATH\n", command);
    }
    return 0;
}
