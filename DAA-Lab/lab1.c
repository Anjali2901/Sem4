# include <stdio.h>
# include <stdlib.h>
# include <time.h>
void hybridSort(int *,int);
void sort(int [],int,int,int);
int main()
{
	int *arr,n;
	srand((unsigned int)time(NULL));
	scanf("%d",&n);
	arr = (int *)malloc(n*sizeof(int));
	hybridSort(arr,n);
	return 0;
}
void hybridSort(int *arr, int n)
{
	int i,k;
	int l,r;
	l=0;
	r=n-1;
	clock_t begin,end;
	for(i=0;i<n/2;i++){
		arr[i]=i;
	}
	for(i=n/2;i<n;i++){
		arr[i]=rand();	
	}
	int a[n];
	int j;
	for(k=1;k<101;k++){
		for(j=0;j<n;j++){
			a[j]=arr[j];
		}	
		begin = clock();
		sort(a,l,r,k);
		end = clock();
		printf("%d\t%lf\n",k,(double)(end-begin));
	}
}
int partition(int a[],int l,int r){
	int pivot,pindex;
	pivot=a[r];
	pindex=l;
	int i;
	int temp;
	for(i=l;i<r;i++){
		if(a[i]<=pivot){
			temp=a[i];
			a[i]=a[pindex];
			a[pindex]=temp;
			pindex=pindex+1;
		}
	}
	temp=a[pindex];
	a[pindex]=a[r];
	a[r]=temp;
	return pindex;
}
void sort(int a[],int l,int r,int k){
	int pivot;
	if(r-l+1>k){
		if(l<r){
			pivot=partition(a,l,r);
			sort(a,l,pivot-1,k);
			sort(a,pivot+1,r,k);
		}
	}
	else{
		int i,j,temp;
		for(i=l;i<=r;i++){
			for(j=i+1;j<=r;j++){
				if(a[i]>a[j]){
					temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
		}	
	}
}
