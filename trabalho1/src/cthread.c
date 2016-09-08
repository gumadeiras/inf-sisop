/*
**
** cthread.c
** Biblioteca cthreads
**
** Instituto de Inform�tica - UFRGS
** Sistemas Operacionais I N 2016/2
** Prof. Alexandre Carissimi
**
*/

#include <stdio.h>
#include <stdlib.h>
#include <ucontext.h>

#include <cdata.h>
#include <cthread.h>
#include <support.h>

//extern?

int ccreate (void* (*start)(void*), void *arg)
{
	if (!has_init_cthreads)
	{
		init_cthreads();
	}

	// cria��o da thread
	TCB_t c_thread;
	c_thread = (TCB_t *)malloc(sizeof(TCB_t));	//precisa fazer malloc?
	c_thread.tid = threadCount;	threadCount++;
	c_thread.state = PROCST_CRIACAO;
	cthread.ticket = Random2();

	getcontext(&c_thread.context);

	c_thread.context.uc_link = &scheduler;
	c_thread.context.uc_stack.ss_sp = malloc(CT_STACK_SIZE);
	c_thread.context.uc_stack.ss_size = sizeof(CT_STACK_SIZE);
	c_thread.context.uc_stack.ss_flags = 0;

	makecontext(&c_thread.context, (void (*)(void)) start, 1, &arg);

	//coloca thread na fila de aptos
	AppendFila2(&filaAptos, (void *) &c_thread);
	c_thread.state = PROCST_APTO;

	return c_thread.tid;
}

int cyield(void)
{
		if (!has_init_cthreads)
	{
		init_cthreads();
	}

	TCB_t *c_thread;
	getcontext(&c_thread.context);
	AppendFila2(&filaAptos, (void *) &c_thread);
	swapcontext(&c_thread.context, &scheduler);

	return 0;
}

int cjoin(int tid)
{
	if (!has_init_cthreads)
	{
		init_cthreads();
	}

}

int csem_init(csem_t *sem, int count)
{
	if (!has_init_cthreads)
	{
		init_cthreads();
	}

}
int cwait(csem_t *sem)
{
	if (!has_init_cthreads)
	{
		init_cthreads();
	}

}

int csignal(csem_t *sem)
{
	if (!has_init_cthreads)
	{
		init_cthreads();
	}

}
