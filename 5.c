#include<stdio.h>
int temp[10],k=0;

void toposort(int a[10][10],int id[10],int n){

    int i,j;
    for(i=1;i<=n;i++){
        if(id[i]==0){
            id[i]=-1;
            temp[++k] = i;
            for(j=1;j<=n;j++){
                if(a[i][j]==1 && id[j]!=-1){
                    id[j]--;
                }
            }
            i=0;
        }
    }
}

void main(){
    int n,id[10],a[10][10],i,j;
    printf("Enter the nodes: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        id[i]=0;
    }
    printf("Enter the adjacency matrix: \n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]==1){
                id[j]++;
            }
        }
    }
    toposort(a,id,n);
    if(k!=n){
        printf("Topological sorting not possible \n");
    }else{
        printf("Topological sorting is: ");
        for(j=1;j<=n;j++){
            printf("%d ",temp[j]);
        }
    }
}