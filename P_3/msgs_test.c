/*
Author- Ashwin Kini(1209237532), Srinivas Putta(1207034435), Nitish Kochhi(1209301713)
CSE 531- Distributed Multiprocessor Operating Systems.
Project-3
*/


#include "msgs.h"

int message[10];


void pSend(int message[],int a,int b,int clientId){

        printf("\t\t\t\t#####client%d running at port=%d sending message",clientId, a);
        printf(" =");
        int mCount=0;
        while(mCount<10){    
        printf("%d",message[mCount]);
        mCount++;
        }
        printf(" to server running at port=%d",b);
       

}



void pReceive(int message[],int a,int b,int clientId){

       printf("\t\t\t\t#####client%d running at port=%d received message",clientId,a);
       int mCount=0;
        printf(" =");       
        while(mCount<10){
              
        printf("%d",message[mCount]);
        mCount++;
        }
       printf(" from server running at port=%d",b);
      

}



void server1() {
        int s=50;
        int serverId=1;
	int message[10];
	for(;;){
        printf("\t\t#####server%d waiting for request at port=%d\n",serverId,s);
	receive(message,s);
	printf("\t\t#####server%d sending reply to port=%d\n",serverId,message[0]);
	send(message,message[0],s); 
	sleep(1);
	}
}

	


void client1() {
        int s=50;
	int c = 6;
        printf("Starting first client=client1 at port %d\n",c);
	message[0]=6;
	for(;;){

        int count=1;
        int mCount=1;
        
        while(count<=10){
        message[count]=rand()%7;
        count++;
        }
        
        pSend(message,c,s,1);
        printf("\n");
	send(message,s,c);
        receive(message,c);
        pReceive(message,c,s,1);
        printf("\n");
        sleep(1);
	}
}


void client2() {
        int s=50;
	int c = 7;
        printf("Starting second client=client2 at port %d\n",c);
        message[0]=7;
	for(;;){

        int count=1;
        int mCount=1;
       
        while(count<=10){
        message[count]=rand()%7;
        count++;
        }  
        pSend(message,c,s,2);
        printf("\n");
	send(message,s,c);
        receive(message,c);
        pReceive(message,c,s,2);
        printf("\n");
        sleep(1);
	}
}



int main() {

        
	initq(&RunQ);
	
        int count = 0;
        int s=50;
        while(count < 100) {
        p[count].mutex = CreateSem(1);

        p[count].producer = CreateSem(10);

	p[count].consumer = CreateSem(0);

        count++;
		
	}
        printf("Starting first server=server1 at port %d\n",s);
	start_thread(server1);
	start_thread(client1);
	start_thread(client2);
        
	run();
}
