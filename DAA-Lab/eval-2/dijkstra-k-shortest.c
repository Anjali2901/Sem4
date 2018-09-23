# include <stdio.h>
# include <stdlib.h>

void dijkstra(int *p1,int *p2,int *p3,int s,int t, int n, int **adj);

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
	//printf("n=%d\n",n);

	scanf("%d%d%d",&i,&j,&k);
	while(i!=-1)
	{
		adj[i][j]=k;
		scanf("%d%d%d",&i,&j,&k);
	}
	scanf("%d%d",&s,&t);
	dijkstra(parent1,parent2,parent3,s,t,n,adj);
	temp=t;
	printf("\n path1: %d",t);
	while(temp!=s)
	{
		printf("->%d",parent1[temp]);
		temp=parent1[temp];
	}
	temp=t;
	printf("\n path2: %d",t);
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
	return 0;
}
struct node
{
	int cost,a[100],as;
} arr[1000];
int get()
{
	int i, mi = -1;
	for(i=0;i<1000;++i)
	{
		if(arr[i].as == 0) continue;
		if(mi == -1)
		{
			mi = i;
		}
		else if(arr[mi].cost > arr[i].cost)
		{
			mi = i;
		}
	}
	return mi;
}
void dijkstra(int *p1,int *p2,int *p3,int s,int t, int n, int **adj)
{
	printf("In funtion\n"); 	
	int i,j,k,nx;
	for(i=0;i<1000;++i)
		arr[i].as = 0;
	nx = 0;
	arr[nx].a[arr[nx].as++] = s;
	arr[nx].cost = 0;
	nx++;
	int cnt = 0;
	int c1,c2,c3;
	while(get() != -1)
	{
		int l = get();
		int u = arr[l].a[arr[l].as-1];
		int v, isp;
		printf("Considering vertex u=%d, cost=%d\n",u,arr[l].cost);
		for(i=0;i<arr[l].as;++i)
		{
			printf("%d->",arr[l].a[i]);
		}
		printf("\n");
		if(u == t)
		{
			cnt++;
			if(cnt == 1)
			{
				for(i=0;i<arr[l].as;++i)
				{
					if(!i) p1[arr[l].a[i]] = arr[l].a[i];
					else p1[arr[l].a[i]] = arr[l].a[i-1];

					//printf("%d->",arr[l].a[i]);
				}
				printf("Cost of Path1 = %d\n", c1 = arr[l].cost);
				//printf("\n");
			}
			else if(cnt == 2)
			{
				for(i=0;i<arr[l].as;++i)
				{
					if(!i) p2[arr[l].a[i]] = arr[l].a[i];
					else p2[arr[l].a[i]] = arr[l].a[i-1];
					//printf("%d->",arr[l].a[i]);
				}
				printf("Cost of Path2 = %d\n", c2 = arr[l].cost);
			}
			else if(cnt == 3)
			{
				for(i=0;i<arr[l].as;++i)
				{
					if(!i) p3[arr[l].a[i]] = arr[l].a[i];
					else p3[arr[l].a[i]] = arr[l].a[i-1];
					//printf("%d->",arr[l].a[i]);
				}
				printf("Cost of Path3 = %d\n", c3 = arr[l].cost);
			}
			else break;


			arr[l].as = 0;
			continue;
		}
		for(i=0;i<n;++i)
		{
			isp = 1;
			if(!adj[u][i]) continue;
			for(j=0;j<arr[l].as;++j)
			{
				if(arr[l].a[j] == i) isp = 0;
			}
			if(!isp) continue;

			arr[nx].cost = arr[l].cost + adj[u][i];

			for(j=0;j<arr[l].as;++j)
			{
				arr[nx].a[j] = arr[l].a[j];
			}
			arr[nx].a[arr[l].as] = i;
			arr[nx].as = arr[l].as+1;
			nx++;
			printf("extended by adding %d\n",i);
		}
		arr[l].as = 0;
	}
	if(cnt < 3) printf("only %d paths found\n",cnt);
	int gv;
	printf("calculated \n");
	printf("Cost of Path1 = %d\n", c1);
	printf("Cost of Path2 = %d\n", c2);
	printf("Cost of Path3 = %d\n", c3);
	//scanf("%d",&gv);
	return;
}
