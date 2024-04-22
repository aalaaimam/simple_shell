#include <stdio.h>
#include <stddef.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1024

/**
* main - Entry point for the simple shell program
*
* Description: This function is the entry point for the shell program.
*              It displays a prompt, reads user input, and executes commands.
*
* Return: Always returns 0 on success.
*/

int main(void)
{
char command[MAX_COMMAND_LENGTH];

while (1)
{
printf("#cisfun$ ");

if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
{
perror("fgets");
return (1); /* Exit if Ctrl+D (EOF) is pressed */
}

/* Remove newline character if present */
if ((strlen(command) > 0) && (command[strlen(command) - 1] == '\n'))
{
command[strlen(command) - 1] = '\0';
}

/* Your code to process the command goes here */

}

return (0);
}
