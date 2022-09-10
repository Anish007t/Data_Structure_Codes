#include<stdio.h>
int main()
{
	//Assume 4x5 Sparce matrix
	int sparsematrix[4][5]={{0,0,3,0,4},{0,0,5,7,0},{0,0,0,0,0},{0,2,6,0,0}};
	int size=0,i,j;
	for(i=0;i<4;i++)
		for(j=0;j<5;j++)
			if(sparsematrix[i][j]!=0)
				size++;	//count the non zero elements
	/*number of columns in Compact matrix must be equal to number of non-zero elements in sparsematrix*/
	int compactmatrix[size][3];
	int k=0;
	for(i=0;i<4;i++)
		for(j=0;j<5;j++)
			if(sparsematrix[i][j]!=0)
			{
				compactmatrix[k][0]=i;
				compactmatrix[k][1]=j;
				compactmatrix[k][2]=sparsematrix[i][j];
				k++;	
			}
	printf("\nThe Output matrix=\n");
	printf("\nRow\tColumn\tValue\n");
	for(i=0;i<size;i++)
	{
		for(j=0;j<3;j++)
			printf("%d\t",compactmatrix[i][j]);
		printf("\n");
	}
	return 0;
}
