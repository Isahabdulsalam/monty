#include "monty.h"
#include <stdio.h>

/**
 * pall - Prints all the values on the stack
 * @stack: Double pointer to the head of the stack
 * @value: Value to be used in the instruction
 *
 * Return: void
 */
void pall(stack_t **stack, int value) {
    /* To avoid unused parameter warning */
    (void)value;

    stack_t *current = *stack;

    while (current != NULL) {
        printf("%d\n", current->n);
        current = current->next;
    }
}

