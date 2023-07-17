#include<stdio.h>
#define INFINITY 100000000

void print_optimal_parens(int (*s)[100], int i, int j)
{
	if(i==j)
	{
		printf("A:%d",i);
	}
	else
	{
		printf("(");
		print_optimal_parens(s,i,s[i][j]);
		printf("*");
		print_optimal_parens(s,s[i][j]+1,j);
		printf(")");
	}
}

int main()
{
	int p[25],n,i,j,k,l,q,m[100][100],s[100][100];

	printf("Enter no. of matrices:\n");
	scanf("%d",&n);
	printf("Enter the %d dimensions:\n",n+1);
	for(i=0;i<=n;i++)
		scanf("%d",&p[i]);

	for(i=1;i<=n;i++)
		m[i][i]=0;
	for(l=2;l<=n;l++)
	{
		for(i=1;i<=n-l+1;i++)
		{
			j=i+l-1;
			m[i][j]=INFINITY;
			for(k=i;k<=j-1;k++)
			{
				q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
	print_optimal_parens(s,1,n);

	return 0;
}
