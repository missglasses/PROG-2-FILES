#include <stdio.h>
#include <stdlib.h>

//get mean average
//get median - sort data and get middle part
 // mode  - how many modes ex: 1,1,2,2,4 value : 2
 //rand modulo with max cvalue ex: rand()%101
 //graph : base100; occurences 

void populate(int list[], int count);
float getMean(int list[], int count);
float getMedian(int list[], int count);
int *getMode(int list[], int count, int *mode_count);
int getMax(int list[], int count);
int getMin(int list[], int count);
int *sortList(int list[], int count);
void displayList(int list[], int count);
int counAboveAverage(int list[], int count);
int countEven(int list[], int count);
int countOdd(int list[], int count);
int *getAllNegative(int list[], int count, int *neg_count);
void graph(int list[], int count);
int *getAllPositiveAndRemove(int list[], int *count, int *pos_rem_count);



 int main (){

    srand(TIME(NULL));
    int myList[100], count =30;
    populate(myList, count);
    displayList(myList, count);


    return 0;
 }


 void populate(int list[], int count){
    for (int i=0; i<count; i++){
        list[i]=(rad()%20)+1;
        if(list[i]!=0 && (rad()%2)==0){
            list[i]*=-1;
        }
    }
 }
float getMean(int list[], int count){

    int sum = 0, mean=0;
    int ctr=0;

    for (int i=0; i<count; i++){
        sum +=list[i];
        ctr++;
    } 
    mean = sum /count;

    return mean;

}
float getMedian(int list[], int count){

    //center and  occurences
    int mid=0;
    //call the sorted func
    for (int i=0; i<count; i++){

    }

    //create a new malloc
    // looop and copy arr from list
    // return 


    return mid;

}
int *getMode(int list[], int count, int *mode_count){
    //occurences
    //sorted func
    

}
int getMax(int list[], int count){

    int max = list[0]; //max as first elmment
    for (int i=0; i<count; i++){
           
        if (list[i]>max){
            max = list[i];
        }
    }

    return max;

}
int getMin(int list[], int count){
    int min = list[0];
    for (int i=0; i<count; i++){
        if (list[i]<min){
            min = list[i];
        }
    }
    return min;
}

int *sortList(int list[], int count){

    int *sort = malloc(sizeof(int)*count);

    int j=0;
    for(int i=0; i<count; i++){
        sort[j]=list[i];
    }
//create a new malloc
    // looop and copy arr from list

    return sortList;
}
void displayList(int list[], int count){
    for (int i=0; i<count; i++){

    }
}
int counAboveAverage(int list[], int count){

}
int countEven(int list[], int count){
    int evCtr=0; 

    for (int i=0; i<count; i++){
        if (list[i]%2==0){
            evCtr++;
        }
    }
    return evCtr;
}
int countOdd(int list[], int count){
    int odCtr=0;

    for(int i=0; i<count; i++){
        if (list[i]%2!=0){
            odCtr++;
        }
    }
    return odCtr;

}
int *getAllNegative(int list[], int count, int *neg_count){
    //malloc ni sya
    int *negzOnly = malloc(sizeof(int)*count);

    for(int i=0; i<count; i++){
        if(list[i]<=0){
        (*neg_count)++;
        }
    }
    
      return negzOnly;  
}
void graph(int list[], int count){

}
int *getAllPositiveAndRemove(int list[], int *count, int *pos_rem_count){

    int *getPos = malloc(sizeof(int)*(count));
    int j=0;
    for(int i=0; i<*count; i++){
        if (list[i]<=0){
        getPos[j]=list[i];
        
        }
    }
}

