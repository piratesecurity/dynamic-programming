#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int lcs(char * string1, char *string2)
	{
	int strlen1,strlen2;
	strlen1=strlen(string1);
	strlen2=strlen(string2);
	
	int solutions[strlen1+1][strlen2+1],i,j;
	memset(solutions,0,(strlen1+1)*(strlen2+1)*sizeof(int));
	printf("Longest Common Subsequence is :");
	int lcs_sol[strlen1];
	memset(lcs_sol,0,sizeof(int)*strlen1);
	for (i=1;i<=strlen1;i++)
		{
		for (j=1;j<=strlen2;j++)
			{
				if (string1[i]==string2[j])
					{
					solutions[i][j]=1+solutions[i-1][j-1];
					lcs_sol[i]=1;
					
					}
				else 
					if (solutions[i-1][j]>solutions[i][j-1])
						{
						solutions[i][j]=solutions[i-1][j];
											
						}
					else
						{
						solutions[i][j]=solutions[i][j-1];
					
						}
			}
		}	

	return solutions[strlen1][strlen2];
	}


int max(int a ,int b)
	{
	if (a>b) return a;
	else return b;
	}

int main()
	{
	char  string1[1000],string2[1000];
	scanf("%s",string1);
	scanf("%s",string2);
	printf(" Answer is :%d\n",lcs(string1,string2));
	
	}
