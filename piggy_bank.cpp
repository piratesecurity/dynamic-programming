#include <iostream>
#include <cstdio>
#define MIN 1000000

int minimum(int a ,int b)
	{
		if (a>b) return b;
		else return a;
	}

int piggy_bank(int pb_wt,int measure[],int weights[],int no_coins)
	{
	int i,min=MIN;
	
	if (pb_wt!=0) 
		{
		for (int i=0;i<no_coins;i++)
			{
			if (pb_wt>=weights[i])
				{
					min=minimum(min,measure[i]+piggy_bank(pb_wt-weights[i],measure,weights,no_coins));
				}
			}
		if (pb_wt==0)
		return min;
		else 
		return -1;
		}
	else
		{
		return 0;
		}
	

	}


int main()
	{
	int pb_wt,no_coins,i;
	scanf("%d",&pb_wt);
	scanf("%d",&no_coins);
	int measure[no_coins],weights[no_coins];
	for (i=0;i<no_coins;i++)
		{
		scanf("%d%d",&measure[i],&weights[i]);
		}
	printf(" \nFinal Output is :%d\n",piggy_bank(pb_wt,measure,weights,no_coins));	

	}
