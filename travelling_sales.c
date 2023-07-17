#include<stdio.h>
#define INF 1000

int n,seq[20],used[20],city[20][20],fin[20],min=INF;

void display()
{
	int i,j,l,m,sum=0;

	seq[0]=0;

	for(i=0;i<n;i++)
	{
		l=seq[i];
		if(i==n-1)
			m=seq[0];
		else
			m=seq[i+1];
		sum=sum+city[l][m];
	}

	if(min>sum)
	{
		min=sum;
		for(i=0;i<n;i++)
			fin[i]=seq[i];		
	}
}

int Tsp(int nxt)
{
	int i;
	if(nxt<n)
	{
		for(i=1;i<n;i++)
		{
			if(used[i]!=1)
			{
				seq[nxt]=i;
				used[i]=1;
				Tsp(nxt+1);
				used[i]=0;
			}
				
		}
	}
	else
		display();
}

int main()
{
	int i,j;
	printf("Enter the no. of cities:\n");
	scanf("%d",&n);
	printf("Enter the distances between any two cities:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&city[i][j]);
	}

	Tsp(1);

	printf("The cities route is:");
	for(i=0;i<n;i++)
		printf("%d-->",fin[i]+1);
	printf("1");
	return 0;
}

