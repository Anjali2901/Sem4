#include <stdio.h>
#include <string.h>
int partition(int* a, int low, int high)
{
    int left = low;
    int pivotIdx = low + (high - low)/2;
    int pivot = a[pivotIdx];
    a[pivotIdx] = a[high];
    a[high] = pivot;
    pivotIdx = high;
    int partitionIdx = low;
    while (left < high)
    {
        if (a[left] < pivot) 
        {
            int tmp = a[left];
            a[left] = a[partitionIdx];
            a[partitionIdx] = tmp;
            ++partitionIdx;
        }
        ++left;
    }
    a[pivotIdx] = a[partitionIdx];
    a[partitionIdx] = pivot;
    return partitionIdx;
}
 
int quickselect(int* a, int low, int high, int k)
{
    if (low == high)
        return a[low];
    int pivotIdx = partition(a, low, high);
    int sizeOfLeftSubArray = pivotIdx - low + 1;
    if (sizeOfLeftSubArray > k)
    {
        return quickselect(a, low, pivotIdx-1, k);
    }
    else if (sizeOfLeftSubArray < k)
    {
        return quickselect(a, pivotIdx+1, high, k-sizeOfLeftSubArray);
    }
    else
    {
        return a[pivotIdx];
    }
}
int main()
{
  int arr[] = {4, 5, 22, 49, 64, 43, 32 , 323, 78, 90};
  int k;
  scanf("%d", &k);
  printf("%d", quickselect(arr, 0, 9, k));
  return 0;
}
