#include "monty.h"

/**
 * push - adds a node at the beggining of a linked list
 * @stack: a double pointer to the stack of the linked list
 * @line_number: file line number where the op was requested
 * Return: nothing if succes, EXIT_FAILURE if it fails
 */

void push(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *new = NULL, *temp = *stack;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		perror("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new->n = value;
	if (*stack == NULL)
	{
		new->prev = NULL;
		new->next = *stack;
		*stack = new;
	}
	else
	{
		new->prev = NULL;
		new->next = *stack;
		temp->prev = new;
		*stack = new;
	}
}
/**
 * pall -  prints all the elements of a doubly linked list.
 * @stack: a pointer to the stack of the list
 * @line_number: file line number where the op was requested
 * Return: Nothing
 */

void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	while (stack)
	{
		printf("%i\n", (*stack)->n);
		*stack = (*stack)->next;
	}
}