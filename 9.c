#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void selectionsort(int a[], int n){
    int i,j,minindex,temp;
    for(i=0;i<n-1;i++){
        minindex =i;
        for(j=i+1;j<n;j++){
            if(a[j] < a[minindex]){
                minindex = j;
            }
        }
        temp = a[i];a[i] = a[minindex];a[minindex] = temp;
    }
}

void main(){
    int n=6000;
    int iteration = 5;
    clock_t start ,end;
    double timetaken;
    printf("Input Size \t Time taken \n");
    for(int i=0;i<iteration;i++){
        int *arr = (int*)malloc(n*sizeof(int));
        for(int j=0;j<n;j++){
            arr[j] = rand()%100000;
        }
        start = clock();
        selectionsort(arr,n);
        end = clock();
        timetaken = (double)(end-start)/CLOCKS_PER_SEC*1000;
        printf(" %d \t  \t %.2fms \n",n,timetaken);
        n+=1000;

    }


}
