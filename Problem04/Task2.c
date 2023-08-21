#include<stdio.h>
 
int main() {
    
    //TOTAL NUMBER OF PROCESSES
    int num;
    int arrival_time[10], burst_time[10], temp[10];
    printf("Please enter the total number of processes: ");
    scanf("%d", &num); 
    
    //COPYTING TOTAL NUMBER OF PROCESSES IN ANOTHER VARIABLE
    int num2 = num;
    
    //ARRIVAL AND BURST TIMES OF THE PROCESSES
    printf("Please enter the arrival and burst times of the processes: \n");
    for(int count = 0; count < num; count++) {
        printf ("For P%d, \n", count+1);
        
        //ARRIVAL TIMES
        printf("Arrival Time: ");
        scanf("%d", &arrival_time[count]);
        
        //BURST TIMES
        printf("Burst Time: ");
        scanf("%d", &burst_time[count]); 
        
        //COPYING BURST TIMES IN A TEMP ARRAY
        temp[count] = burst_time[count];
    }
    
    //TIME QUANTUM
    int time_quantum;
    printf("Please enter the time quantum: ");
    scanf("%d", &time_quantum); 
    
   
    
    int sum_waiting_time, sum_turnaround_time;
    float average_waiting_time, average_turnaround_time;
    
    int time = 0;
    int count = 0;
    int status;
    
    while (num2 != 0) {
        //WHEN BURST TIME IS LESS THAN TIME QUANTUM
        if(burst_time[count] <= time_quantum && burst_time[count] > 0) {
              time += burst_time[count];
              burst_time[count] = 0;
              status = 1;
              //printf("At time = %d, \n", time);
              //printf("P%d \n", count+1);
        }
        
        //WHEN BURST TIME IS GREATER THAN TIME QUANTUM
        else if(burst_time[count] > time_quantum && burst_time[count] > 0) {
              burst_time[count] = burst_time[count] - time_quantum;
              time += time_quantum;
              //printf("At time = %d, \n", time);
              //printf("P%d \n", count+1);
        }
        
        //WHEN A PROCESS COMPLETES
        if (burst_time[count] == 0 && status == 1) {
        	printf("\nFor P%d,", count + 1);
            num2--;
            
            double completion_time = time;
            printf("\nCompletion Time = %lf", completion_time);
            
            double turnaround_time = completion_time - arrival_time[count];
            printf("\nTurnaround Time = %lf", turnaround_time);
            sum_turnaround_time += turnaround_time;
            
            double waiting_time = turnaround_time - temp[count];
            printf("\nWaiting Time = %lf \n\n", waiting_time);
            sum_waiting_time += waiting_time;
              
            status = 0;
        }
        
        //RETURNING TO THE FIRST PROCESS AFTER LAST PROCESS IS EXECUTED
        if(count == num - 1) {
              count = 0;
        }
        
        //EXECUTING THE PROCESSES SERIALLY UNTIL LAST PROCESS IS EXECUTED
        else if(arrival_time[count + 1] <= time) {
            count++;
        }
        
        //FOR ALL OTHER CASES
        else {
            count = 0;
        }
    }
    /*
    //AVERAGE WAITING TIME
    average_waiting_time = sum_waiting_time / num; 
    printf("\nAverage Waiting Time: %lf", average_waiting_time);
    
    //AVERAGE TURNAROUND TIME
    average_turnaround_time = sum_turnaround_time / num;
    printf("\nAverage Turnaround Time: %lf", average_turnaround_time);
    */
    return 0;
}
