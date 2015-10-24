#include <iostream>
#include <cstdio>

int combinations(int,int);
int factorial(int);

int bit_sum(int n)
	{
	int i,sum=0,comb;
	for (i=0;i<=n;i++)
		{
		comb=combinations(n,i);
		sum=sum+comb*comb;
		}
	printf(" Sum :%d\n",sum);
	return 0;
	}

int combinations(int n,int r)
	{
		return (factorial(n)/(factorial(n-r)*factorial(r)));
	}

int factorial(int n)
	{
	if (n<=0) return 1;
	else return n*factorial(n-1);
	}

int main()
	{
	int num;
	scanf("%d",&num);
	bit_sum(num);	
	
	}
