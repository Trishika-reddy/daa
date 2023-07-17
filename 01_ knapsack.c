#include<stdio.h>

int n, W[100],P[100],x[100],wt,m;

int main()
{
	int i,B[100][100];

	printf("Enter the no. of weights:\n");
	scanf("%d",&n);
	printf("Enter the capacity of Knapsack:\n");
	scanf("%d",&m);
	printf("Enter the weights:\n");
	for(i=1;i<=n;i++)
		scanf("%d",&W[i]);
	printf("Enter the profits:\n");
	for(i=1;i<=n;i++)
		scanf("%d",&P[i]);
	for(i=1;i<=n;i++)
		B[i][0]=0;
	for(wt=0;wt<=m;wt++)
		B[0][wt]=0;
	wt=0;
	for(i=1;i<=n;i++)
	{
		for(wt=0;wt<=m;wt++)
		{
			if(wt>=W[i])
			{
				if(P[i] + B[i-1][wt-W[i]] >= B[i-1][wt])
					B[i][wt] = P[i] + B[i-1][wt-W[i]];
				else
					B[i][wt] = B[i-1][wt];					
			}
			else
				B[i][wt] = B[i-1][wt];
		}
	}
	wt=m;
	for(i=n;i>=1;i--)
	{
		if(B[i][wt]!=B[i-1][wt])
		{
			x[i] = 1;
			wt=wt-W[i];
		}
		else
			x[i] = 0;	
	}
	
	for(i=1;i<=n;i++)
		printf("%d ",x[i]);
		
	return 0;
}
