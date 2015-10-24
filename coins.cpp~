#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 1000000

long long int max(long long int a,long long int b) {if (a>b) return a; else return b;}

long long solutions[N+1];
int main()
	{
	long long int num;
	while(scanf("%lld",&num)==1)
		{
		long long int i;
		solutions[0]=0;
		for (i=1;i<=num;i++)
			{
			solutions[i]=max(i,solutions[i/2]+solutions[i/3]+solutions[i/4]);
			}
		printf("%lld\n",solutions[num]);
		}

	return 0;
	}
