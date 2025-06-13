#include<stdio.h>

int s[10],x[10],n,d;

void sumofsubset(int currentsum,int currentindex){
    if(currentsum==d){
        printf("Subset: ");
        for(int i=0;i<currentindex;i++){
            if(x[i]){
                printf("%d ",s[i]);
            }
        }
        printf("\n");
        return;
    }

    if(currentsum > d || currentindex==n){
        return;
    }

    x[currentindex]=1;
    sumofsubset(currentsum + s[currentindex],currentindex+1);

    x[currentindex]=0;
    sumofsubset(currentsum,currentindex+1);
}
int main(){
    int totalsum = 0;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements in ascending order: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&s[i]);
    }
    printf("Enter the target value: ");
    scanf("%d",&d);
    for(int i=0;i<n;i++){
        totalsum += s[i];
    }
    if(totalsum < d){
        printf("Subset not possible \n");
    }
    else{
        sumofsubset(0,0);
    }
}