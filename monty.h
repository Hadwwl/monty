#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void(*op_func)(stack_t **, unsigned int);

void push_st(stack_t **new_n, __attribute__((unused))unsigned int num);
void print_st(stack_t **st, unsigned int num);
void pint_top(stack_t **st, unsigned int num);
void pop_first(stack_t **st, unsigned int num);


stack_t *cr_node(int i);
void free_n(void);
void add_qu(stack_t **new_n, __attribute__((unused))unsigned int n);


void nop_n(stack_t **st, unsigned int ln);
void add_n(stack_t **st, unsigned int ln);
void swap_n(stack_t **st, unsigned int ln);


void openf(char *file_n);
void read_f(FILE *fd);
int parse_l(char *buff, int ln, int formatt);


void find_f(char *opc, char *v, int num, int formatt);
void call_f(op_func fuc, char *opc, char *v, int num, int formatt);

void fierror(int err_code, ...);
void serror(int err_code, ...);


#endif
