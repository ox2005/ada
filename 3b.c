#include<stdio.h>

void warshall(int p[10][10],int n){
    int i,j,k;
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                p[i][j] = p[i][j] || (p[i][k] && p[k][j]);
            }
        }
    }
}

void main(){
    int n,p[10][10]={0},i,j,k,u,v,e;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);

    printf("Enter the no of edges: ");
    scanf("%d",&e);
    printf("Enter the edges: \n");
    for(i=1;i<=e;i++){
            scanf("%d %d",&u,&v);
            p[u][v] = 1;
        }
    printf("The matrix is :\n");
    for(i=1;i<=n;i++){
        printf("\n");
        for(j=1;j<=n;j++){
            printf("%d ",p[i][j]);
        }
    }
    warshall(p,n);
    printf("\n The transitive closure of matrix is: \n");
        for(i=1;i<=n;i++){
        printf("\n");
        for(j=1;j<=n;j++){
            printf("%d ",p[i][j]);
        }
    }

}