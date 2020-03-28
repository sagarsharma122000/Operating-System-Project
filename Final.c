#include<stdio.h>
#include<conio.h>

void main()
{
	int l,q3_art[20],q3_brt[20],i,q3_temp,q3_wt[20],q3_tat[20],q3_start[20],q3_finish[20],j;
    int q3_twt=0,q3_ttat=0;	
	printf("Enter the number of Process : ");
	scanf("%d",&l);
	
	printf("\nEnter the Detail of Every Process\n");
	for(i=1;i<=l;i++)
	{
		printf("Enter the Arrival time for Procees : ");
		scanf("%d",&q3_art[i-1]);
		printf("Enter the Brust time for Procees : ");
		scanf("%d",&q3_brt[i-1]);
		printf("\n\n");
	}
	
	for(i=0; i<l; i++)
    {
        for(j=0; j<l; j++)
        {
            if(q3_art[i]<q3_art[j])
            {
                q3_temp=q3_art[i];
                q3_art[i]=q3_art[j];
                q3_art[j]=q3_temp;
                q3_temp=q3_brt[i];
                q3_brt[i]=q3_brt[j];
                q3_brt[j]=q3_temp;
            }
 
        }
    }
    for(i=0; i<l; i++)
    {
        if(i==0)
            q3_start[i]=q3_art[i];
        else
            q3_start[i]=q3_finish[i-1];
        q3_wt[i]=q3_start[i]-q3_art[i];
        q3_finish[i]=q3_start[i]+q3_brt[i];
        q3_tat[i]=q3_finish[i]-q3_art[i];
    }
	printf("\n\nProcess Running on queue 3 in First Come First Serve are\n\n");
	printf("\nProcess		Arrival Time\t    Burst Time    \tWaiting Time\tTurnaround Time");
	
	for(i=0; i<l; i++)
    {
        printf("\nProcess[%d]\t\t%d\t\t%d\t\t %d\t\t\t %d",i+1,q3_art[i],q3_brt[i],q3_wt[i],q3_tat[i]);
        q3_twt+=q3_wt[i];
        q3_ttat+=q3_tat[i];
    }
    
    printf("\n\nAverage Waiting Time:\t%f",(float)q3_twt/l);
    printf("\nAvg Turnaround Time:\t%f\n",(float)q3_ttat/l);
}
