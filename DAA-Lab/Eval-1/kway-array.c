#include<stdio.h>
#include<stdlib.h>
#define n 4
#define INT_MAX 100000
struct element
{
	int value;
	int index;    
	int arrIndex; 
};
void swap(struct element *a, struct element *b)
{
	struct element temp = *a;
	*a = *b;
	*b = temp;
}

void minHeapify(struct element a[], int size, int i)
{
	int l = 2*i;
	int r = 2*i+1;
	int smallest = i;
	if(l<size && a[l].value<a[smallest].value)
		smallest = l;
	if(r<size && a[r].value<a[smallest].value)
		smallest = r;
	if(smallest!=i)
	{
		swap(&a[i],&a[smallest]);
		minHeapify(a,size,smallest);
	}

}
void buildMinHeap(struct element a[], int size) {
	for(int i=size/2;i>=0;i--)
		minHeapify(a,size,i);
}
int *mergesortedArrays(int arr[][n], int k)
{
	int *ans = (int*)malloc((n*k)*sizeof(int));
	struct element minHeap[k];
	for (int i = 0; i < k; i++)
	{
		minHeap[i].value = arr[i][0];
		minHeap[i].index = i;
		minHeap[i].arrIndex = 1;
	}
	buildMinHeap(minHeap,k);
	for (int count = 0; count < n*k; count++)
	{
		ans[count]=minHeap[0].value;
		int index = minHeap[0].index;
		int c = minHeap[0].arrIndex;
		if(c<n)
		{
			minHeap[0].value = arr[index][1];
			minHeap[0].arrIndex+=1;
		}
		else
			minHeap[0].value=INT_MAX;
		minHeapify(minHeap,k,0);
	}
	return ans;
}
void printArray(int arr[], int size)
{
	for (int i=0; i < size; i++) {
		printf("%d\t",arr[i]);
	}
	printf("\n");
}
int main()
{
	int a[][n] =  {{1, 3, 5, 7},
		{2, 4, 6, 8},
		{3, 6, 9, 12}};
	int k = sizeof(a)/sizeof(a[0]);
	int *ans = mergesortedArrays(a, k);
	printArray(ans, n*k);
	return 0;
}

