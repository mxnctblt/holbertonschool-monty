#include "monty.h"

/**
 * openfile - open a monty and validate input
 * @argc: args count
 * @filename: path to monty
 */
void openfile(int argc, char *filename)
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty.file = fopen(filename, "r");
	if (!monty.file)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}

/**
 * read_line - reads and executes each line of input from monty file
 */
void read_line(void)
{
	size_t len = 0;
	ssize_t read;
	char *opcode, *data;

	while ((read = getline(&monty.line, &len, monty.file) != -1))
	{
		opcode = strtok(monty.line, " ");
		if (*opcode == '\n')
		{
			monty.line_number++;
			continue;
		}
		else if (strcmp(opcode, "push") == 0)
		{
			data = strtok(NULL, " \n");
				push(data);
		}
		else
			op_choose(&monty.stack, opcode);
		monty.line_number++;
	}
}

/**
 * op_choose - find & call the function that corresponds with the opcode
 * @stack: **pointer to stack
 * @opcode: opcode from this line of our monty file
 */
void op_choose(stack_t **stack, char *opcode)
{
	int i;
	char *op;
	instruction_t functions[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{NULL, NULL}
	};

	op = strtok(opcode, "\n");
	for (i = 0; functions[i].opcode; i++)
	{
		if (strcmp(op, functions[i].opcode) == 0)
		{
			functions[i].f(stack, monty.line_number);
			return;
		}
	}
	if (strcmp(opcode, "push"))
	{
		dprintf(STDERR_FILENO, "L%u: ", monty.line_number);
		dprintf(STDERR_FILENO, "unknown instruction %s\n", opcode);
	}
	else
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", monty.line_number);
	exit(EXIT_FAILURE);
}
