#include "monty.h"

/**
 * pall - Prints all values on the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the file where the opcode is located.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	if (!stack || !(*stack))
		return;

	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
