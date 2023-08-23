#include<stdio.h>
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int a[5],int l,int u)
{
	int start=l,end=u,pivot=a[l];
	while(start<end)
	{
		while(a[start]<=pivot)
		{
			start++;
		}
		while(a[end]>pivot)
		{
			end--;
		}
		if(start<end)
		{
			swap(&a[start],&a[end]);
		}
	}
	swap(&a[l],&a[end]);
	return end;
}
void qsort(int a[5],int l,int u)
{
	if(l<u)
	{
		int c=partition(a,l,u);
		qsort(a,l,c-1);
		qsort(a,c+1,u);
	}
}
int main()
{
	int a[5]={4,5,1,2,3},i;
	qsort(a,0,4);
	for(i=0;i<5;i++)
	{
		printf("%3d",a[i]);
	}
}
