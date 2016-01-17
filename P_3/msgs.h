#include "sem.h"


int clientId;
struct port {
	Semaphore_t  *mutex;
        Semaphore_t  *consumer;
        Semaphore_t  *producer;
        int mes[10][10];
	int in;
        int out;
};



struct port p[100];

void send(int mes[],int pno,int a) {
         int x;
	P(p[pno].producer);
	P(p[pno].mutex);
        int count=0;
        clientId=a;
        x=p[pno].in;
	while(count < 10) {
        
	p[pno].mes[x][count]=mes[count];
        count++;
	}
	p[pno].in =(x+1)%10;
	V(p[pno].mutex);
	V(p[pno].consumer);
}

void receive(int mes[],int pno) {
        int y;
	P(p[pno].consumer);
	P(p[pno].mutex);
        int count=0;
        y=p[pno].out;
	while(count < 10) { 
        mes[count]=p[pno].mes[y][count];
	count++;
        }
	p[pno].out=(y+1)%10;
	V(p[pno].mutex);
	V(p[pno].producer);
}





