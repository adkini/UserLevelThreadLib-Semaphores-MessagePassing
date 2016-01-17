#include "threads.h"

typedef struct{
	int value;
	TCB_t *Q;
}Semaphore_t;


Semaphore_t CreateSem(int x)
{
	Semaphore_t sem;
	memset(&sem, '\0', sizeof(Semaphore_t));
	sem.value = x;
	sem.Q = NULL;
	return sem;
}

void P(Semaphore_t *sem)
{	
	TCB_t *token = NULL;
	(sem->value)--;
	if(sem->value < 0)
	{
	token  = deleteq(&RunQ);
	addq(&(sem->Q), token);
	swapcontext(&(token->context), &(RunQ->context));
	}
}

void V(Semaphore_t *sem)
{
	TCB_t *token;
	(sem->value)++;
	if(sem->value <= 0)
	{
	token = deleteq(&(sem->Q));

	addq(&RunQ, token);
	}
	yield();	
}
