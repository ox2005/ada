#include<stdio.h>

void main(){
    int i,j,n,u,v,ne=1,cost[9][9],visited[9],min,mincost=0;

    printf("Enter the number of vertex : ");
    scanf("%d",&n);
    printf("Enter the adjacency matrix: \n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
            cost[i][j]=999;
        }
    }

    for(i=1;i<=n;i++){
        visited[i]=0;
    }
    printf("The edges of mst are : \n");
    visited[1]=1;

    while(ne<n){

        for(i=1,min=999;i<=n;i++){
            for(j=1;j<=n;j++){
                if(cost[i][j]<min){
                    if(visited[i]==0){
                        continue;
                    }else{
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        if(visited[u]==0||visited[v]==0){
            printf("%d edge(%d,%d) is %d \n",ne++,u,v,min);
            mincost += min;
            visited[v]=1;
        }
            cost[u][v] = cost[v][u] = 999;
    }
    printf("The mincost is %d \n",mincost);
}