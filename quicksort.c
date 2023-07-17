#include <stdio.h>  
int partition (int a[], int f, int l)  
{  
    int i,j,p,temp;
    p=a[l]; 
    i=(f-1);  
  
    for (j=f;j<=l-1;j++)  
    {   
        if (a[j]<p)  
        {  
            i++; 
            temp = a[i];  
            a[i] = a[j];  
            a[j] = temp;  
        }  
    }  
    temp=a[i+1];  
    a[i+1]=a[l];  
    a[l]=temp;  
    return (i+1);  
}  

void quicksort(int a[], int f, int l)
{  
    int m;
    if (f<l)  
    {  
        m=partition(a,f,l); 
        quicksort(a,f,m-1);  
        quicksort(a,m+1,l);  
    }  
}   

int main()  
{  
    int a[100],n,i;
    printf("QUICK SORT \n");
    printf("Enter n: ");
    scanf("%d",&n);
	printf("The elements are: \n");
	for (i=0;i<n;i++)
	  scanf("%d",&a[i]);  
    quicksort(a, 0, n-1); 
	printf("\n");
    printf("After sorting: \n");    
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);
}  
