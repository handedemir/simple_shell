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



#endif
