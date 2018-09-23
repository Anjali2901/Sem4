#include<stdio.h>
void bsort(int a[],int l, int r){
	int i,j,temp;
	for(i=l;i<r;i++){
		for(j=i+1;j<r;j++){
			if(a[i]>a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
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
	bsort(a,0,n-1);
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
	printf("\n");
	return 0;

}

