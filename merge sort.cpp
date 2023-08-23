#include<stdio.h>
void merge(int a[6],int l,int m,int h)
{
	int i,j,k,b[20],r;
	i=l;
	j=m+1;
	k=l;
	while((i<=m)&&(j<=h))
	{
		if (a[i]<a[j])
		{
			b[k]=a[i];
			i++;
		}
		else
		{
			b[k]=a[j];
			j++;
		}
		k++;
	}
	if(i<=m)
	{
		for(r=i;r<=m;r++)
		{
			b[k]=a[r];
			k++;
		}
	}
	else
	{
		for(r=i;r<=h;r++)
		{
			b[k]=a[r];
			k++;
		}
	}
	for(k=l;k<=h;k++)
	{
		a[k]=b[k];
	}
}
void msort(int a[6],int l,int h)
{
	int m;
	if(l<h)
	{
		m=(l+h)/2;
		msort(a,l,m);
		msort(a,m+1,h);
		merge(a,l,m,h);
	}
}
int main()
{
	int i,a[6]={6,7,8,1,2,3};
	printf("Unsorted Array:");
	for(i=0;i<6;i++)
	{
		printf("%3d",a[i]);
	}
	msort(a,0,5);
	printf("\nSorted Array using merge sort:");
	for(i=0;i<6;i++)
	{
		printf("%3d",a[i]);
	}
}
