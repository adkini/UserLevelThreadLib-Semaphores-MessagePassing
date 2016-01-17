
#include <ucontext.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>



typedef struct TCB_t
{
	ucontext_t context;// To be used in actual code.
	struct TCB_t * next;
	struct TCB_t * prev;

}TCB_t;
TCB_t * RunQ=NULL;



void init_TCB (TCB_t *tcb, void *function, void *stackP, int stack_size)

{
    memset(tcb, '\0', sizeof(TCB_t));       
    getcontext(&tcb->context);              
    tcb->context.uc_stack.ss_sp = stackP;
    tcb->context.uc_stack.ss_size = (size_t) stack_size;
    makecontext(&tcb->context, function, 0);
}
