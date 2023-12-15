#include "monty.h"

stack_t *head = NULL;
/**
 * cr_node - creates node in stack
 * @n: number that holded inside the node
 * Return: nd or NULL
 */
stack_t *cr_node(int n)
{
	stack_t *nd; /* n = node **/

	nd = malloc(sizeof(stack_t));
	if (nd == NULL)
	{
		fierror(4);
	}
	nd->next = NULL;
	nd->prev = NULL;
	nd->n = n;
	return (nd);
}
/**
 * free_n - free nodes in stack
 */
void free_n(void)
{
	stack_t *temp;

	if (head == NULL)
	{
		return;
	}
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * add_qu - add new node to queue
 * @new_n: pointer to new node
 * @n: opcode number line
 */
void add_qu(stack_t **new_n, __attribute__((unused))unsigned int n)
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
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *new_n;
	(*new_n)->prev = temp;
}
