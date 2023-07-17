#include<stdio.h>
#include<string.h>

char X[100],Y[100],Z[100],b[100][100],m,n;
int C[100][100];

void LCS_length()
{
	int i,j;
	
	m=strlen(X);
	n=strlen(Y);
	
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(X[i-1]==Y[j-1])
			{
				C[i][j]=C[i-1][j-1]+1;
				b[i][j]='K';
			}
			else if(C[i-1][j]>=C[i][j-1])
			{
				C[i][j]=C[i-1][j];
				b[i][j]='U';
			}
			else
			{
				C[i][j]=C[i][j-1];
				b[i][j]='L';
			}
		}
	}
}

void print_LCS(int x, int y)
{
	if((x==0) || (y==0))
		return;
	if(b[x][y]=='K')
	{
		print_LCS(x-1,y-1);
		printf("%c ",X[x-1]);
	}
	else if(b[x][y]=='U')
		print_LCS(x-1,y);
	else if(b[x][y]=='L')
		print_LCS(x,y-1);
}

int main()
{
	printf("Enter first string:\n");
	scanf("%s",X);
	printf("Enter second string:\n");
	scanf("%s",Y);

	LCS_length();
	printf("m=%d,n=%d\n",m,n);
	print_LCS(m,n);

	return 0;
}
