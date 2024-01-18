#include "monty.h"
#include <string.h>
#include <stdio.h>

/**
 * execute_instruction - Executes a Monty instruction
 * @stack: Double pointer to the head of the stack
 * @instruction: Monty instruction to be executed
 * @value: Value to be used in the instruction
 *
 * Return: void
 */
void execute_instruction(stack_t **stack, char *instruction, int value) {
    instruction_t instructions[] = {
        {"push", &push},
        {"pall", &pall},
        {NULL, NULL}
    };

    int i = 0;

    while (instructions[i].opcode != NULL) {
        if (strcmp(instruction, instructions[i].opcode) == 0) {
            instructions[i].f(stack, value);
            return;
        }
        i++;
    }

    fprintf(stderr, "L%d: unknown instruction %s\n", value, instruction);
    exit(EXIT_FAILURE);
}

