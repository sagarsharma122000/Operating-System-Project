#include<stdio.h>
#include<conio.h>

int main()
{
	int process,p_arrival[20],p_brust[20],p_priority[20],i,q1_temp[20];
	int Total=0,t1=0,t2=0,t3=0;
	
	printf("Enter the number of Process : ");
	scanf("%d",&process);
	
	printf("\nEnter the Detail of Every Process\n");
	for(i=1;i<=process;i++)
	{
		printf("Enter the Arrival time for Procees[%d] : ",i);
		scanf("%d",&p_arrival[i-1]);
		printf("Enter the Brust time for Procees[%d] : ",i);
		scanf("%d",&p_brust[i-1]);
		printf("Enter the Priority for Procees[i] (1-15) : ");
		scanf("%d",&p_priority[i-1]);
		printf("\n\n");
		Total=Total+p_brust[i-1];
	}
	
	int q1_art[20],q1_brt[20],q2_art[20],q2_brt[20],q3_art[20],q3_brt[20],q2_priority[20]; 
	int m=0,k=0,l=0;
	for(i=0;i<process;i++)
	{
		if(p_priority[i]>=1&&p_priority[i]<=5)
		{
			printf("Process[%d] belongs to Queue 1\n",i+1);
			q1_art[m]=p_arrival[i];
			q1_brt[m]=p_brust[i];
			q1_temp[m]=p_brust[i];
			m++;
			t1=t1+p_brust[i];
		}
		
		else if(p_priority[i]>=6&&p_priority[i]<=10)
		{
			printf("Process[%d] belongs to Queue 2\n",i+1);
			q2_art[k]=p_arrival[i];
			q2_brt[k]=p_brust[i];
			q2_priority[k]=p_priority[i];
			k++;
			t2=t2+p_brust[i];
		}
		
		else if(p_priority[i]>=11&&p_priority[i]<=15)
		{
			printf("Process[%d] belongs to Queue 3\n",i+1);
			q3_art[l]=p_arrival[i];
			q3_brt[l]=p_brust[i];
			l++;
			t3=t3+p_brust[i];
		}
	}
	//Round Robin 1
	
	
	printf("Time Quantum between these queues is 10seconds\n");
	for(i=1;i<Total;i=i+10)
	{
		if(t1>10)
		{
			printf("Queue1 is running for 10 units\n");
			t1=t1-10;
		}
		else if(t1<=10&&t1!=0)
		{
			printf("Queue1 is running for %d units\n",t1);
			t1=0;
		}
		if(t2>10)
		{
			printf("Queue2 is running for 10 units\n");
			t2=t2-10;
		}
		else if(t2<=10&&t2!=0)
		{
			printf("Queue2 is running for %d units\n",t2);
			t2=0;
		}
		if(t3>10)
		{
			printf("Queue3 is running for 10 units\n");
			t3=t3-10;
		}
		else if(t3<=10&&t3!=0)
		{
			printf("Queue3 is running for %d units\n",t3);
			t3=0;
		}
	}
	
	//Round Robin 2
	printf("\n\nProcess Running on queue 1 in Round Robin Schedulling are\n");
	printf("\nProcess		Arrival Time\t    Burst Time    \tWaiting Time\tTurnaround Time\n");
	
	
	int q1_tq=4,q1_wt=0,q1_tat=0,j,x,q1_total=0,counter=0,limit;
	float q1_avgwt, q1_avgtat;
	limit=m;
	x=limit;
	for(q1_total = 0, i = 0; x != 0;)
      {
            if(q1_temp[i] <= q1_tq && q1_temp[i] > 0)
            {
                  q1_total = q1_total + q1_temp[i];
                  q1_temp[i] = 0;
                  counter = 1;
            }
            else if(q1_temp[i] > 0)
            {
                  q1_temp[i] = q1_temp[i] - q1_tq;
                  q1_total = q1_total + q1_tq;
            }
            if(q1_temp[i] == 0 && counter == 1)
            {
                  x--;
                  printf("\nProcess[%d]\t\t%d\t\t%d\t\t %d\t\t\t %d", i + 1,q1_art[i],q1_brt[i],q1_total - q1_art[i] - q1_brt[i] ,q1_total - q1_art[i] );
                  q1_wt = q1_wt + (q1_total - q1_art[i] - q1_brt[i]);
                  q1_tat = q1_tat + (q1_total - q1_art[i]);
                  counter = 0;
            }
            if(i == limit - 1)
            {
                  i = 0;
            }
            else if(q1_art[i + 1] <= q1_total)
            {
                  i++;
            }
            else
            {
                  i = 0;
            }
      }
      printf("\n%d",q1_tat);
      q1_avgwt = q1_wt * 1.0 / limit;
      q1_avgtat = q1_tat * 1.0 / limit;
      printf("\n\nAverage Waiting Time:\t%f", q1_avgwt);
      printf("\nAvg Turnaround Time:\t%f\n", q1_avgtat);
	
	
			//Priority Schedullling
	printf("\n\nProcess Running on queue 2 in Priority Schedulling are\n\n");
	printf("\nProcess		Arrival Time\t    Burst Time    \tWaiting Time\tTurnaround Time");
			
			int q2_temp,q2_wt[20],q2_tat[20],q2_start[20],q2_full[20],q2_twt=0,q2_ttat=0;
			float q2_avgwt,q2_avgtat;
			for(i=0; i<k; i++)
			{
        		for(j=0; j<k; j++)
        		{
            		if(q2_priority[i]<q2_priority[j])
            		{
                		q2_temp=q2_priority[i];
                		q2_priority[i]=q2_priority[j];
                		q2_priority[j]=q2_temp;
                		q2_temp=q2_art[i];
                		q2_art[i]=q2_art[j];
                		q2_art[j]=q2_temp;
                		q2_temp=q2_brt[i];
                		q2_brt[i]=q2_brt[j];
                		q2_brt[j]=q2_temp;
            		}
        		}
        	}
    		for(i=0; i<k; i++)
    		{
        		if(i==0)
        		{
            		q2_start[i]=q2_art[i];
            		q2_wt[i]=q2_start[i]-q2_art[i];
            		q2_full[i]=q2_start[i]+q2_brt[i];
            		q2_tat[i]=q2_full[i]-q2_art[i];
        		}
        		else
        		{
            		q2_start[i]=q2_full[i-1];
            		q2_wt[i]=q2_start[i]-q2_art[i];
            		q2_full[i]=q2_start[i]+q2_brt[i];
            		q2_tat[i]=q2_full[i]-q2_art[i];
        		}
        		q2_twt+=q2_wt[i];
        		q2_ttat+=q2_tat[i];		
			}
			
			q2_avgwt=(float)q2_twt/k;
    		q2_avgtat=(float)q2_ttat/k;
			
			for(i=0; i<k; i++)
        		printf("\nProcess[%d]\t\t%d\t\t%d\t\t %d\t\t\t %d",i+1,q2_art[i],q2_brt[i],q2_wt[i],q2_tat[i]);	
			
			printf("\n\nAverage Waiting Time:\t%f",q2_avgwt);
    		printf("\nAvg Turnaround Time:\t%f\n",q2_avgtat);
	
	
			//First Come First Serve
	printf("\n\nProcess Running on queue 3 in First Come First Serve are\n\n");
	printf("\nProcess		Arrival Time\t    Burst Time    \tWaiting Time\tTurnaround Time");
	
	
			int q3_wt[20],q3_twt=0,q3_ttat=0;
			float q3_avgwt,q3_avgtat;
			q3_wt[0]=0;			
			for(i=1;i<l;i++)
    		{
        		q3_wt[i]=0;
        		for(j=0;j<i;j++)
        		{
           			q3_wt[i]+=q3_brt[j]; 
        		}
    		}
    		int q3_tat[20];
    		for(i=0;i<l;i++)
    		{
        		q3_tat[i]=q3_brt[i]+q3_wt[i];
        		q3_twt+=q3_wt[i];
        		q3_ttat+=q3_tat[i];
        		printf("\nProcess[%d]\t\t%d\t\t%d\t\t %d\t\t\t %d",i+1,q3_art[i],q3_brt[i],q3_wt[i],q3_tat[i]);
    		}
    		q3_avgwt=(float)q3_twt/l;
    		q3_avgtat=(float)q3_ttat/l;
    		
    		printf("\n\nAverage Waiting Time:\t%f",q3_avgwt);
    		printf("\nAvg Turnaround Time:\t%f\n",q3_avgtat);
 
    	return 0;	
	
}
