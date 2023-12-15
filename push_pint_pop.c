#include "monty.h"

/**
 * push_st - pushes an element to the stack
 * @new_n: pointer to pointer of of stack top node
 * @num: line number of opcode
 */
void push_st(stack_t **new_n, __attribute__((unused))unsigned int num)
{
	stack_t *temp;

	if (new_n == NULL || *new_n == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (head == NULL)
	{
		head = *new_n;
		return;
	}
	temp = head;
	head = *new_n;
	head->next = temp;
	temp->prev = head;
}
/**
 * print_st - prints all the values on the stack
 * @st: pointer to pointer of of stack top node
 * @num: line number of opcode
 */
void print_st(stack_t **st, unsigned int num)
{
	stack_t *temp;

	(void) num;
	if (st == NULL)
	{
		exit(EXIT_FAILURE);
	}
	temp = *st;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * pint_top - prints the value at the top of the stack
 * @st: pointer to pointer of of stack top node
 * @num: line number of opcode
 */
void pint_top(stack_t **st, unsigned int num)
{
	if (st == NULL || *st == NULL)
	{
		serror(6, num);
	}
	printf("%d\n", (*st)->n);
}
/**
 * pop_first - removes the top element of the stack
 * @st: pointer to pointer of of stack top node
 * @num: line number of opcode
 */
void pop_first(stack_t **st, unsigned int num)
{
	stack_t *temp;

	if (st == NULL || *st == NULL)
	{
		serror(7, num);
	}
	temp = *st;
	*st = temp->next;
	if (*st != NULL)
	{
		(*st)->prev = NULL;
	}
	free(temp);
}
