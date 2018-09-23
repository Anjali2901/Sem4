# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

void radix_sort(char **,int,int);
void quicksortX(char **input, int n, int k, int i);
void exch(char **a, int i, int j){
	char tem[1000];
	strcpy(tem, a[i]);
	strcpy(a[i], a[j]);
	strcpy(a[j],tem);
}
int main()
{
	char **input;
	char ch=' ';
	int n,k,i,j;
	srand(time(NULL));
	scanf("%d",&n);
	scanf("%d",&k);
	input = (char **)malloc(n*sizeof(char *));
	for(i=0;i<n;i++)
	{
		input[i]=(char *)malloc((k+1)*sizeof(char));
		for(j=0;j<k;j++)
			input[i][j]=(rand()%95)+32;
		input[i][k]='\0';
	}
	radix_sort(input,n,k);
	for(i=0;i<n;i++)
	{
		printf("%s\n",input[i]);
	}

	return 0;
}

void radix_sort(char **input,int n,int k)
{
	int i;
	printf("\n");
	for(i = 0 ; i<n;i++){
		printf("%s\n", input[i]);
	}
	printf("\n");
	for(i=k-1;i>=0;i--){
		//printf("%d", i);
		quicksortX(input, 0, n-1, i);
	}
	return;
}
void quicksortX(char **a, int lo, int hi, int d){
	if (hi - lo <= 0) return;
	int i = lo-1, j = hi;
	int k;	
	int p = lo-1, q = hi;
	char v = a[hi][d];
	while (i < j)
	{
		while (a[++i][d] < v) if (i == hi) break;
		while (v < a[--j][d]) if (j == lo) break;
		if (i > j) break;
		exch(a, i, j);
		if (a[i][d] == v) exch(a, ++p, i);
		if (a[j][d] == v) exch(a, j, --q);
	}
	if (p == q)
	{
		if (v != '\0') quicksortX(a, lo, hi, d+1);
		return;
	}
	if (a[i][d] < v) i++;
	for (k = lo; k <= p; k++) exch(a, k, j--);
	for ( k = hi; k >= q; k--) exch(a, k, i++);
	quicksortX(a, lo, j, d);
	if ((i == hi) && (a[i][d] == v)) i++;
	if (v != '\0') quicksortX(a, j+1, i-1, d+1);
	quicksortX(a, i, hi, d);

}

