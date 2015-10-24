#include <iostream>
#include <cstdio>
#include <cstring>
#define INFY 10000

int max(int a, int b) { return (a > b)? a : b; }

void knapSack(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];
   int V[n+1][W+1];
 
   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
			{
               K[i][w]= 0;
			   V[i][w]= 0;
			}

           else if (wt[i-1] <= w)
				{
				int a=val[i-1] + K[i-1][w-wt[i-1]],b= K[i-1][w];
                if (a>b)
					{
					K[i][w]=a;
					V[i][w]=wt[i-1]+V[i-1][w-wt[i-1]];					
					}
				else
					{
					K[i][w]=b;
					V[i][w]=V[i-1][w];
					}
				}
           else
				{
                K[i][w] = K[i-1][w];
				V[i][w] = V[i-1][w];
				}
       }
   }
   for (i=0;i<=w;i++) printf("%d ",K[n][i]);
   printf("\n");
   printf("%d %d\n",V[n][W],K[n][w]);
}


int main()
	{
	int budget,num_parties,i;
	scanf("%d%d",&budget,&num_parties);
	while (budget!=0 && num_parties!=0)
		{
		int party_prices[num_parties],party_funs[num_parties];
		for (i=0;i<num_parties;i++) scanf("%d%d",&party_prices[i],&party_funs[i]);				
		knapSack(budget,party_prices,party_funs,num_parties);	
		//for (i=0;i<num_parties;i++) printf("%d %d \n",party_prices[i],party_funs[i]);
		//printf("\n\n\n");
		scanf("%d%d",&budget,&num_parties);
		}
	return 0;
	}
