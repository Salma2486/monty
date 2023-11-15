#include "monty.h"
/**
 * main - main function here
 * @argc: the number of argument
 * @argv: the argument
 * Return: 0
 */
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	execute_instructions(file);
	free_stack(&stack);
	fclose(file);
	return (0);
}
