#include "monty.h"

/**
 * push - add node to list
 * @argument: int
 */
void push(char *argument)
{
	int data;
	stack_t *new;

	if (!check_input(argument))
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n"
			, monty.line_number);
		freeall();
		exit(EXIT_FAILURE);
	}

	data = atoi(argument);
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		freeall();
		exit(EXIT_FAILURE);
	}
	new->n = data;
	new->next = monty.stack;
	new->prev = NULL;
	if (new->next)
		new->next->prev = new;
	monty.stack = new;
}

/**
 * check_input - check if int
 * @str: the string we check
 *
 * Return: false unless int
 */
bool check_input(char *str)
{
	int i = 0;

	if (!str)
	{
		return (false);
	}
	if (str[0] != '-' && !isdigit(str[0]))
	{
		return (false);
	}
	for (i = 1; str[i]; i++)
	{
		if (!isdigit(str[i]))
		{
			return (false);
		}
	}
	return (true);
}
