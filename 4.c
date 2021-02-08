
/*A program to find the matrix multiplication using 2-D arrays*/

#include<stdio.h>
int SOParrays(int *,int ,int *);
void multiply(int , int , int *, int ,int ,int *);
int main()
{
	int i,j,m1,n1,m2,n2;
	scanf("%d%d%d%d",&m1,&n1,&m2,&n2);
	int A[m1][n1];
	int B[m2][n2];
	for(i=0;i<m1;i++)  /*the matrices which are to be multiplied are taken in 2 2-D arrays using two for loops*/
	{
		for(j=0;j<n1;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
	for(i=0;i<m2;i++)
	{
		for(j=0;j<n2;j++)
		{
			scanf("%d",&B[i][j]);
		}
	}
	if(n1!=m2)  /* If matrices are not multiplicable then "NOT POSSIBLE" is printed*/
		printf("NOT POSSIBLE");
	else if(n1==m2)
	{
		multiply(m1,n1,*A,m2,n2,*B);
	}
	return 0;
}
void multiply(int m1,int n1,int *A,int m2,int n2,int *B)
{
	int i,j;
	int BT[n2][m2];
	int C[m1][n2];
	int a[m1][n1];
	for(i=0;i<m1;i++)
	{
		for(j=0;j<n1;j++)
		{
			a[i][j]=*(A+i*n1+j);
		}
	}
	for(i=0;i<n2;i++) /*BT is as a another matrix it is a transpose of Bi.e2nd matrix to be multiplied*/
	{
		for(j=0;j<m2;j++)
		{
			BT[i][j]=*(B+i+j*n2);
		}
	}
	for(i=0;i<m1;i++)
	{
		for(j=0;j<n2;j++)
		{
			C[i][j]=SOParrays(a[i],n1,BT[j]);
		}
	}
	for(i=0;i<m1;i++)
	{
		for(j=0;j<n2;j++)
		{
			printf("%d ",C[i][j]);
		}
		printf("\n");
	}
	
	return ;
}

/* The function SOParrays find the sum of products of elemts of the two arrays respectively*/

int SOParrays(int *A,int n1,int *BT)
{
	int i,k=0;
	for(i=0;i<n1;i++)
	{
		k+=(*(A+i)) * (*(BT+i));
	}
	return k;
}



