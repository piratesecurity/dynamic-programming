#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;


#define gc getchar_unlocked


int read_int() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}

int lcs(int n_arr[], int m_arr[],int len1,int len2)
	{
	int solutions[len1+1][len2+1],i,j;
	memset(solutions,0,(len1+1)*(len2+1)*sizeof(int));
	printf("Longest %d %d :",len1,len2);
	int lcs_sol[len1];
	memset(lcs_sol,0,sizeof(int)*len1);
	for (i=1;i<=len1;i++)
		{
		for (j=1;j<=len2;j++)
			{
				if (n_arr[i]==m_arr[j])
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

	return solutions[len1][len2];
	}


int max(int a ,int b)
	{
	if (a>b) return a;
	else return b;
	}

int main()
	{
	int n=read_int(),m=read_int(),i;
	int n_arr[n],m_arr[m];
	for (i=0;i<n;i++) n_arr[i]=read_int();
	for (i=0;i<m;i++) m_arr[i]=read_int();	
	printf("%d",lcs(n_arr,m_arr,n,m)+1);
	
	}
