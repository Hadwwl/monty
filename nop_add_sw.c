#include "monty.h"
/**
 * swap_n - swaps top two elements of stack
 * @st: pointer to pointer points to top stack node
 * @ln: line number of opcode
 */
void swap_n(stack_t **st, unsigned int ln)
{
	stack_t *temp;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
	{
		serror(8, ln, "swap");
	}
	temp = (*st)->next;
	(*st)->next = temp->next;
	if (temp->next != NULL)
	{
		temp->next->prev = *st;
	}
	temp->next = *st;
	(*st)->prev = temp;
	temp->prev = NULL;
	*st = temp;
}
/**
 * add_n - adds the top two elements of the stack
 * @st: pointer to pointer points to top stack node
 * @ln: line number of opcode
 */
void add_n(stack_t **st, unsigned int ln)
{
	int num_sum;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
	{
		serror(8, ln, "add");
	}
	(*st) = (*st)->next;
	num_sum = (*st)->n + (*st)->prev->n;
	(*st)->n = num_sum;
	free((*st)->prev);
	(*st)->prev = NULL;
}
/**
 * nop_n - doesn’t do anything.
 * @st: pointer to pointer points to top stack node
 * @ln: line number of opcode
 */
void nop_n(stack_t **st, unsigned int ln)
{
	(void)st;
	(void)ln;
}
