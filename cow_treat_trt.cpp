#include <iostream>
#include <cstdio>

#

using namespace std;

int max(int a ,int b ) { if (a>b) return a; else return b;}

void maximize_revenue(int num,int *values)
	{
	int left_max,right_max,i,j;
	right_max=num/2;left_max=right_max+num%2;
	int solutions[left_max][right_max];
	solutions[0][0]=0;
	int age;
	for (i=0;i<left_max;i++)
		{
		for (j=0;j<right_max;j++)
			{
			int use_left=0,use_right=0;
			age=num-(i+j)+1;
			if (i!=0)
				use_left=(age*values[i-1])+solutions[i-1][j];
			if (j!=0)
				use_right=(age*values[num-j-1])+solutions[i][j-1];
			if (use_left>use_right)
				solutions[i][j]=use_left;
			else
				solutions[i][j]=use_right;
			}
		}
	for (i=0;i<left_max;i++) 
		{
		for (j=0;j<right_max;j++)
			printf("%d\t",solutions[i][j]);
		printf("\n");
		}
	
	printf("%d\n",solutions[left_max-1][right_max-1]);
	}



int main()
	{
	int num,i;
	scanf("%d",&num);
	int values[num];
	for(i=0;i<num;i++) scanf("%d",&values[i]);
	maximize_revenue(num,values);	
	}
