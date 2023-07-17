#include <stdio.h>
void MinMax(int a[],int i,int j,int *min,int *max)
{
    int n;
    int min1=0;
    int max1=0;
    if(i==j)
    {
        *max=*min=a[i];
    }
    else if(i==j-1)
    {
        if(a[i]<a[j])
        {
            *min=a[i];
            *max=a[j];
        }
        else
        {
            *min=a[j];
            *max=a[i];
        }
    }
    else
    {
        int mid;
        mid=(i+j)/2;
        MinMax(a,i,mid,min,max);
        MinMax(a,mid+1,j,&min1,&max1);
        if(*max<max1)
        {
            *max=max1;
        }
        if(*min>min1)
        {
            *min=min1;
        }
    }
}
int main()
{
    int n;
    int a[50];
    int min=0;
    int max=0;
    printf("Enter the no.of elements:");
    scanf("%d",&n);
    int i;
    printf("Enter the elements:");
    for(i=0;i<n;i++)
    {
    	printf("Enter Element a[%d]:",i);
        scanf("%d",&a[i]);
    }
    MinMax(a,0,n-1,&min,&max);
    printf("Minimum number:%d\nMaximum Number:%d",min,max);
}

