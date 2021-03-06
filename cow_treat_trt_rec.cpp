#include <iostream>
#include <cstdio>
#include <cstring>
int N;
using namespace std;

int max(int a ,int b ) { if (a>b) return a; else return b;}

int maximize_revenue(int num,int left,int right,int *values,int **solutions[])
	{
		int age=N-num+1;
		if (solutions[num][left][right]!=-1) return solutions[num][left][right];
		printf("%d %d \n",left,right);
		if (num==0) return 0;
		else
			{
			int cal=max(values[left]*age+maximize_revenue(num-1,left+1,right,values,solutions),values[right]*age+maximize_revenue(num-1,left,right-1,values,solutions));
			solutions[num][left][right]=cal;
			return cal;
			}
	}



int main()
	{
	int num,i;	
	scanf("%d",&num);
	N=num;
	int values[num];
	for(i=0;i<num;i++) scanf("%d",&values[i]);
	int solutions[num+1][num+1][num+1];
	memset(solutions,-1,sizeof(int)*(num+1)*(num+1)*(num+1));
	solutions[5][0][4]=1;
	printf("%d\n",maximize_revenue(num,0,num-1,values,(int ***)solutions));	
	}
