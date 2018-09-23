#include <stdio.h>

void minheapify(int a[],int i,int n)
{
	int left=(i*2+1);
	int right=(i*2+2);
	int smallest,temp;
	if(left<n && a[left]<a[i]){
		smallest=left;
	}
	else{
		smallest=i;
	}
	if(right<n && a[right]<a[smallest]){
		smallest=right;
	}

	if(smallest != i){
		temp=a[i];
		a[i]=a[smallest];
		a[smallest]=temp;
		minheapify(a,smallest,n);
	}
}


void build_min_heap(int a[],int n)
{
	int i;
	for(i=n/2;i>=0;i--)
	{
		minheapify(a,i,n);
	}

}
void insert(int x,int a[],int n)
{
	a[n]=x;
	int i=n,temp;
	int parent=i/2;
	while(a[i]<a[parent]){
		temp=a[i];
		a[i]=a[parent];
		a[parent]=temp;
		i=parent;
		parent=i/2;
	}
}

int delete1(int a[],int n)
{
	int temp=a[0];
	a[0]=a[n-1];
	a[n-1]=temp;
	minheapify(a,0,n-1);
	return temp;
}
int main()
{
	int n,k;scanf("%d%d",&n,&k);
	int i,a[n+1];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	int temp[k+1];
	for(i=0;i<k;i++){
		temp[i]=a[i];
	}
	build_min_heap(temp,k);
	for(i=k;i<n;i++){
		insert(a[i],temp,k);
		printf("%d ",delete1(temp,k+1));

	}
	for(i=0;i<k;i++){
		printf("%d ",delete1(temp,k-i));
	}
	return 0;
}
