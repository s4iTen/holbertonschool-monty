#include "monty.h"
/**
 * read_and_parse_input - func that read and parse the input
 * @filename: this is the file name
 * Return: always 0 or -1
 */
int read_and_parse_input(const char *filename)
{
	stack_t *stack = NULL;
	char *opcode;
	unsigned int line_number = 0;
	int ret;
	FILE *fp;
	char *line = NULL;
	size_t len = 0;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		return (-1);
	}
	while (getline(&line, &len, fp) != -1)
	{
		line_number++;
		opcode = strtok(line, " \n");
		if (opcode == NULL || opcode[0] == '#')
			continue;
		ret = execute(&stack, opcode, line_number);
		if (ret < 0)
		{
			free_stack(stack);
			return (-1);
		}
	}
	free(line);
	fclose(fp);
	free_stack(stack);
	return (0);
}
