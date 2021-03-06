#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 100010

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


char string1[MAX];
int len;
long long int min(long long int a,long long int b)
	{
	if (a<b) return a;
	else return b;
	}

long long int find_num_changes(void)
	{
	long long int solutions[len+1][2],i;
	solutions[0][0]=solutions[0][1]=0;
	for (i=1;i<=len;i++)
		{
		if (string1[i-1]<'-')
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
	int num_tests=read_int(),i;	
	for (i=0;i<num_tests;i++)	
		{
		scanf("%s",string1);
		len=strlen(string1);
		printf("%lld\n",find_num_changes());
		}	
	return 0;
	}
