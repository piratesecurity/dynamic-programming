#include <iostream>
#include <cstdio>
#include <cstring>

#define MAX 1010

using namespace std;

int global=1;
long long int values[MAX],len;


long long int max(long long int a,long long int b)
	{
	if (a>b) return a;
	else return b;	
	}

long long int find_max(int left,int right,long long int f_sum,long long int s_sum)
	{
	if (left==(right-1))
		{
		return max(values[left]+f_sum-(values[right]+s_sum),values[right]+f_sum-(values[left]+s_sum));
		}
	else
		{
		int f_left,f_right,s_left,s_right,sum_s,sum_f;
		if (values[left+1]>=values[right])
			{
			f_left=2;f_right=0;
			sum_s=values[left+1];
			}
		else
			{
			f_left=1;f_right=1;
			sum_s=values[right];
			}
		if (values[right-1]>values[left])
			{
			s_left=0;s_right=2;
			sum_f=values[right-1];
			}
		else
			{
			s_left=1;s_right=1;
			sum_f=values[left];
			}
		return max(find_max(left+f_left,right-f_right,f_sum+values[left],s_sum+sum_s),find_max(left+s_left,right-s_right,f_sum+values[right],s_sum+sum_f));
		}
	
	}

int main()
	{
	int num,i;
	scanf("%d",&num);
	while (num!=0)
		{
		memset(values,0,sizeof(int)*MAX);
		for (i=0;i<num;i++) scanf("%lld",&values[i]);
		len=num;
		printf("In game %d, the greedy strategy might lose by as many as %lld points.\n",global++,find_max(0,len-1,0,0));
		scanf("%d",&num);	
		}	
	return 0;
	}
