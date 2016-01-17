/*
Group Members- Ashwin Kini(1209237532), Srinivas Putta(1207034435), Nitish Kochhi(1209301713)
CSE 531- Distributed Multiprocessor Operating Systems.
Project-1 -Q Routines to implement NON premptive scheduling on linux operating systems
Date- 10/13/2015
*/

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include"threads.h"
int j=1;//global variable.

void func1(void)
{
	int i=1;	//local variable.
	while(1)
	{
		printf("This is function 1 and i=%d and j=%d\n",i,j);
		j++;
		sleep(1);
		if(i%5==0)
			{		
			printf("yielding to function 2\n");//Yield when i%5==0. effectively prints value from 1..5
			i=0;
			
			yield();
			}
		i++;
	}
		
	
   return;
}


void func2(void)
{

int i=1;	      //local variable.
	while(1)
	{
		printf("This is function 2 and i=%d and j=%d\n",i,j);
		j++;
		sleep(1);
		if(i%5==0)
			{		
			printf("yielding to function 3\n");//Yield when i%5==0. effectively prints value from 1..5
			i=0;
			yield();
			}
		i++;
	}
 
return ;

}

void func3(void)
{

int i=1;	//local variable.	
	while(1)
	{
		printf("This is function 3 and i=%d and j=%d\n",i,j);
		j++;
		sleep(1);
		if(i%5==0)
			{		
			printf("yielding to function 1\n");//Yield when i%5==0. effectively prints value from 1..5
			i=0;		
			yield();
			}
		i++;
	}
return ;

}

int main()
{

	start_thread(func1);
	start_thread(func2);
	start_thread(func3);
	printf("Starting threads 1 and 2 and 3\n\n");
	run();

return 0;
}

