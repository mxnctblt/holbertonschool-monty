#ifndef __MONTY__H
#define __MONTY__H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <errno.h>
#include <stdbool.h>


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

/**
 * struct monty_s - global struct to hold all the things
 * @file: monty file
 * @line: line we are interpreting
 * @stack: the stack
 * @line_number: current line number read
 */
typedef struct monty_s
{
	FILE *file;
	char *line;
	stack_t *stack;
	unsigned int line_number;
} monty_t;

extern monty_t monty;

void openfile(int argc, char *filename);
void read_line(void);
void op_choose(stack_t **stack, char *opcode);
void initialize(void);
void freeall(void);
void freestack(stack_t *h);
bool check_input(char *str);

void push(char *argument);

void pall(stack_t **stack, unsigned int linenumber);

void pint(stack_t **stack, unsigned int linenumber);

void pop(stack_t **stack, unsigned int linenumber);

void swap(stack_t **stack, __attribute__((unused))unsigned int linenumber);

void add(stack_t **stack, unsigned int linenumber);

void nop(stack_t **stack, __attribute__((unused))unsigned int linenumber);

void sub(stack_t **stack, unsigned int linenumber);

void divising(stack_t **stack, unsigned int linenumber);

void mul(stack_t **stack, unsigned int linenumber);

void mod(stack_t **stack, unsigned int linenumber);

#endif
