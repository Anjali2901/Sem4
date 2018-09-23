#include<stdio.h>
#include<stdlib.h>
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
void sort(int a[],int l,int r){
	int pivot;
	if(l<r){
		pivot=partition(a,l,r);
		sort(a,l,pivot-1);
		sort(a,pivot+1,r);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,0,n-1);
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
	printf("\n");
	return 0;
}
