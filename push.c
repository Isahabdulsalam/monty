#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the file where the opcode is located.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	char *token;

	token = strtok(NULL, " \n");

	if (!token || !is_integer(token))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(token);
	new_node->prev = NULL;

	if (*stack)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	else
	{
		new_node->next = NULL;
	}

	*stack = new_node;
}

/**
 * is_integer - Checks if a string represents an integer.
 * @str: String to check.
 * Return: 1 if it's an integer, 0 otherwise.
 */
int is_integer(char *str)
{
	int i = 0;

	if (!str)
		return (0);

	if (str[0] == '-')
		i++;

	for (; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}

	return (1);
}

