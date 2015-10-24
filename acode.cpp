#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAX 10000

char str1[MAX];
long long int len,solutions[MAX+1];
long long int global=0;

long long int explore(long long int index)
	{
	//printf("%c\n",str1[index]);
	if (solutions[index]!=0) return solutions[index];
	if (index==len|| (index==(len-1) && str1[index]!='0' )) return 1;
	long long int num1= str1[index]-48;
	char next=str1[index+1];	
	num1=num1*10+(next-48);
	if (num1>=10 && num1<=26)
		 {
		 solutions[index]=explore(index+2);
		 if (num1%10!=0)			
		 solutions[index]+=explore(index+1);
		 return solutions[index];
		 }
	
	else if (num1<10)
		{
		return 0;
		}
	else
		{
		solutions[index]=explore(index+1);
		return solutions[index];
		}
	
	
	}

int main()
	{
	
	scanf("%s",str1);
	while (!(strlen(str1)==1 && str1[0]=='0'))
		{
			memset(solutions,0,sizeof(int)*(MAX+1))	;
			len=strlen(str1);
			//printf("%lld\n",len);				
			if (global!=0) printf("\n");
			printf("%lld",explore(0));
			global++;
			scanf("%s",str1);
		}
	return 0;
	}

