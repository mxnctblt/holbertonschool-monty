#include "monty.h"

monty_t monty;

/**
 * main - entry point
 * @argc: args count
 * @argv: args vector
 *
 * Return: EXIT_SUCCESS
 */
int main(int argc, char **argv)
{

	initialize();
	openfile(argc, argv[1]);
	read_line();
	freeall();
	return (EXIT_SUCCESS);
}

/**
 *  initialize - initialize the struct
 */
void initialize(void)
{

	monty.file = NULL;
	monty.line = NULL;
	monty.stack = NULL;
	monty.line_number = 1;
}

/**
 * freeall - frees our file
 */
void freeall(void)
{
	fclose(monty.file);
	free(monty.line);
	freestack(monty.stack);
}

/**
 * freestack - frees the stack
 * @h: the head of stack
 */
void freestack(stack_t *h)
{
	stack_t *temp;
	stack_t *loc = h;

	while (loc)
	{
		temp = loc;
		loc = loc->next;
		free(temp);
	}
}
