#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int a[],int low,int high){
    int pivot = a[low];
    int i=low+1;
    int j=high;
    while(1){
        while(i<=high && a[i]<=pivot){
            i++;
        }
        while(j>=low && a[j]>pivot){
            j--;
        }
        if(i<j){
            swap(&a[i],&a[j]);
        }else{
            break;
        }
    }
    swap(&a[low],&a[j]);
    return j;
}
void quicksort(int a[],int low,int high){
    if(low < high){
        int pi = partition(a,low,high);
        quicksort(a,low,pi-1);
        quicksort(a,pi+1,high);
    }
}
int main(){
    int n=60000;
    int iteration =5;
    clock_t start,end;
    double timetaken;
    printf("Input size \t Time taken \n");
    for(int i=0;i<iteration;i++){
        int arr[n];
        for(int j=0;j<n;j++){
            arr[j] = rand()%100000;
        }
        
        start = clock();
        quicksort(arr,0,n-1);
        end = clock();
        
        timetaken = (double)(end-start)/CLOCKS_PER_SEC*1000;
        printf("%ld \t \t %.2fms \n",n,timetaken);
        n+=10000;
    }


    return 0;
}