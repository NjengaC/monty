#include "monty.h"

/**
 * _add - adds the top 2 elements
 * @head: head of the stack
 * @line_number: line number where the instruction appears
 *
 * Return: Nothing
 */

void _add(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	int sum;

	if (!*head || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(monty.file);
		free(monty._getline);
		free_stack_t(*head);
		exit(EXIT_FAILURE);
	}

	sum = (*head)->n + (*head)->next->n;
	(*head)->next->n = sum;
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(current);
}

/**
 * _div - divides the second top element of the stack by the top elemen
 * *@head: head of the stack
 * @line_number: line number where the instruction appears
 * Return: Nothing
 */

void _div(stack_t **head, unsigned int line_number)
{
	int total = 0;
	int i = 0;
	stack_t *current = *head;

	while (current)
	{
		current = current->next;
		i++;
	}

	if (i < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		fclose(monty.file);
		free(monty._getline);
		free_stack_t(*head);
		exit(EXIT_FAILURE);
	}

	current = *head;
	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(monty.file);
		free(monty._getline);
		free_stack_t(*head);
		exit(EXIT_FAILURE);
	}

	total = current->next->n / current->n;
	current->next->n = total;
	*head = current->next;
	(*head)->prev = NULL;
	free(current);
}

/**
 * _mod - computes the rest of the division of the second top element 
 * of the stack by the top element
 * @head: stacks head
 * @line_number: line number where the instruction appears
 *
 * Return: Nothing
 */
void _mod(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	int result;

	if (!*head || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		fclose(monty.file);
		free(monty._getline);
		free_stack_t(*head);
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(monty.file);
		free(monty._getline);
		free_stack_t(*head);
		exit(EXIT_FAILURE);
	}

	result = (*head)->next->n % (*head)->n;
	(*head)->next->n = result;
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(current);
}
/**
 * _mul -  multiplies the second top element of the stack with the top element
 * @head: head of the stack.
 * @line_number: line number where the instruction appears
 *
 * Return: Nothing
 */

void _mul(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	int res;

	if (!*head || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(monty.file);
		free(monty._getline);
		free_stack_t(*head);
		exit(EXIT_FAILURE);
	}
	res = current->next->n * current->n;
	current->next->n = res;
	*head = current->next;
	free(current);
}
/**
 * _pchar - prints the char at the top of the stack
 * @head: stacks head
 * @line_number:line number where the instruction appears
 *
 * Return: Nothing
 */

void _pchar(stack_t **head, unsigned int line_number)
{
	if (!*head)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(monty.file);
		free(monty._getline);
		free_stack_t(*head);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n < 0 || (*head)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(monty.file);
		free(monty._getline);
		free_stack_t(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}
