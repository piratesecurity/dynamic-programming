#include <iostream>
#include <cstdio>
#include <cstring>

#define MAX 6200

char str[MAX];
int len;

int solutions[MAX][MAX];

int min(int a,int b)
	{
	if (a<b) return a;
	else return b;
	}

int find_min(int left,int right)
	{
	if (solutions[left][right]!=-1) return solutions[left][right];
	if ((left==right) ||(left==(right+1)))
		{
		solutions[left][right]=0;
		return solutions[left][right];
		}
	if (str[left]==str[right])
		{ 
		solutions[left][right]=find_min(left+1,right-1);
		return solutions[left][right];
		}
	else
		{
		solutions[left][right]= min(1+find_min(left+1,right),1+find_min(left,right-1));
		return solutions[left][right];
		}
	}


int main()
	{
	int num_tests,i;
	scanf("%d",&num_tests);
	for (i=0;i<num_tests;i++)
		{
		memset(solutions,-1,sizeof(int)*MAX*MAX);
		scanf("%s",str);
		len=strlen(str);		
		printf("%d\n",find_min(0,len-1));
		}	
	}
