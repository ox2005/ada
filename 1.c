#include<stdio.h>
int i,j,u,v,a,b,n,ne=1;
int cost[9][9],min=0,mincost,parent[9];
int find(int i);
int uni(int i,int j);
void main(){
    printf("Kruskal's Algorithm \n");
    printf("Enter number of vertex: ");
    scanf("%d",&n);
    printf("Enter the adjacency matrix: \n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
            cost[i][j]=999;
        }
    }
    printf("Minimum Spanning Tree using Kruskal's Algorithm: \n");
    while(ne<n){

        for(i=1,min=999;i<=n;i++){
            for(j=1;j<=n;j++){
                if(min > cost[i][j]){
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u=find(u);
        v=find(v);
        if(uni(u,v)){
            printf("%d edge(%d,%d) is %d \n",ne++,a,b,min);
            mincost += min;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("The minimum cost is %d ",mincost);
}
int find(int i){
    while(parent[i])
    i = parent[i];
    return i;
}
int uni(int i,int j){
    if(i!=j){
        parent[j] = i;
        return 1;
    }
    return 0;
}