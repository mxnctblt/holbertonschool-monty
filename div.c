#include "monty.h"

/**
 * divising - divs top two stack mems
 * @stack: double list
 * @linenumber: line
 */
void divising(stack_t **stack, __attribute__((unused))unsigned int linenumber)
{
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n"
			, monty.line_number);
		freeall();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n"
			, monty.line_number);
		freeall();
		exit(EXIT_FAILURE);
	}
	if (*stack && (*stack)->next)
	{
		(*stack)->next->n /= (*stack)->n;
		temp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);
	}
}
