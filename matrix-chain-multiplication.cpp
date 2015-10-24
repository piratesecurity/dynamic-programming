/*
Matrix chain multiplicaion solution using dynamic programming..
Top Down approach
Tabular method
solutions[i][j] represents minimum scalar multiplications for multiplying i to j matrices
*/


#include <iostream>
#include <cstdio>
#include <cstring>
#define NUM_MATRICES 3
#define INFINITE 99999



using namespace std;

int matrix_chain_mul(int orders[])
	{
	int i,j,k;	
	int solutions[NUM_MATRICES][NUM_MATRICES];
	memset(solutions,0,(NUM_MATRICES)*(NUM_MATRICES)*sizeof(int));
	
	printf("Start    End      Muls\n");

	for (i=NUM_MATRICES-1;i>=0;i--)
		{
		for (j=i;j<=NUM_MATRICES-1;j++)
			{
			int min=INFINITE,num_muls;
			for (k=i;k<j;k++)
				{				
				num_muls=solutions[i][k]+solutions[k+1][j]+orders[i]*orders[k+1]*orders[j+1];						
				if (min>num_muls)
					min=num_muls;			
					}
			
			if (min!=INFINITE)
				{
				solutions[i][j]=min;
				printf("%d\t%d\t%d\t\n",i,j,min);
				}
			}
		}
	
	/* for (i=0;i<NUM_MATRICES;i++)
		{
		for (j=0;j<NUM_MATRICES;j++)
			{
				printf("%d ",solutions[i][j]);
			}
		printf("\n");
		}
	
	*/
	return solutions[0][NUM_MATRICES-1];
	}





int main()
	{
	int orders[NUM_MATRICES+1]={10,100,5,50};
	printf("\n Answer is :%d\n",matrix_chain_mul(orders));
	return 0;
	}
