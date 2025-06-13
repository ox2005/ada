#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge(long int a[],long int left,long int mid,long int right){
    long int i = left;
    long int j = mid+1;
    long int k = 0;
    long int temp[right-left+1];
    while(i<=mid && j<=right){
        temp[k++] = (a[i]<a[j])?a[i++]:a[j++];
    }
    while(i<=mid){
        temp[k++] = a[i++];
    }
    while(j<=right){
        temp[k++] = a[j++];
    }
    for(i=left,k=0;i<=right;i++,k++){
        a[i] = temp[k];
    }

}


void mergesort(long int arr[],long int left,long int right){
    if(left < right){
    long int mid = (left + right)/2;
    mergesort(arr,left,mid);
    mergesort(arr,mid+1,right);
    merge(arr,left,mid,right);
}
}

int main(){
    long int n=60000;
    long int iteration =5;
    clock_t start,end;
    double timetaken;
    printf("Input size \t Time taken \n");
    for(long int i=0;i<iteration;i++){
        long int *arr = (long int*)malloc(n*sizeof(long int));
        for(long int j=0;j<n;j++){
            arr[j] = rand()%10000000;
        }
        
        start = clock();
        mergesort(arr,0,n-1);
        end = clock();
        
        timetaken = (double)(end-start)/CLOCKS_PER_SEC*1000;
        printf("%ld \t \t %.2fms \n",n,timetaken);
        n+=10000;
    }


    return 0;
}