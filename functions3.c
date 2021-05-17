#include "monty.h"

/**
 * mod - omputes the rest of the division of the second top
 * element of the stack by the top element of the stack
 * @head: a double pointer to the stack of the linked list
 * @line_number: file line number where the op was requested
 * Return: nothing if succes, EXIT_FAILURE if it fails
 */

void mod(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;

	if (!*head || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		global_free(*head);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		global_free(*head);
	}
	(*head)->next->n %= (*head)->n;
	if (temp->next)
	{
		*head = temp->next;
		temp->next->prev = NULL;
	}
	else
	{
		*head = NULL;
	}
	free(temp);
}

/**
 * pchar - prints the char at the top of the stack, followed by a new line..
 * @stack: a pointer to the stack of the list
 * @line_number: file line number where the op was requested
 * Return: Nothing
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp && temp->n >=0 && temp->n <128)
	{
		printf("%c\n", temp->n);
	}
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		global_free(*stack);
	}
}