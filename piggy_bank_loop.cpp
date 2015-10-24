#include <iostream>
#include <cstdio>
#include <cstring>
#define MIN 1000000

int minimum(int a ,int b)
	{
		if (a>b) return b;
		else return a;
	}



int main()
	{
	int num_tests,pb_wt,no_coins,i,j,k;
	scanf("%d",&num_tests);
	int min=MIN;
	for (k=0;k<num_tests;k++)
	{		
		
		int empty,full;
		scanf("%d",&empty);
		scanf("%d",&full);
		pb_wt=full-empty;
		int solutions[pb_wt+1];
		for (i=0;i<=pb_wt;i++) solutions[i]=-1;
		solutions[0]=0;
		scanf("%d",&no_coins);
		int measure[no_coins],weights[no_coins];
		for (i=0;i<no_coins;i++)
			{
			scanf("%d",&measure[i]);
			scanf("%d",&weights[i]);
			}
		for(i=1;i<=pb_wt;i++)
			{
			min=MIN;
			for (j=0;j<no_coins;j++)
				{
					if ((i-weights[j]>=0)&&(solutions[i-weights[j]]!=-1))
						{
						min=minimum(min,measure[j]+solutions[i-weights[j]]);
						}
				
				}
			if (min!=MIN)
				solutions[i]=min;
			}
		if (k!=0) printf("\n");
		if (min==MIN) printf("This is impossible.");
		else
			printf("The minimum amount of money in the piggy-bank is %d.",solutions[pb_wt]);	
	}
	}
