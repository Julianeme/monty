#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * global_struct - Global Variable to sotre node value, fd and
 * double pointer array with monty commands
 * @value: value to be stored in the node
 * @fd: File descriptor of the monty file
 * @cmds: double pointer array with the monty commands
 */

typedef struct global_struct
{
	int value;
	FILE *fd;
	char **command;
	char *line_buf;
} global_v;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

global_v global;

void get_op(char *s, stack_t **stack, unsigned int line_number);
char **lines_tokenizer(char *string);
char **words_tokenizer(char *string);
char *_strdup(char *str);
void push_error(stack_t *stack, unsigned int i);
int value_check(stack_t *stack, char *val, unsigned int line_number);
void double_ptr_free(char **array);
void free_grid(char **grid);
void free_stack(stack_t *stack);
void push(stack_t **head, unsigned int num_lines);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
int count_words(char *string);
void swap(stack_t **head, unsigned int line_number);
void global_free(stack_t *stack);
void camilo_patino(stack_t *stack);
int batman(char *line_buf);
void add(stack_t **head, unsigned int line_number);
void nop(stack_t **head, unsigned int line_number);
void sub(stack_t **head, unsigned int line_number);
void div(stack_t **head, unsigned int line_number);
void argc_checker(int argc);

#endif
