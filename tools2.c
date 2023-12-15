#include "monty.h"

/**
 * find_f - searchs for the right function
 * @opc: opcode function
 * @v: value of opcode argument
 * @num: line number of node
 * @formatt: format storage 0 for stack, 1 for queue
 * Return: void
 */
void find_f(char *opc, char *v, int num, int formatt)
{
	int t, flg;

	instruction_t func_list[] = {
		{"push", push_st},
		{"pall", print_st},
		{"pint", pint_top},
		{"pop", pop_first},
		{"nop", nop_n},
		{"swap", swap_n},
		{"add", add_n},
		{NULL, NULL}
	};

	if (opc[0] == '#')
	{
		return;
	}

	for (flg = 1, t = 0 ; func_list[t].opcode != NULL ; t++)
	{
		if (strcmp(opc, func_list[t].opcode) == 0)
		{
			call_f(func_list[t].f, opc, v, num, formatt);
			flg = 0;
		}
	}

	if (flg == 1)
	{
		fierror(3, num, opc);
	}
}
/**
 * call_f - to call functions
 * @fuc: function to be called
 * @opc: opcode string
 * @v: numeric value of string
 * @num: instruction for number
 * @formatt: format storage 0 for stack, 1 for queue
 */
void call_f(op_func fuc, char *opc, char *v, int num, int formatt)
{
	stack_t *n;
	int flg = 1;
	int t;

	if (strcmp(opc, "push") == 0)
	{
		if (v != NULL && v[0] == '-')
		{
			v = v + 1;
			flg = -1;
		}
		if (v == NULL)
		{
			serror(5, num);
		}
		for (t = 0; v[t] != '\0' ; t++)
		{
			if (isdigit(v[t]) == 0)
			serror(5, num);
		}
		n = cr_node(atoi(v) * flg);
		if (formatt == 0)
		{
			fuc(&n, num);
		}
		if (formatt == 1)
		{
			add_qu(&n, num);
		}
	}
	else
		fuc(&head, num);
}
