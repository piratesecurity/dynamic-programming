#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

#define MAX 2010
char  string1[MAX],string2[MAX];
int solutions[MAX+1][MAX+1];

int min(int a ,int b,int c)
	{
	if (a<b) 
		{
		if(a<c)
			return a;
		else return c;
		}
	else
		{
		if (b<c) 
			return b;
		else return c;
		}
	}


int edit_distance()
	{
	int strlen1,strlen2;
	strlen1=strlen(string1);
	strlen2=strlen(string2);	
	int i,j;
	memset(solutions,MAX,(strlen1+1)*(strlen2+1)*sizeof(int));
	solutions[0][0]=0;
	for (i=0;i<=strlen1;i++) solutions[i][0]=i;
	for (i=0;i<=strlen2;i++) solutions[0][i]=i;
	for (i=1;i<=strlen1;i++)
		{
		for (j=1;j<=strlen2;j++)
			{
				if (string1[i-1]==string2[j-1])
					{		
					solutions[i][j]=solutions[i-1][j-1];				
					}
				else 
					{
					solutions[i][j]=min(1+solutions[i-1][j],1+solutions[i][j-1],1+solutions[i-1][j-1]);	
					}
			}			
	
		}
		return solutions[strlen1][strlen2];
	}





int main()
	{
	int num_tests,i,max_len;
	scanf("%d",&num_tests);
	for (i=0;i<num_tests;i++)	
		{	
		scanf("%s",string1);
		scanf("%s",string2);			
		printf("%d\n",edit_distance());
		}
	
	}
