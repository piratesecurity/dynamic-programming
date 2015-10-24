#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 2000
char string1[MAX];
int len;
int min(int a,int b)
	{
	if (a<b) return a;
	else return b;
	}

int find_num_changes(void)
	{
	int solutions[len+1][2],i;
	solutions[0][0]=solutions[0][1]=0;
	for (i=1;i<=len;i++)
		{
		if (string1[i-1]<'a')
			{
			solutions[i][0]=solutions[i-1][1];
			solutions[i][1]=1+solutions[i-1][0];
			}
		else
			{
			solutions[i][0]=1+solutions[i-1][1];
			solutions[i][1]=solutions[i-1][0];
			}
		
		}
	return min(solutions[len][0],solutions[len][1]);
	}
int main()
	{
	while ((scanf("%s",string1))==1)
		{
		len=strlen(string1);
		printf("%d\n",find_num_changes());
		}
	
	return 0;
	}
