#include<stdio.h>
#include<limits.h>
int min_index(int distance[],int sptset[],int n){
    int temp = INT_MAX;
    int index;
    int i;
    for(i=0;i<n;i++){
        if(sptset[i]==0 && distance[i] <= temp){
            temp = distance[i];
            index = i;
        }
    }
    return index;
}
void dijkstra(int graph[][100],int n){
    int distance[n];
    int sptset[n];
    int i,v;
    for(i=0;i<n;i++){
        sptset[i]=0;
    }
    distance[0]=0;
    for(i=1;i<n;i++){
        distance[i]=INT_MAX;
    }
    for(i=0;i<n-1;i++){
        int u = min_index(distance,sptset,n);
        sptset[u] = 1;
        for(v=0;v<n;v++){
        if(sptset[v]==0&&graph[u][v]!=0&&distance[u]+graph[u][v]<distance[v]&&distance[u]!=INT_MAX){
            distance[v]=distance[u]+graph[u][v];
            }                        
        }
    }
    for(i=0;i<n;i++){
        printf("%d\n",distance[i]);//prints distance from source to each vertex
    }
}
int main(){
    int n;
    scanf("%d",&n);//number of vertices
    int graph[n][100];
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&graph[i][j]);//adjacency matrix of graph
        }
    }
    dijkstra(graph,n);
    return 0;
}