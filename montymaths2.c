#include "monty.h"

/**
 * _sub - subtracts the top element of the stack from the second top element
 * @head: head of the stack
 * @line_number: line number in which the instruction appears.
 *
 * Return: nothing
 */

void _sub(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	int res;

	if (!*head || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(monty.file);
		free(monty._getline);
		free_stack_t(*head);

		exit(EXIT_FAILURE);
	}

	res = (*head)->next->n - (*head)->n;
	(*head)->next->n = res;
	(*head)->prev = NULL;
	*head = (*head)->next;
	free(current);
}
/**
 * _swap - swaps the top two elements of the stack
 * @head: head of the stack
 * @line_number: line number in which the instruction appears.
 *
 * Return: Nothing
 */
void _swap(stack_t **head, unsigned int line_number)
{
	int current;

	if (!*head || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(monty.file);
		free(monty._getline);
		free_stack_t(*head);

		exit(EXIT_FAILURE);
	}
	current = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = current;
}


/**
 * add_dnodeint_end - adds a new node at the end of a DLL
 * @head: head of the stack
 * @n: n member
 * Return: address of new element, or NULL
 */
stack_t *add_dnodeint_end(stack_t **head, int n)
{
	stack_t *new, *temp;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		return (NULL);
	}

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	temp = *head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = new;
	new->prev = temp;

	return (new);
}

/**
 * add_dnodeint - add a new node at the beggining of a DLL
 * @head: head of the stack
 * @n: n member
 * Return: address of the new node
 */
stack_t *add_dnodeint(stack_t **head, int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		return (NULL);
	}

	new->n = n;
	new->next = *head;
	new->prev = NULL;

	if (*head != NULL)
	{
		(*head)->prev = new;
	}

	*head = new;

	return (new);
}

/**
 * _nop - does not  do anything
 * @head: head of the stack
 * @line_number: line number in which the instruction appears.
 * Return: nothing
 */
void _nop(stack_t **head, unsigned int line_number __attribute__((unused)))
{
	(void)head;
}
