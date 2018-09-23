#include<stdio.h>
#include<stdlib.h>
int search(int *, int, int, int);
void sort(int *,int);
void swap(int* ,int *);
int main() {
	int n;
	scanf("%d", &n);
	int* a = (int*)malloc(n*sizeof(int));
	int i;
	for(i=0;i<n;i++){
		a[i]=rand()%100;
	}
	sort(a,n);
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
	printf("\n");
	int x;
	scanf("%d",&x);
	printf("Result-%d\n",search(a,x,0,n));
	return 0;
}
void swap(int* a, int* b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void sort(int *a, int n){
	int i, j;
	for(i = 0;i < n - 1; i++) {
		for(j = i+1; j < n; j++) {
			if(a[i]>a[j]){
				swap(&a[i],&a[j]);
			}
		}
	}
}
int search(int* a,int x, int l, int r) {
	int m = (l + r)/2;
	while(l<=r) {
		if(a[m] == x) {
			return 1;
		}
		else if (x > a[m]) {
			return search(a,x,m+1,r);
		}
		else {
			return search(a,x,l,m-1);
		}
	}
	return 0;
}
