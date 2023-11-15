#include "monty.h"
#include <string.h>

/**
 * _select - selects functions appropriately
 * @command: command line
 * @file: the input file
 * @count: count tracker
 * @head: list head
 *
 * Return: nothing
 */
int _select(char *command, FILE *file, unsigned int count, stack_t **head);
int _select(char *command, FILE *file, unsigned int count, stack_t **head)
{
	char *commands;
	int i = 0;
	instruction_t choice[] = {
		{"push", _push}, {"pall", _pall}, {"pint", _pint}, {"pop", _pop},
		{"swap", _swap}, {"add", _add}, {"nop", _nop}, {"div", _div},
		{"sub", _sub}, {"mul", _mul}, {"mod", _mod}, {"pchar", _pchar},
		{"pstr", _pstr}, {"rotr", _rotr}, {"rotl", _rotl}, {NULL, NULL}
	};

	commands = strtok(command, " \n\t");
	if (strcmp(commands, "stack") == 0 || strcmp(commands, "queue") == 0)
	{
		set_state(commands);
		return (0);
	}
	i = 0, monty.head = head, monty.first = commands;
	monty.second = strtok(NULL, " \n\t");
	while (choice[i].opcode && commands)
	{
		if (commands[0] == '#')
		{
			choice[6].f(head, count);
			return (0);
		}
		if (strcmp(commands, choice[i].opcode) == 0)
		{
			choice[i].f(head, count);
			return (0);
		}
		i++;
	}
	if (commands && choice[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, commands);
		fclose(file);
		free(command);
		free_stack_t(*head);

		exit(EXIT_FAILURE);
	}
	return (0);
}

/**
 * handle_hash - comments
 * @buffer: input
 *
 * Return: new output
 */
char *handle_hash(char *buffer)
{
	int i = 0;

	while (buffer[i] != ' ' && buffer[i] != '\t')
	{
		i++;
	}
	if (buffer[i] == '#')
	{
		return (NULL);
	}

	return (buffer);
}

/**
 *free_stack_t - frees the stack
 *@head: head of the linked list
 *Return: nothing
 */
void free_stack_t(stack_t *head)
{
	stack_t *current;

	if (!head)
	{
		return;
	}

	while (head)
	{
		current = head;
		head = head->next;
		free(current);
	}
}
/**
 * _push - pushes an integer on top of a stack
 * @head: head of the stack
 * @line_number: line_numberition to push at
 *
 * Return: Nothing
 */
void _push(stack_t **head, unsigned int line_number);
void _push(stack_t **head, unsigned int line_number)
{
	int n, j = 0, status = 0;

	if (monty.second)
	{
		if (monty.second[0] == '-')
			j++;
		for (; monty.second[j] != '\0'; j++)
		{
			if (monty.second[j] > 57 || monty.second[j] < 48)
				status = 1;
		}
		if (status == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(monty.file), free(monty._getline);
			free_stack_t(*head), exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(monty.file), free(monty._getline), free_stack_t(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(monty.second);
	if (monty.state == 0)
	{
		if (add_dnodeint(head, n) == NULL)
		{
			fprintf(stderr, "Error: malloc failed");
			fclose(monty.file), free(monty._getline);
			free_stack_t(*head), exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (add_dnodeint_end(head, n) == NULL)
		{
			fprintf(stderr, "Error: malloc failed");
			fclose(monty.file), free(monty._getline);
			free_stack_t(*head), exit(EXIT_FAILURE);
		}
	}
}
/**
 * _pall - prints all the values on the stack
 * @head: head of the stack
 * @line_number: line_number where the instruction appear
 *
 * Return: Nothing
 */
void _pall(stack_t **head, unsigned int line_number __attribute__((unused)))
{
	stack_t *current = *head;

	if (current == NULL)
	{
		return;
	}
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}

}
