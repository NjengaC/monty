#include "monty.h"

/**
 * _pint - prints the value at the top of the stack
 * @head: stacks head
 * @line_number:  line number where the instruction appears.
 * Return: Nothing
 */

void _pint(stack_t **head, unsigned int line_number)
{
	if (!*head)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(monty.file);
		free(monty._getline);
		free_stack_t(*head);

		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * _pop - removes the top element from the stack
 * @head: stack head
 * @line_number:  line number where the instruction appears.
 * Return: Nothing
 */
void _pop(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;

	if (!*head)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(monty.file);
		free(monty._getline);
		free_stack_t(*head);

		exit(EXIT_FAILURE);
	}

	*head = (*head)->next;

	if (*head != NULL)
		(*head)->prev = NULL;

	free(current);
}
/**
 * _pstr - prints the string starting at the top of the stack
 * @head: head of stack
 * @line_number:  line number where the instruction appears.
 * Return: Nothing
 */
void _pstr(stack_t **head, unsigned int line_number __attribute__((unused)))
{
	stack_t *current = *head;

	if (!*head)
	{
		printf("\n");
		fclose(monty.file);
		free(monty._getline);
		free_stack_t(*head);
	}
	while (current)
	{
		if (current->n <= 0 || current->n > 127)
			break;
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}
/**
 * _rotl - rotates the stack to the top.
 * @head: head of the stack.
 * @line_number:  line number where the instruction appears.
 * Return: Nothing.
 */
void _rotl(stack_t **head, unsigned int line_number __attribute__((unused)))
{
	stack_t *first, *last;

	if (!head || !(*head)->next || (*head)->next == NULL)
		return;
	first = *head;
	last = *head;

	while (last->next != NULL)
	{
		last = last->next;
	}
	*head = first->next;
	first->next->prev = NULL;

	last->next = first;
	first->prev = last;

	first->next = NULL;
}
/**
 * _rotr - rotates the stack to the bottom.
 * @head: stack's head..
 * @line_number:  line number where the instruction appears.
 * Return: Nothing.
 */

void _rotr(stack_t **head, unsigned int line_number __attribute__((unused)))
{
	stack_t *next, *current, *prev;

	current = *head;
	prev = NULL;


	if (*head && (*head)->next != NULL)
	{
		while (current)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		*head = prev;
	}
}
