#include<stdio.h>
int main()
{
  long int n,i=0,j=0;
  printf("Enter Number of Processes : ");
  scanf("%ld",&n ); 
  double priority[n],avg_waiting,avg_turnaround,burstTime[n],arrivalTime[n],waitingTime[n],turnaroundTime[n], process[n], temp, completionTime[n],min,sum=0,sum2=0,wait_final, turnaround_final, wait_avg, turnaround_avg;
  for(i=0;i<n;i++)
  {
    printf("\nEnter Burst Time for Process [%ld] : ", i+1 );
    scanf("%lf", &burstTime[i]);
    printf("Enter Arrival Time for Process [%ld] : ", i+1 );
    scanf("%lf", &arrivalTime[i] );
    process[i]=i+1;
  }

  printf("\n\n\tData Provided By The User\n\n");
  printf("\t Process  Arrival Time  Burst Time \n\n");
  for(i=0;i<n;i++)
  {
    printf("\t  P[%0.0lf]          %0.0lf           %0.0lf      \n",process[i],arrivalTime[i],burstTime[i]);
  }

  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(arrivalTime[i]<arrivalTime[j])
      {
        
        temp = burstTime[j];
        burstTime[j] = burstTime[i];
        burstTime [i] = temp;
	
	      temp = process[j];
        process[j] = process[i];
        process[i] = temp;

	      temp = arrivalTime[j];
        arrivalTime[j] = arrivalTime[i];
        arrivalTime[i] = temp;
      
      }
    }
  }
    for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(arrivalTime[i]==arrivalTime[j])
      {
      	if (burstTime[i]<burstTime[j]){
		  
        temp = burstTime[j];
        burstTime[j] = burstTime[i];
        burstTime [i] = temp;
	
	      temp = process[j];
        process[j] = process[i];
        process[i] = temp;

	      temp = arrivalTime[j];
        arrivalTime[j] = arrivalTime[i];
        arrivalTime[i] = temp;
  		}
      }
    }
  }

  long int k = 1;
  double b_time = 0;
  for(j=0;j<n;j++)
  {
    b_time = b_time + burstTime[j];
    min = burstTime[k];

    for(i=k;i<n;i++)
    {
      if((b_time >=arrivalTime[i])&&(burstTime[i]<min))
      {
        temp = burstTime[k];
        burstTime[k] = burstTime[i];
        burstTime[i] = temp;

        temp = arrivalTime[k];
        arrivalTime[k] = arrivalTime[i];
        arrivalTime[i] = temp;

        temp = process[k];
        process[k] = process[i];
        process[i] = temp;
      }
    }
    k++;
  }


  completionTime[0] = burstTime[0];
  for(i=1;i<n;i++)
  {
    completionTime[i] = completionTime[i-1] + burstTime[i];
  }
   waitingTime[0] = 0;
   for(i=1;i<n;i++)
  {
    sum += burstTime[i-1];
    waitingTime[i] = sum - arrivalTime[i];
    wait_final += waitingTime[i]; 
  }
  wait_avg = wait_final/n;
  for(i=0;i<n;i++)
  {
    sum2 += burstTime[i];
    turnaroundTime[i] = sum2 - arrivalTime[i];
    turnaround_final += turnaroundTime[i];
  }
  turnaround_avg=turnaround_final/n;

  printf("\n\n\tAfter Calculating Waiting Time And Turn Around Time\n\n");
  printf("\t Process  Arrival Time  Burst Time   Waiting Time    Turn Around Time  \n");
  for(i=0;i<n;i++)
  {
    printf("\t  P[%0.0lf]          %0.0lf           %0.0lf              %0.0lf                %0.0lf          \n",process[i],arrivalTime[i],burstTime[i],waitingTime[i],turnaroundTime[i]);
  }

 
printf("\n\n\tNow , Prioritizing All The Processes According The Formaula \n\tPriority = 1+ Waiting time / Estimated run time\n\n");

  printf("\n\tThe Calculated Priority Of All The Processes : \n");
  for(i=0;i<n;i++)
  {
    priority[i] = 1+waitingTime[i]/completionTime[i];
    printf("\n\t%0.01lf\n",priority[i]);
  }


  printf("\n\n\tAfter Using The Formula, The Arrangement Is : \n\n");
  printf("\t Process  Arrival Time  Burst Time   Waiting Time    Turn Around Time  \n\n");
 
  for(i=0;i<n;i++)
  {
    printf("\t  P[%0.0lf]          %0.0lf           %0.0lf              %0.0lf                %0.0lf      \n",process[i],arrivalTime[i],burstTime[i],waitingTime[i],turnaroundTime[i]);
  }

  printf("\n\tThe Average Turn Around Time : %0.01lf",turnaround_avg);
  printf("\n\tThe Average Waiting Time     : %0.01lf\n\n",wait_avg);
}
