#include <iostream>
#include <cstdio>

#define ELEMENTS 12

int array[ELEMENTS+1];

int count=0;

void find_permutations(int k)
	{
	int i;
	if (k==0)  count++;
	else if (k<0) return ;
	else
		{
		for (i=1;array[i]<=k;i++)
			{
				find_permutations(k-i);
			}
		}
	}



int main()
	{
	int n,k,i,j;
	scanf("%d",&n);
	for (i=1;i<=n;i++) array[i]=i*(i-1)/2;
	//for (i=0;i<=n;i++) printf("%d ",array[i]);
	scanf("%d",&k);
	find_permutations(k);
	printf("%d ",count);
	}
