#include "monty.h"

/**
 * openf - open file
 * @file_n: namepaTh of file
 */
void openf(char *file_n)
{
	FILE *fd = fopen(file_n, "r");

	if (file_n == NULL || fd == NULL)
	{
		fierror(2, file_n);
	}
	read_f(fd);
	fclose(fd);
}
/**
 * read_f - read file
 * @fd: pointer to the file descriptor
 */
void read_f(FILE *fd)
{
	int ln, formatt = 0;
	size_t l = 0;
	char *buff = NULL;

	for (ln = 1 ; getline(&buff, &l, fd) != -1 ; ln++)
	{
		formatt = parse_l(buff, ln, formatt);
	}
	free(buff);
}
/**
 * parse_l - separates lines to tokens
 * @buff: line
 * @ln: line number
 * @formatt: storage format 0 for stack, 1 for queue
 * Return: 1 for queue and 0 for stack
 */
int parse_l(char *buff, int ln, int formatt)
{
	char *opc, *v;
	const char *deli = "\n ";

	if (buff == NULL)
	{
		fierror(4);
	}
	
	opc = strtok(buff, deli);
	if (opc == NULL)
	{
		return (formatt);
	}
	
	v = strtok(NULL, deli);
	if (strcmp(opc, "stack") == 0)
	{
		return (0);
	}
	if (strcmp(opc, "queue") == 0)
	{
		return (1);
	}
	find_f(opc, v, ln, formatt);
	return (formatt);
}
