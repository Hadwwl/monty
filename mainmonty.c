#include "monty.h"
stack_t *head = NULL;

/**
 * main - main functio
 * @arv: pointer to argument string
 * @arc: count of arguments
 * Return: 0 success
 */
int main(int arc, char *arv[])
{
	if (arc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	openf(arv[1]);
	free_n();
	return (0);
}
