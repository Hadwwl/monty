#include "monty.h"

/**
 * fierror - error handeler
 * @err_code: 1, 2, 3, 4
 */
void fierror(int err_code, ...)
{
	va_list ag;
	char *s;
	int num;

	va_start(ag, err_code);

	switch (err_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", va_arg(ag, char *));
			break;
		case 3:
			num = va_arg(ag, int);
			s = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", num, s);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		default:
			break;
	}
	free_n();
	exit(EXIT_FAILURE);
}

/**
 * serror - second error handeler
 * @err_code: 5, 6, 7, 8, 9
 */
void serror(int err_code, ...)
{
	va_list ag;
	char *s;
	int num;

	va_start(ag, err_code);

	switch (err_code)
	{
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(ag, int));
			break;
		case 8:
			num = va_arg(ag, unsigned int);
			s = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", num, s);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n", va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_n();
	exit(EXIT_FAILURE);
}
