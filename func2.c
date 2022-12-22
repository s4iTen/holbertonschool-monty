#include "monty.h"
/**
 * swap - swap the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number in the file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *top = *stack;
	stack_t *second = top->next;

	top->prev = second;
	top->next = second->next;
	if (second->next)
		second->next->prev = top;
	second->prev = NULL;
	second->next = top;
	*stack = second;
}

/**
 * free_stack - free the memory used by the stack
 * @stack: pointer to the top of the stack
 */
void free_stack(stack_t *stack)
{
	stack_t *current, *next;

	current = stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the instruction in the input file
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	node = *stack;
	sum = node->n + node->next->n;

	*stack = (*stack)->next;
	free(node);
	(*stack)->n = sum;
}
/**
 * nop - does nothing
 * @stack: pointer to the top of the stack (unused)
 * @line_number: line number of the instruction in the input file (unused)
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
