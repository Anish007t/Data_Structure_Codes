#include<stdio.h>
void mergeSort(int *,int,int);
void merge(int *,int,int,int);
int main()
{
	int n,i,arr[20];
	printf("Enter size of array : ");
	scanf("%d",&n);
	printf("Input array elements : ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	mergeSort(arr,0,n-1);						//function call to print the sorted array
	printf("The sorted array is : ");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	return 0;
}
void mergeSort(int arr[],int s,int e)
{
	int mid=s+(e-s)/2;
	if(s>=e)									//base condition when starting index is greater than end index
	return;
	else
	{
		mergeSort(arr,0,mid);					//sort the left part of the array till middle index
		mergeSort(arr,mid+1,e);					//sort the right part of array from (mid+1)th index till last index
	}
	merge(arr,s,mid,e);							//to merge the sorted array
}
void merge(int arr[],int s,int mid,int e)
{
	int i,j,firstArray[10],secondArray[10];
	int len1=mid-s+1;							//length of first sub-array
	int len2=e-mid;								//length of second sub-array
	for(i=0;i<len1;i++)
		firstArray[i]=arr[s+i];					//copy the values to fist sub-array
	for(j=0;j<len2;j++)
		secondArray[j]=arr[mid+1+j];			//copy the values to second sub-array
	int firstArrayIndex=0,secondArrayIndex=0,k=s;
	while(firstArrayIndex < len1 && secondArrayIndex < len2)	//check whether correct index position is maintained
	{
		if(firstArray[firstArrayIndex] <= secondArray[secondArrayIndex])	//to sort between two sub-array
		{
			arr[k++]=firstArray[firstArrayIndex++];
		}
		else
		{
			arr[k++]=secondArray[secondArrayIndex++];
		}
	}
	while(firstArrayIndex < len1)
	{
	arr[k++]=firstArray[firstArrayIndex++];		//sort the first sub-array
	}
	while(secondArrayIndex < len2)
	{
		arr[k++]=secondArray[secondArrayIndex++];	//sort the second subarray
	} 
}
