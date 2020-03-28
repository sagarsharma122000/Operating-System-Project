#include<stdio.h>
#include<conio.h>

void main()
{
int q1_art[20],q1_brt[20],q1_priority[20],q1_temp[20];
int m,i;

printf("Enter the number of Process : ");
	scanf("%d",&m);
	
	printf("\nEnter the Detail of Every Process\n");
	for(i=1;i<=m;i++)
	{
		printf("Enter the Arrival time for Procees[%d] : ",i);
		scanf("%d",&q1_art[i-1]);
		printf("Enter the Brust time for Procees[%d] : ",i);
		scanf("%d",&q1_brt[i-1]);
		printf("Enter the Priority for Procees[i] : ");
		scanf("%d",&q1_priority[i-1]);
		printf("\n\n");
		q1_temp[i-1]=q1_brt[i-1];
	}
  
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
	

}
