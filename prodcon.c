#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int mutex = 1, full = 0 , empty = MAX;
int buffer[MAX] , p= 0 , c =0 ;
void signal(int * s)
{
		*s=*s+1;
}
void wait(int * s)
{
	*s=*s-1;
}
void produce()
{	
	int item;
	printf("Enter item to produce:");
	scanf("%d",&item);
	wait(&mutex) ;
	wait(&empty) ;

	p = (p+1)%MAX ;
	buffer[p] = item ;
	printf("Produced : %d" , item) ;

	signal(&mutex) ;
	signal(&full) ;
		
}
void consume()
{
	
	wait(&mutex) ;
	wait(&full) ;
	c= (c+1)%MAX ;
	int item = buffer[c] ;
	printf("Consumed : %d" , item) ;
	signal(&mutex) ;
	signal(&empty) ;
}

int main()
{
	
	int choice;
	while(1)
	{
		printf("\n1.Produce\n2.Consume\n3.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 :if(mutex==0||empty==0)
					{
						printf("\nBuffer Full cannot Produce!");
					}
					else
						produce();
					break ;
			case 2 :if(mutex==0||empty==MAX)
					{
						printf("\nBuffer Empty cannot Consume!");
					}
					else
						consume() ;
					break ;
			case 3:	exit(0);
		}
		
	}
	return 0;
	
	
}

