#include<stdio.h>
void swap(int*,int*);
void heapify(int[],int,int);
void heapsort(int[],int);
int main()
{
	int i,n;
	printf("\nEnter how many elements=");
	scanf("%d",&n);
	int arr[n];
	printf("\nEnter the elements=");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	heapsort(arr,n);
	printf("\nThe sorted array is=");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void heapify(int arr[],int n,int i)
{
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	if(left<n && arr[left]>arr[largest])
		largest=left;
	if(right<n && arr[right]>arr[largest])
		largest=right;
	if(largest!=i)
	{
		swap(&arr[i],&arr[largest]);
		heapify(arr,n,largest);
	}
}
void heapsort(int arr[],int n)
{
	int i;
	for(i=n/2-1;i>=0;i--)
		heapify(arr,n,i);
	for(i=n-1;i>=0;i--)
		{
			swap(&arr[0],&arr[i]);
			heapify(arr,i,0);
		}
}
