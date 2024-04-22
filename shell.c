i#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

int main(void) {
char command[MAX_COMMAND_LENGTH];
pid_t pid;
int status;

while (1) {
printf("#cisfun$ ");
if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL) {
printf("\n");
break; // Exit if Ctrl+D (EOF) is pressed
}

// Replace '\n' with '\0' to remove the newline character
if ((strlen(command) > 0) && (command[strlen(command) - 1] == '\n')) {
command[strlen(command) - 1] = '\0';
}

pid = fork();
if (pid < 0) {
perror("fork");
exit(EXIT_FAILURE);
} else if (pid == 0) { // Child process
if (execlp(command, command, NULL) == -1) {
perror("execlp");
exit(EXIT_FAILURE);
}
} else { // Parent process
wait(&status);
}
}

return EXIT_SUCCESS;
}
