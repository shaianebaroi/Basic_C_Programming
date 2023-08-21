#include <stdio.h>
#include <stdbool.h>

int main() {

	//PARAMETERS
    int n = 5; //NUMBER OF PROCESSES
    int m = 4; //NUMBER OF RESOURCES
    
    //ALLOCATION MATRIX
    int alloc[5][4] = {{0,1,0,3},{2,0,0,0},{3,0,2,0},{2,1,1,5},{0,0,2,2}};

	//MAX MATRIX
    int max[5][4] = {{6,4,3,4},{3,2,2,1},{9,1,2,6},{2,2,2,8},{4,3,3,7}};

	//AVAILABLE RESOURCES
    int avail[4] = {3,3,2,1};

	//INITIALISING THE FINAL ARRAY
	int final[n];
    for (int k = 0; k < n; k++) {
   	 final[k] = 0;
    }
	
	//COMPUTING THE NEED (MAX - ALLOCATION)
    int need[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }    
    }
    
    //RUNNING THE BANKER'S ALGORITHM
	bool flag = false;
    for (int k = 0; k < 5; k++) {
        for (int i = 0; i < n; i++) {
            if (final[i] == 0) {
                flag = false;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]){
                        flag = true;
                        break;
                    }
                }

                if (flag == false) {
                    for (int y = 0; y < m; y++) {
                        avail[y] += alloc[i][y];
                    }    
                    final[i] = true;
                }
            }
        }
    }

    flag = true;
    
    //FINAL CONDITIONS FOR DEADLOCK
    for(int i=0; i < n; i++) {
        if(final[i] == false) {
            flag = false;
            printf("Deadlock Ahead\n");
            break;
        }
    }
    if(flag == true){
        printf("Safe Here\n");
    }
    return 0;
}


