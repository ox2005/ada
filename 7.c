#include<stdio.h>

void main(){
    int n,i,j,k,capacity;
    float totalvalue=0;
    int weight[10],profit[10],index[10];
    float ratio[10];
    printf("Enter number of items: ");
    scanf("%d",&n);

    printf("Enter the weight followed by profit \n");
    for(i=0;i<n;i++){
    scanf("%d %d",&weight[i],&profit[i]);
    ratio[i] = (float)profit[i]/weight[i];
    index[i] = i+1;
    }
    printf("Enter the capacity of knapsack: ");
    scanf("%d",&capacity);
    //sorting
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(ratio[i]<ratio[j]){
                float tempratio = ratio[i]; ratio[i] = ratio[j];ratio[j] = tempratio;
                int tempprofit = profit[i]; profit[i] = profit[j];profit[j] = tempprofit;
                int tempweight = weight[i]; weight[i] = weight[j];weight[j] = tempweight;
                int tempindex = index[i]; index[i] = index[j];index[j] = tempindex;
            }
        }
    }

    for(i=0;i<n && capacity > 0;i++){
        if(weight[i]<=capacity){
            capacity -= weight[i];
            totalvalue += profit[i];
            printf("Added item %d (%d,%d) fully remaining capacity is %d \n",index[i],weight[i],profit[i],capacity);
        }else{
            float frac = (float)capacity/weight[i];
            totalvalue += frac*profit[i];
            printf("Added item %d %.2f (w=%d,p=%d) \n",index[i],frac*100,weight[i],profit[i]);
            capacity = 0;
        }
    }
    printf("knapsack value is %.2f ",totalvalue);
}
3 10
3 15
2 10
5 12
1 8