#include "monty.h"

/**
 * push - adds a node at the beggining of a linked list
 * @head: a double pointer to the stack of the linked list
 * @line_number: file line number where the op was requested
 * Return: nothing if succes, EXIT_FAILURE if it fails
 */

void push(stack_t **head, unsigned int line_number)
{
	stack_t *new_node, *temp;

	(void)line_number;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		exit(EXIT_FAILURE);
	}
	new_node->n = value, new_node->prev = NULL, new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
	}
	else
		temp = *head, new_node->next = *head,
		temp->prev = new_node, *head = new_node;
}
/**
 * pall -  prints all the elements of a doubly linked list.
 * @stack: a pointer to the stack of the list
 * @line_number: file line number where the op was requested
 * Return: Nothing
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;
	while (temp)
	{
		printf("%i\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint -  prints all the elements of a doubly linked list.
 * @stack: a pointer to the stack of the list
 * @line_number: file line number where the op was requested
 * Return: Nothing
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp)
	{
		printf("%i\n", temp->n);
	}
	else
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
