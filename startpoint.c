#define _GNU_SOURCE
#include "monty.h"
#include <stdio.h>
#include <string.h>

track_str monty = {NULL, NULL, 0, 0, NULL, NULL, NULL};
/**
 * whitespace - checks for white spaces
 * @command: command input
 * Return: 0 is command consist of whitespaces
 */
int whitespace(char *command)
{
	int i;
	int count = 0;
	int len;


	len = strlen(command);
	for (i = 0; i < len; i++)
	{
		if (command[i] == ' ' || command[i] == '\t' || command[i] == '\n')
			count++;
		else
			return (0);
	}
	return (1);
}


/**
 * set_state - sets the queue or stack status
 * @commands: command line from file
 * Return: 0
 */
void set_state(char *commands)
{
	if (strcmp(commands, "stack") == 0)
		monty.state = 0;
	else
		monty.state = 1;
}
/**
 * main - main entry point
 * @argc: args count.
 * @argv: args vector.
 * Return: 0 (Success)
 */
int main(int argc, char **argv);
int main(int argc, char **argv)
{
	FILE *file;
	unsigned int count = 0;
	ssize_t reads;
	size_t index = 0;
	char *store = NULL;
	stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	monty.file = file;
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((reads = getline(&store, &index, file)) != -1)
	{
		if (*store == '\n' || (whitespace(store)) == 1)
		{
			continue;
		}
		monty._getline = store;
		count++;
		monty.track = count;
		if (reads)
		{
			_select(store, file, count, &head);
		}
	}
	if (store != NULL)
		free(store);
	fclose(file);
	if (monty.head != NULL)
		free_stack_t(*(monty.head));
	return (0);
}
