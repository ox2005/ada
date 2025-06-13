#include<stdio.h>
int i,j,k,n,a[10][10],cost[10][10];

void readf(){
printf("Enter the number of nodes: ");
scanf("%d",&n);
printf("Enter the cost adjacency matrix: \n");
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        scanf("%d",&cost[i][j]);
        if(cost[i][j]==0 && i!=j)
        cost[i][j]=999;
        a[i][j] = cost[i][j];
    }
}
}

void amin(){
    
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(a[i][j] > a[i][k] + a[k][j]){
                    a[i][j] = a[i][k] + a[k][j];
                }
            }
        }
    }
    printf("The all pair shortest path is \n");
    for(i=1;i<=n;i++){
        printf("\n");
        for(j=1;j<=n;j++){
            printf("%d ",a[i][j]);
        }
    }
}

void main(){
    readf();
    amin();
}