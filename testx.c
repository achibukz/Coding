#include<stdio.h>



//write function countStations() here

void countStations(int x, int y, int* z){
    *z = y - x;
}
//write function computeFare() here

void computeFare(int x, float* y){
    int z = x - 20;

    if(x <= 20){
        *y = 30.00;
    }
    else{
        *y = 30.00 + (z * 1.25);
    }
}

int main()
{   int stationIn = 30;
    int stationOut = 70;
    int positives = 40;


  if (positives != 0){
    if (positives == 0){
        printf("Same Station");
    }	
    else 
    { /* call countStations(), 
         computeFare() and display() */
        int numStation;
        float fare;

        countStations(stationIn, stationOut, &numStation);
        computeFare(positives, &fare);

        printf("Number of Stations: %d\n", numStation);
        printf("Train Fare: %.2f", fare);

    }
  }
    			
    
  return 0; 
}
