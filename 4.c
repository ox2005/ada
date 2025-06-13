#include<stdio.h>

void dijkstra(int c[10][10],int n,int s,int d[10]){
    int i,j,v[10],u,min;
    for(i=1;i<=n;i++){
        d[i] = c[s][i];
        v[i] = 0;
    }
    v[s]=1;
    for(i=1;i<=n;i++){
        min=999;
        for(j=1;j<=n;j++){
            if(v[j]==0 && d[j]<min){
                min = d[j];
                u = j;
            }
        }

        for(j=1;j<=n;j++){
            if(v[j]==0 && (d[u] + c[u][j])<d[j]){
                d[j] = d[u]+c[u][j];
            }
        }
    }
}

void main(){
    int i,j,n,s,c[10][10],d[10];
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    printf("Enter the source vertex: ");
    scanf("%d",&s);
    printf("Enter the adjacency matrix: \n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&c[i][j]);
        }
    }
    dijkstra(c,n,s,d);
    for(i=1;i<=n;i++)
    printf("The shortest path from %d to %d is %d \n",s,i,d[i]);
}