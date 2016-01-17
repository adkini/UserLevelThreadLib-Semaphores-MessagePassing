#include<stdio.h>
#include<stdlib.h>

#include "q.h"


void start_thread(void (*function)(void))
{ 
	void * stackP = malloc(8192);
	TCB_t * tcb = (TCB_t *)malloc(sizeof(TCB_t));
	init_TCB (tcb, function, stackP,  8192);
	addq( &RunQ,tcb);
}

void run()
{  
	ucontext_t parent;     
	getcontext(&parent);   
	swapcontext(&parent, &(RunQ->context));  
    
}
void yield() 
{
	ucontext_t parent;     
	getcontext(&parent);   
	RunQ->context=parent;
	rotateq(&RunQ);
	swapcontext(&parent, &(RunQ->context));
    
}

