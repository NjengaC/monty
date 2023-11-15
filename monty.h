#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct track_str - structure to track runtime execution
 * @first: the first tokenized word
 * @second: the second tokenized word
 * @state: queue/stack?
 * @track: line track
 * @head: the head of the linked list
 * @file: sourcefile
 * @_getline: line from the file
 *
 * Description: short description, Structure
 */
typedef struct track_str
{
	char *first;
	char *second;
	int state;
	int track;
	stack_t **head;
	FILE *file;
	char *_getline;
} track_str;

extern track_str monty;

int _select(char *command, FILE *file, unsigned int count, stack_t **head);
int execute(stack_t **head, unsigned int count);
void free_stack_t(stack_t *head);
stack_t *add_dnodeint(stack_t **head, int n);
stack_t *add_dnodeint_end(stack_t **head, int n);
void _pall(stack_t **head, unsigned int line_number __attribute__((unused)));
void _push(stack_t **head, unsigned int line_number);
void set_state(char *commands);
void _pint(stack_t **head, unsigned int line_number);
void _pop(stack_t **head, unsigned int line_number);
void _swap(stack_t **head, unsigned int line_number);
void _add(stack_t **head, unsigned int line_number);
void _nop(stack_t **head, unsigned int line_number __attribute__((unused)));
void _sub(stack_t **head, unsigned int line_number);
void _mul(stack_t **head, unsigned int line_number);
void _mod(stack_t **head, unsigned int line_number);
void _pchar(stack_t **head, unsigned int line_number);
void _pstr(stack_t **head, unsigned int line_number __attribute__((unused)));
void _rotl(stack_t **head, unsigned int line_number __attribute__((unused)));
void _rotr(stack_t **head, unsigned int line_number __attribute__((unused)));
void _div(stack_t **head, unsigned int line_number);
char *handle_hash(char *buffer);


#endif
