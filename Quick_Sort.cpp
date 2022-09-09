#include<stdio.h>
void quickSort(int *,int,int);
int partition(int *,int,int);
void swap(int *,int *);
int main()
{
	int n,i,arr[20];
	printf("Enter size of array : ");
	scanf("%d",&n);
		printf("Input array elements : ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	quickSort(arr,0,n-1);
	printf("The sorted array is : ");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	return 0;
}
void quickSort(int arr[],int s,int e)		// s = starting index, e= end index
{
	if(s>=e)								//base condition when starting index is greater than end index
		return;
	else
	{
		int p=partition(arr,s,e);
		quickSort(arr,0,p-1);				//sort the left part having elements lesser than the pivot
		quickSort(arr,p+1,e);				//sort the right part having elements greater than the pivot
	} 
}
int partition(int arr[],int s,int e)
{
	int pivot=arr[e];						//select the last element as the pivot
	int i=(s-1);							// pointer for greatest element
	int k;
	for(k=s;k<e;k++)						//Traverse each element of the array
	{
		if(arr[k]<pivot)					//Compare each element with the pivot
		{
			i++;							//increment index of smaller element
			swap(&arr[i],&arr[k]);
		} 
	}
	swap(&arr[i+1],&arr[e]);				//swap the pivot element with the greater element at i
	return (i+1);
}
void swap(int *v1,int *v2)
{
	int temp=*v1;
	*v1=*v2;
	*v2=temp;
}
