#include<stdio.h>
#include<conio.h>

void main()
{
	int k,q2_art[20],q2_brt[20],q2_priority[20],i,j;
	
	printf("Enter the number of Process : ");
	scanf("%d",&k);
	
	printf("\nEnter the Detail of Every Process\n");
	for(i=1;i<=k;i++)
	{
		printf("Enter the Arrival time for Procees[%d] : ",i);
		scanf("%d",&q2_art[i-1]);
		printf("Enter the Brust time for Procees[%d] : ",i);
		scanf("%d",&q2_brt[i-1]);
		printf("Enter the Priority for Procees[i]  : ");
		scanf("%d",&q2_priority[i-1]);
		printf("\n\n");
	}
	
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
	
}
	
