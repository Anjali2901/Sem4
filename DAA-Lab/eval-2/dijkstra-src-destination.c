# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

void dijkstra(int *,int *,int *,int **,int,int,int);

int main()
{
  int **adj, *parent1,*parent2,*parent3;
  int n,k,i,j,s,t,temp;
  scanf("%d",&n);
  adj = (int **)calloc(n,sizeof(int *));
  for(i=0;i<n;i++)
    {
      adj[i] = (int *)calloc(n,sizeof(int));
    }
  parent1 = (int *)calloc(n,sizeof(int));
  parent2 = (int *)calloc(n,sizeof(int));
  parent3 = (int *)calloc(n,sizeof(int));

  for(i = 0 ; i < n ; i ++) {
    for( j = 0 ; j < n ; j++) {
      adj[i][j] = 0;
    }
  }
  
  scanf("%d%d%d",&i,&j,&k);
  while(i!=-1)
    {
      adj[i][j] = k;
//      adj[j][i] = k;
      scanf("%d%d%d",&i,&j,&k);
    }
  scanf("%d%d",&s,&t);
  dijkstra(parent1,parent2,parent3,adj,s,t,n);
  temp=t;
  printf("\n path1: %d",t);
  while(temp!=s)
    {
      printf("->%d",parent1[temp]);
      temp=parent1[temp];
    }
  temp=t;
/*  printf("\n path2: %d",t);
  while(temp!=s)
    {
      printf("->%d",parent2[temp]);
      temp=parent2[temp];
    }
  temp=t;
  printf("\n path3: %d",t);
  while(temp!=s)
    {
      printf("->%d",parent3[temp]);
      temp=parent3[temp];
    }
*/ return 0;
}

int min_dist(int *d,int *v,int n)
{
  int i,min = INT_MAX,ind = -1;
  for(i = 0 ; i < n ; i++) {
    if(v[i] == 0 && min > d[i]) {
      min = d[i];
      ind = i;
    }
  }
  return ind;
}

void dijkstra(int *p1,int *p2,int *p3,int **adj,int s,int t,int n)
{
  int d[n],v[n];
  int i,j,u;
  for(i = 0 ; i < n ; i++) {
    p1[i] = -1;
    d[i] = INT_MAX;
    v[i] = 0;
  }
  d[s] = 0;
  for (i = 0; i < n; i++) {
    u = min_dist(d,v,n);
    if (u == -1)
      continue;
    v[u] = 1;
    for (j = 0; j < n; j++) {
      if(adj[u][j] != 0 && d[j] > d[u] + adj[u][j] && v[j] == 0) {
        d[j] = d[u] + adj[u][j];
        p1[j] = u;
      }
    }
  }
  return;
  
}