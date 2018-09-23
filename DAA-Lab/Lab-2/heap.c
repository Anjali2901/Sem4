#include<stdio.h>
int heap_size;
void swap(int* a,int* b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void max_heapify(int a[],int i){
	int l=2*i+1;
	int r=2*i+2;
	int largest;
	if(l<=heap_size&&a[l]>a[i]){
		largest=l;
	}
	else{ 
		largest=i;
	}
	if(r<=heap_size&&a[r]>a[largest]){
		largest=r;
	}
	if(largest!=i){
		swap(&a[i],&a[largest]);
		max_heapify(a,largest);
	}
}
void build_heap(int a[],int n){
	int i;
	for(i=n/2;i>=0;i--){
		max_heapify(a,i);
	}
}
int main(){
	int a[100];
	int i;
	for(i=0;i<100;i++){
		a[i]=0;
	}
	int n;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	heap_size=n-1;
	build_heap(a,n);
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
	printf("\n");
	return 0;
}

