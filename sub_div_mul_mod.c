#include "monty.h"

/**
 * sub_n - subs top element Of the stack from second top element of stack
 * @st: pointer to pointer to stack top node
 * @ln: line number of opcode number
 */
void sub_n(stack_t **st, unsigned int ln)
{
	int sum_num;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
	{
		serror(8, ln, "sub");
	}
	(*st) = (*st)->next;
	sum_num = (*st)->n - (*st)->prev->n;
	(*st)->n = sum_num;
	free((*st)->prev);
	(*st)->prev = NULL;
}
/**
 * div_n - divides second top element of stack by top element Of stack
 * @st: pointer to pointer to stack top node
 * @ln: line number of opcode number
 */
void div_n(stack_t **st, unsigned int ln)
{
	int sum_num;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
	{
		serror(8, ln, "div");
	}
	if ((*st)->n == 0)
	{
		serror(9, ln);
	}
	(*st) = (*st)->next;
	sum_num = (*st)->n / (*st)->prev->n;
	(*st)->n = sum_num;
	free((*st)->prev);
	(*st)->prev = NULL;
}
/**
 * mul_n -  multiplies second top element of stack with top element Of stack
 * @st: pointer to pointer to stack top node
 * @ln: line number of opcode number
 */
void mul_n(stack_t **st, unsigned int ln)
{
	int sum_num;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
	{
		serror(8, ln, "mul");
	}
	(*st) = (*st)->next;
	sum_num = (*st)->n * (*st)->prev->n;
	(*st)->n = sum_num;
	free((*st)->prev);
	(*st)->prev = NULL;
}
/**
 * mod_n - compute rest of division of snd top element by top element Of stack
 * @st: pointer to pointer to stack top node
 * @ln: line number of opcode number
 */
void mod_n(stack_t **st, unsigned int ln)
{
	int sum_num;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
	{
		serror(8, ln, "mod");
	}
	if ((*st)->n == 0)
	{
		serror(9, ln);
	}
	(*st) = (*st)->next;
	sum_num = (*st)->n % (*st)->prev->n;
	(*st)->n = sum_num;
	free((*st)->prev);
	(*st)->prev = NULL;
}
