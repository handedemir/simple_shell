#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdbool.h>
#define MAX_C 10

int main(void);
int main(int argc __attribute__((unused)),
                char *argv[] __attribute__((unused)), char *env_lp[]);
void print_prompt(int dg, const char *str);
int main(void);
void execute_command(char *input);
char *read_input();
void display_prompt(void);


#endif
