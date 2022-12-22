#include "monty.h"
/**
 * execute - executes the instruction specified by the opcode
 * @stack: pointer to the top of the stack
 * @opcode: the instruction to execute
 * @line_number: the line number in the input file where the instruction
 * Return: 0 on success, -1 on failure
 */
int execute(stack_t **stack, char *opcode, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}};
	int i;

	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return (0);
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	return (-1);
}
