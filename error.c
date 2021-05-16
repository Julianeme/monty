#include "monty.h"
/**
 * push_error -  xxx
 * @stack: double linked list
 * @i: xxxx
 * Return: void
 */

void push_error(stack_t *stack, unsigned int i)
{
	fprintf(stderr, "L%u: usage: push integer\n", i);
	global_free(stack);
}
