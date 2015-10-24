#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

#define MAX 100
int solutions[MAX][MAX];
void print_sequences(char *cur_seq,int rem,int row,int column,char *string1,char *string2)
	{
		printf("%d %d %d  \n",rem,row,column);
		if (rem==0)
			{
			
			printf("%s\n",cur_seq);
			return;
			}
		if (string1[row-1]==string2[column-1])
			{
				printf("char assigned %d %c\n",rem-1,string1[row-1]);
				cur_seq[rem-1]=string1[row];
				return print_sequences(cur_seq,rem-1,row-1,column-1,string1,string2);
			}
		if (solutions[row][column-1]>=solutions[row-1][column])
			{
				if ((column-1)>=0)
				print_sequences(cur_seq,rem,row,column-1,string1,string2);
				
			}
		if (solutions[row][column-1]<=solutions[row-1][column])
			{
				if ((row-1)>=0)
				print_sequences(cur_seq,rem,row-1,column,string1,string2);
				
			}
		
		
	}





void lcs(char * string1, char *string2)
	{
	int strlen1,strlen2;
	strlen1=strlen(string1);
	strlen2=strlen(string2);
	
	int i,j;
	memset(solutions,0,(strlen1+1)*(strlen2+1)*sizeof(int));
	printf("Longest Common Subsequence is :");
	int lcs_sol[strlen1];
	memset(lcs_sol,0,sizeof(int)*strlen1);
	for (i=1;i<=strlen1;i++)
		{
		for (j=1;j<=strlen2;j++)
			{
				if (string1[i-1]==string2[j-1])
					{
					printf("%d %d %c\n",i,j,string1[i-1]);
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
	printf(" Longest one length :%d \n",solutions[strlen1][strlen2]);
	for (i=0;i<=strlen1;i++)
		{
		for (j=0;j<=strlen2;j++)
			printf("%d ",solutions[i][j]);
		printf("\n");	
		}
	printf("comlete  \n\n");
	char sample[solutions[strlen1][strlen2]+1];
	sample[solutions[strlen1][strlen2]]='\0';
	print_sequences(sample,solutions[strlen1][strlen2],strlen1,strlen2,string1,string2);
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
	lcs(string1,string2);
	
	}
