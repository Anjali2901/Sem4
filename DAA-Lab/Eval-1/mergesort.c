#include<stdio.h>
#include<stdlib.h>
void sort(int* ,int ,int);
void merge(int* ,int ,int ,int);
int main(){
	int n;
	scanf("%d",&n);
	int* a = (int*)malloc(n*sizeof(int));
	int i;
	for(i=0;i<n;i++){
		a[i]=rand()%100;
	}
	sort(a,0,n-1);
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
	printf("\n");
}
void sort(int* a,int l, int r){
	if(r>l) {
		int q = (l+r)/2;
		sort(a,l,q);
		sort(a,q+1,r);
		merge(a,l,q,r);
	}
}
void merge(int* a,int l, int q, int r){
	int b[r-l+1];
	int i,j,k;
	i=l;
	j=q+1;
	k=0;
	while(i<=q&&j<=r){
		if(a[i]>a[j]){
			b[k]=a[j];
			j++;
		}
		else{
			b[k]=a[i];
			i++;
		}
		k++;
	}
	while(i<=q){
		b[k]=a[i];
		k++;
		i++;
	}
	while(j<=r){
		b[k]=a[j];
		j++;
		k++;
	}
	for(i=l,j=0;i<=r;i++,j++){
		a[i]=b[j];
	}
}
