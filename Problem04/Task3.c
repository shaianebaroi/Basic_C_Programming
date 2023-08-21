#include <stdio.h>
    
int main() {

    //TOTAL NUMBER OF PROCESSES
    int num;
    printf("Please enter the total number of processes: ");
    scanf("%d", &num); 
    
    //ARRIVAL TIMES, BURST TIMES AND PRIORITY OF THE PROCESSES
    int arrival_time[num], burst_time[num], temp[num], priority[num+1];
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
        
        //PRIORITY
        printf("Priority: ");
        scanf("%d", &priority[count]); 
    }
    
    int array_size = sizeof(priority)/sizeof(priority[0]);
    
    double sum_waiting_time = 0, sum_turnaround_time = 0, completion_time = 0;
    float average_waiting_time, average_turnaround_time;
    
    int count = 0;
    priority[array_size - 1] = num + 1;  
    for(int time = 0; count != num; time++) {   
        //FINDING THE SHORTEST JOB
        int smallest = array_size - 1;
        for(int count = 0; count <= num; count++) {
              if(arrival_time[count] <= time && priority[count] < priority[smallest] && burst_time[count] > 0) {
                    smallest = count;
              }
        }
        
        //GANTT CHART
        //printf("P%d \n", smallest+1);
        
        burst_time[smallest]--;
        
        //WHEN A PROCESS COMPLETES
        if (burst_time[smallest] == 0) {
            
            printf ("\nFor P%d,", smallest+1);
            count++;
            
            completion_time = time + 1;
            printf("\nCompletion Time = %lf", completion_time);
            
            double turnaround_time = completion_time - arrival_time[smallest];
            printf("\nTurnaround Time = %lf", turnaround_time);
            sum_turnaround_time += turnaround_time;
            
            double waiting_time = turnaround_time - temp[smallest];
            printf("\nWaiting Time = %lf \n\n", waiting_time);
            sum_waiting_time += waiting_time;
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

