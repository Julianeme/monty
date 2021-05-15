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
		fprintf(stderr, "Error: malloc failed");
		if (*head)
			free_stack(*head);
		exit(EXIT_FAILURE);
	}
	new_node->n = global.value, new_node->prev = NULL, new_node->next = NULL;
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
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pop - removes the top element of the stack
 * in a doubly linked list
 * @stack: a double pointer to the stack of the linked list
 * @line_number: file line number where the op was requested
 * Return: the address of the new element, or NULL if it failed
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (temp->next)
	{
		*stack = temp->next;
		temp->next->prev = NULL;
	}
	else
	{
		*stack = NULL;
	}
	free(temp);
}

/**
 * swap - swap the two top elements of the stack
 * @head: a double pointer to the stack of the linked list
 * @line_number: file line number where the op was requested
 * Return: nothing if succes, EXIT_FAILURE if it fails
 */

void swap(stack_t **head, unsigned int line_number)
{
	int aux = 0;
	stack_t *temp = *head;

	if (!temp->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	aux = temp->n;
	temp->n = temp->next->n;
	temp->next->n = aux;
}
