#include "monty.h"
/**
 * main - this is the main function
 * @argc: this is the argument counter
 * @argv:this is the argument variable
 * Return: return EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	int ret = read_and_parse_input(argv[1]);

	if (ret < 0)
		return (EXIT_FAILURE);

	return (EXIT_SUCCESS);
}
