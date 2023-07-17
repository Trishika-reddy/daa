#include <stdio.h>    
void merge(int a[], int f, int m, int l)    
{    
    int i, j, k;  
    int x= m-f+1;    
    int y= l-m;    
      
    int L[x],R[y]; 
    for (i = 0; i<x; i++)    
    L[i] = a[f+i];    
    for (j = 0; j < y; j++)    
    R[j] = a[m+1+j];    
      
    i = 0;
    j = 0;  
    k = f;  
      
    while (i<x && j<y)    
    {    
        if(L[i]<=R[j])    
        {    
            a[k]=L[i];    
            i++;    
        }    
        else    
        {    
            a[k] = R[j];    
            j++;    
        }    
        k++;    
    }    
    while (i<x)    
    {    
        a[k]=L[i];    
        i++;    
        k++;    
    }    
      
    while (j<y)    
    {    
        a[k]=R[j];    
        j++;    
        k++;    
    }    
}    
  
void mergesort(int a[], int f, int l)  
{  
    if (f<l)   
    {  
        int m= (f+l)/2;  
        mergesort(a,f,m);  
        mergesort(a,m+1,l);  
        merge(a,f,m,l);  
    }  
}  

void display(int a[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);   
}

int main()  
{  
    int a[25],n,i;
    printf("Enter n: ");
    scanf("%d",&n);
	printf("The elements are: \n");
	for (i=0;i<n;i++)
	  scanf("%d",&a[i]);
    printf("Before sorting: \n");  
    display(a,n);  
    printf("\n");
    mergesort(a,0,n-1);  
    printf("After sorting: \n");  
    display(a,n);  
    return 0;  
}
