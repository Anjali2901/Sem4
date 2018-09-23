#include<stdio.h>
void csort(int*,int);
int main(){
	int n;
	int i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	csort(a,n);
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
	printf("\n");
}
void csort(int a[],int n){
	int b[10];
	int i;
	for(i=0;i<10;i++){
		b[i]=0;
	}
	int temp;
	for(i=0;i<n;i++){
		temp=a[i];
		b[temp]++;
	}
	for(i=1;i<10;i++){
		b[i]=b[i]+b[i-1];
	}
	int sorted[n+1];
	for(i=0;i<n;i++){
		temp=a[i];
		sorted[b[temp]]=temp;
		b[temp]--;
	}
	for(i=1;i<n+1;i++){
		a[i-1]=sorted[i];
	}	
}
