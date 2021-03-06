#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <cstring>
#define PRICE_TABLE_LEN 10


//  Rod cut problem solution for non continuous rod length profits 

//http://www.geeksforgeeks.org/dynamic-programming-set-13-cutting-a-rod/

using namespace std;
int max(int,int);
int find_max_profit(int n,int rod_length[],int rod_profit[]);


int find_max_profit(int n,int rod_length[],int rod_profit[])
	{
	int profits[n+1],i,j,k;
	int solution[n+1];
	memset(solution,0,(n+1)*sizeof(int));
	memset(profits,0,(n+1)*sizeof(int));	
	for (i=1;i<=n;i++)
		{
		int max_profit=0,current_profit;	
		
		for (j=0;j<PRICE_TABLE_LEN;j++)
			{
			if ((i-rod_length[j])>=0)
				{
				current_profit=rod_profit[j]+profits[i-rod_length[j]];		
				//printf("%d %d  %d  \n",rod_length[j],rod_profit[j],current_profit);	
				if (max_profit<current_profit)
					{
					max_profit=current_profit;
					solution[i]=rod_length[j];
					}				
				}
			}
		
		profits[i]=max_profit;
		}
	i=n;
		//for (k=0;k<=n;k++) printf("%d ",solution[k]);
	printf("Rod Cuttings are :\n");
	while (i>0)
		{
		printf("%d ",solution[i]);
		i=i-solution[i];
		}
	
	return profits[n];
	}

int max(int a,int b)
	{
	if (a>b) return a;
	else return b;
	}

int main()
	{
	int n;
	int rod_length[PRICE_TABLE_LEN]={1,2,3,4,5,6,7,8,9,10};
	int rod_profit[PRICE_TABLE_LEN]={1,5,8,9,10,17,17,20,24,30};	
	printf("Enter rod length :");
	scanf("%d",&n);
	printf("\nMaximum Profit Obtained is  :%d\n",find_max_profit(n,rod_length,rod_profit));
	}




