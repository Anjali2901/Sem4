# include <stdio.h>
# include <stdlib.h>

int check_MAX_heap(int *,int,int);
void build_MAX_heap(int *,int, int);
int extract_MAX(int *,int, int);
void insert(int *,int,int,int);
void change(int *,int,int,int,int);
void swap(int *, int *);
void max_heapify(int *, int, int, int);
void print(int *, int);
void restoreup(int *, int, int, int);

int main()
{
	char ch=' ';
	int *arr,n,k,i,new;
	scanf("%d",&k);
	scanf("%d",&n); /* To have anything non-trivial, n should be >2*n*k*/
	arr = (int *)malloc(2*n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	if(!check_MAX_heap(arr,n,k)) {
		build_MAX_heap(arr,n,k);
	}
	print(arr,n);
	do
	{
		while(getchar()!='\n'); /* To clear the buffer of any leftover characters*/
		ch=getchar();
		switch(ch)
		{
			case 'i':
				scanf("%d",&new);
				insert(arr,n,k,new);
				n++;
				print(arr,n);
				break;
			case 'd':
				printf("%d\n",extract_MAX(arr,n,k));
				n--;
				break;
			case 'c':
				scanf("%d",&i);
				scanf("%d",&new);
				change(arr,n,k,i,new);
				print(arr,n);
				break;
		}
	}while(ch!='q');
	return 0;
}

int check_MAX_heap(int arr[],int n,int k)
{
	int i, j;
	for(i = 0 ; i < (n-1)/k ; i++) {
		for(j = k*i+1 ; j <= ((k*i)+k) ; j++) {
			if(arr[i] < arr[j])
				return 0;
		}
	}
	return 1;
}

void build_MAX_heap(int arr[],int n,int k)
{
	int i;
	for(i = (n-1)/k ; i >= 0 ; i--)
		max_heapify(arr,n,k,i);
}

void insert(int arr[],int n,int k,int new)
{
	int i;
	arr[n] = new;
	int p = (n-1)/k;
	while(p >= 0) {
		if(arr[n] > arr[p]) {
			swap(&arr[n],&arr[p]);
			n = p;
			p = (n-1)/k;
		}
		else
			break;
	}
}

int extract_MAX(int arr[],int n,int k)
{
	int r;
	r = arr[0];
	swap(&arr[0],&arr[n-1]);
	max_heapify(arr,n-1,k,0);
	return r;
}

void change(int arr[],int n,int k,int i,int new)
{
	int t = arr[i]; 
	arr[i] = new;
	if(new > t) {
		restoreup(arr,n,k,i);
	}
	else {
		max_heapify(arr,n,k,i);
	}
}

void swap(int *a, int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

void max_heapify(int arr[], int n, int k, int i)
{
	while(1) {
		int child[k];
		int j;
		for(j = 0 ; j < k ; j++) {
			if((k*i)+j+1 < n) {
				child[j] = (k*i)+j+1;
			}
			else {
				child[j] = -1;
			}
		}
		int largest = -1;
		int lindex;
		for(j = 0 ; j < k ; j++) {
			if(child[j] != -1 && arr[child[j]] > largest) {
				largest = arr[child[j]];
				lindex = child[j];
			}
		}
		if(largest == -1) {
			break;
		}
		if(largest > arr[i]) {
			swap(&arr[i],&arr[lindex]);
		}
		i = lindex;
	}
}

void print(int arr[],int n) 
{
	int i;
	for(i = 0 ; i < n ; i++) 
		printf("%d ",arr[i]);
	printf("\n");
}

void restoreup(int arr[], int n, int k , int i) 
{
	int p = (i-1)/k;
	while(p >= 0) {
		if(arr[i] > arr[p]) {
			swap(&arr[i],&arr[p]);
			i = p;
			p = (i-1)/k;
		}
		else
			break;
	}
}