#include <stdio.h>
#include <stdlib.h>
struct bucket 
{
	int count;
	int* values;
};
int compareIntegers(const void* first, const void* second)
{
	int a = *((int*)first), b =  *((int*)second);
	if (a == b)
	{
		return 0;
	}
	else if (a < b)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}
void bucketSort(int array[],int n)
{
	struct bucket buckets[3];
	int i, j, k;
	for (i = 0; i < 3; i++)
	{
		buckets[i].count = 0;
		buckets[i].values = (int*)malloc(sizeof(int) * n);
	}
	// Divide the unsorted elements among 3 buckets
	// < 0    : first
	// 0 - 10 : second
	// > 10   : third
	for (i = 0; i < n; i++)
	{
		if (array[i] < 0)
		{
			buckets[0].values[buckets[0].count++] = array[i];
		}
		else if (array[i] > 10)
		{
			buckets[2].values[buckets[2].count++] = array[i];
		}
		else
		{
			buckets[1].values[buckets[1].count++] = array[i];
		}
	}
	for (k = 0, i = 0; i < 3; i++)
	{
		// Use Quicksort to sort each bucket individually
		qsort(buckets[i].values, buckets[i].count, sizeof(int), &compareIntegers);
		for (j = 0; j < buckets[i].count; j++)
		{
			array[k + j] = buckets[i].values[j];
		}
		k += buckets[i].count;
		free(buckets[i].values);
	}
}

int main(int brArg,char *arg[]) {

	int array[100] = { -5, -9, 1000, 1, -10, 0, 2, 3, 5, 4, 1234, 7 };
	int i = 12,j,k,n;

	n=i;
	for (j = 0; j<i; j++)
	{
		printf("Broj: %d\n", array[j]);
	}

	bucketSort(array, n); 
	for (k = 0; k<i; k++)
		printf("%d \n", array[k]);   


	return 0;
}
