#include<stdlib.h>
#include<stdio.h> 
#define MAX 5
void findwt(int bt[],int at[])
{
	int i,wt[MAX];
	float avgwt,wtsum=0;
	wt[0]=0;
	for(i=1;i<MAX;i++)
	{
		wt[i]=wt[i-1]+bt[i-1];
	}
	for(i=0;i<MAX;i++)
	{
		wt[i]=wt[i]-at[i];
	}
	
	printf("WT\n");
	for(i=0;i<MAX;i++)
	{
		printf("%d\n",wt[i]);
		wtsum=wtsum+wt[i];
	}
	avgwt=wtsum/MAX;
	printf("Average Waiting time:%3f\n",avgwt);
	
}
void findtat(int bt[],int at[])
{
	int i,ct[MAX],tat[MAX];
	float avgtat;
	ct[0]=bt[0];
	for(i=1;i<MAX;i++)
	{
		ct[i]=ct[i-1]+bt[i];
	}
	for(i=0;i<MAX;i++)
	{
		tat[i]=ct[i]-at[i];
	}
	printf("TAT\n");
	float tsum=0;
	for(i=0;i<MAX;i++)
	{
		printf("%d\n",tat[i]);
		tsum=tsum+tat[i];
	}
	
	avgtat=tsum/MAX;
	printf("Average TurnaroundTime time:%3f\n",avgtat);
}
int main()
{
	int i,at[MAX],bt[MAX];
	printf("Enter the arrival time of process :");
	for(i=0;i<MAX;i++)
	{
		scanf("%d",&at[i]);
	}	
	printf("Enter the burst time of process :");
	for(i=0;i<MAX;i++)
	{
		scanf("%d",&bt[i]);
	}
	
	printf("P\tBT\tAT\n");
	for(i=0;i<MAX;i++)
	{
		printf("%d\t%d\t%d\n",i+1,bt[i],at[i]);
	} 
	findwt(bt,at);
	findtat(bt,at);
	return 0;
}
