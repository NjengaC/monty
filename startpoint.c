#define _GNU_SOURCE
#include "monty.h"
#include <stdio.h>
#include <string.h>

track_str monty = {NULL, NULL, 0, 0, NULL, NULL, NULL};
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
 * @argc: args count
 * @argv: args vector
 * Return: 0 (Success)
 */
int main(int argc, char **argv)
{
	FILE *file;
	unsigned int count = 0;
	ssize_t reads = 1;
	size_t index = 0;
	char *store;
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
	while (reads > 0)
	{
		store = NULL;
		reads = getline(&store, &index, file);
		if (store[0] == '\n')
		{
			free(store);
			fclose(file);
			exit (0);
		}
		monty._getline = store;
		count++;
		monty.track = count;
		if (reads > 0)
		{
			_select(store, file, count, &head);
		}
		free(store);
	}
	fclose(file);
	free_stack_t(*(monty.head));
	return (0);
}
