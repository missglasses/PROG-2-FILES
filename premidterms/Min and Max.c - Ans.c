#include <stdio.h>

// Function prototypes
int find_min(double data[], int size);
int find_max(double data[], int size);

int main() {
    // Quarterly GDP growth rate data for 5 years (2019-2023)
    double gdp_growth[20] = {
        2.2, 2.8, 2.0, 2.3,  // 2019
        -1.3, -9.1, 7.5, 4.5, // 2020 (COVID impact)
        6.4, 6.7, 2.3, 3.5,   // 2021
        3.7, 2.1, 2.9, 3.2,   // 2022
        1.9, 2.5, 3.3, 2.8    // 2023
    };

    char* quarters[20] = {
        "Q1/2019", "Q2/2019", "Q3/2019", "Q4/2019",
        "Q1/2020", "Q2/2020", "Q3/2020", "Q4/2020",
        "Q1/2021", "Q2/2021", "Q3/2021", "Q4/2021",
        "Q1/2022", "Q2/2022", "Q3/2022", "Q4/2022",
        "Q1/2023", "Q2/2023", "Q3/2023", "Q4/2023"
    };
    
    int max_idx, min_idx;
    //  int max_idx, min_idx;

    // [1] To do code logic for calling the min and max
    min_idx = find_min(gdp_growth,20);
    max_idx = find_max(gdp_growth,20);

    // Perform analyses
    printf("\nGDP Growth Rate Analysis (2019-2023)\n");
    printf("==================================\n");

    printf("\nExtreme Values:\n");
    printf("Highest Growth: %.2f%% in %s\n", gdp_growth[max_idx], quarters[max_idx]);
    printf("Lowest Growth: %.2f%% in %s\n", gdp_growth[min_idx], quarters[min_idx]);
    return 0;
}

 
int find_min(double data[], int size) {
    // [3] To do code logic here. Change the return value with actual value.
    // int min=0; 
    if (size <= 0) return -1;
    int minPos=0;
    
    float min=data[0]; //first element
    // data[0]=max;
    for (int i=1;i<size; i++){
    //   if (min<data[i]){
      if (data[i]<min){ //
        //   min = data[i]+1;
        //   min = data[i+1];
          min = data[i];
           minPos = i;
      } 
          
    }
   //   minPos++;
    return minPos;
}

int find_max(double data[], int size) {
    // [4] To do code logic here. Change the return value with actual value.
        if (size <= 0) return -1;
    int maxPos=0;
    
     float max=data[0]; 
    for (int i=1;i<size; i++){
    //   if (max<data[i]){
       if (data[i]>max){

              max = data[i];
        //  max = data[i];
            maxPos = i;
   
      } 
        
    }
     //  maxPos++;  
    return maxPos;

    // return 0;
}
