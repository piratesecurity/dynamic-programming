#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

string string1,string2;
long long int strlen1,strlen2;
long long int lcs()
	{	
	strlen1=string1.size();
	strlen2=string2.size();
	long long int solutions[strlen1+1][strlen2+1],i,j;
	for (i=0;i<=strlen1;i++) for (j=0;j<=strlen2;j++) solutions[i][j]=0;
	long long int lcs_sol[strlen1];
	memset(lcs_sol,0,sizeof(int)*strlen1);
	for (i=1;i<=strlen1;i++)
		{
		for (j=1;j<=strlen2;j++)
			{
				if (string1[i-1]==string2[j-1])
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

long long int max(long long int a ,long long int b)
	{
	if (a>b) return a;
	else return b;
	}

int main()
	{
	getline(cin,string1);
	getline(cin,string2);
	cout << lcs();
	return 0;
	}
