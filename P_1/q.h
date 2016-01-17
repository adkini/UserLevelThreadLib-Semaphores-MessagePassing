#include<stdio.h>
#include<stdlib.h>

#include "TCB.h"


void initq(TCB_t ** q)
{

	*q=NULL;// Init the head.
	
}


void addq(TCB_t ** q,TCB_t * t)
{

	
	TCB_t* tmp=*q,*tmp1,*tmp2;// Temporary pointer as head and some more temporary pointers.
	

	if(*q==NULL)// If first element
	{	
		*q=t;
		t->prev=t;
		t->next=t;
		
	}

	else// if not first element.
	{	
		tmp1=tmp->prev;
		tmp1->next=t;
		t->prev=tmp1;
		t->next=tmp;
		tmp->prev=t;
		
	}

return;

}


void rotateq(TCB_t ** q)
{
	TCB_t * tmp=*q;//Temporary pointer pointing to head.
	*q=tmp->next;// Shift head to next.
	
}


TCB_t * deleteq(TCB_t **q)
{
	TCB_t * tmp4;// Points to previous in the code.
	TCB_t * tmp5;// Points to next node in the code.
	TCB_t * tmp=*q;//Temporary pointer pointing to head. 
	
	if(tmp->next==*q)// If only one element,make head NULL and return the node.
	{
		*q=NULL;
		return tmp;
	}


  	if (*q!=NULL)// If queue isnt empty,Delete the first element.
	{
		tmp4=tmp->prev;
		tmp5=tmp->next;
		*q=tmp5;
		tmp4->next=tmp5;
		tmp5->prev=tmp4;
		return tmp;
	
	}
	if(*(q)==NULL)// If queue is NULL, return.
		return NULL;
	
}

