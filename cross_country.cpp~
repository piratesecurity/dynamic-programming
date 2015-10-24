#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#define MAX 2000
using namespace std;


int lcs(int lady_checks[],int player_checks[],int lady_count,int player_count)
	{
	int m,n;
	//printf(" lady set \n ");
	//for (m=0;m<lady_count;m++) printf(" %d ",lady_checks[m]);
	//printf("\n");
	

	//printf(" player set \n ");
	//for (n=0;n<player_count;n++) printf(" %d ",player_checks[n]);
	//printf("\n");
	int solutions[lady_count+1][player_count+1],i,j;
	for (i=0;i<=lady_count;i++) for (j=0;j<=player_count;j++) solutions[i][j]=0;
	int lcs_sol[lady_count];
	memset(lcs_sol,0,sizeof(int)*lady_count);
	for (i=1;i<=lady_count;i++)
		{
		for (j=1;j<=player_count;j++)
			{
				if (lady_checks[i-1]==player_checks[j-1])
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

	//printf("\n Solutions is : %d %d %d \n",solutions[lady_count][player_count],lady_count,player_count);

	return solutions[lady_count][player_count];
	}

int max(int a ,int b)
	{
	if (a>b) return a;
	else return b;
	}

int main()
	{
	int num_tests,i,j,k;
	scanf("%d",&num_tests);
	for (i=0;i<num_tests;i++)
		{	
		int lady_checks[MAX];
		int check_point,lady_count=0;
		scanf("%d",&check_point);
		while (check_point!=0)
			{		
									
				lady_checks[lady_count++]=check_point;
				scanf("%d",&check_point);			
			}
		
		int end_set_check=0;
		while (end_set_check==0)
			{
			int player_checks[MAX],player_count=0;
			scanf("%d",&check_point);	
			int max=0,player_points=0;		
			while (1)
				{
				if (player_count==0 && check_point==0) {end_set_check=1;printf("%d\n",max);break;}
				else
					{
					if (check_point==0)
						{
							// function call

							//printf(" set \n ");
							//for (j=0;j<player_count;j++) printf(" %d ",player_checks[j]);
							//printf("\n");
							player_points=lcs(lady_checks,player_checks,lady_count,player_count);
							if (player_points>max) max=player_points;
							player_count=0;
							
						}
					else
						{
						player_checks[player_count++]=check_point;
						}
					}
				scanf("%d",&check_point);
				}
			}
		
		}
	}
