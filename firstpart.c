#include<stdio.h>
#include<conio.h>

void main()
{
	int process,p_arrival[20],p_brust[20],p_priority[20],i;
	printf("Enter the number of Process : ");
	scanf("%d",&process);
	
	printf("\nEnter the detail of every Process\n");
	for(i=1;i<=process;i++)
	{
		printf("Enter the Arrival time for Procees[%d] : ",i);
		scanf("%d",&p_arrival[i-1]);
		printf("Enter the Brust time for Procees[%d] : ",i);
		scanf("%d",&p_brust[i-1]);
		printf("Enter the Priority for Procees[i] in range of 1 to 15 : ");
		scanf("%d",&p_priority[i-1]);
		printf("\n\n");
	}
	
	int q1_art[20],q1_brt[20],q2_art[20],q2_brt[20],q3_art[20],q3_brt[20]; 
	int j=0,k=0,l=0;
	for(i=0;i<process;i++)
	{
		if(p_priority[i]>=1&&p_priority[i]<=5)
		{
			printf("Process[%d] belongs to Queue 1\n",i+1);
			q1_art[j]=p_arrival[i];
			q1_brt[j]=p_brust[i];
			j++;
		}
		
		else if(p_priority[i]>=6&&p_priority[i]<=10)
		{
			printf("Process[%d] belongs to Queue 2\n",i+1);
			q2_art[k]=p_arrival[i];
			q2_brt[k]=p_brust[i];
			k++;
		}
		
		else if(p_priority[i]>=11&&p_priority[i]<=15)
		{
			printf("Process[%d] belongs to Queue 3\n",i+1);
			q3_art[l]=p_arrival[i];
			q3_brt[l]=p_brust[i];
			l++;
		}
	}
	
	
	

}
