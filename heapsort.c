#include<stdio.h>

void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void max_heapify(int arr[],int n,int i)
{
   int large=i;
   int lc=2*i+1;
   int rc=2*i+2;
   if(lc<n&&arr[lc]>arr[large])
   {
    large=lc;
   }
   if(rc<n&&arr[rc]>arr[large])
   {
    large=rc;
   }
   if(large!=i)
   {
     swap(&arr[i],&arr[large]);
     max_heapify(arr,n,large);
   }
}
void buildheap(int arr[],int n)
{
   for(int i=(n/2)-1;i>=0;i--)
   {
     max_heapify(arr,n,i);
   }
}


void heapsort(int arr[],int n)
{
   buildheap(arr,n);
   for(int i=n-1;i>=0;i--)
   { 
     swap(&arr[0],&arr[i]);
     max_heapify(arr,i,0);
   }

}

  
int main()
{
    int n;
    printf("Enter number of elements in an array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i <n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Before sorting elements are:\n");
     for (int i = 0; i < n; i++)
    {
        printf("%d \t",arr[i]);
    }
    heapsort(arr,n);
    printf("\n");
    printf("After sorting elements are:\n");
    
    for (int i = 0; i <n; i++)
    {
        printf("%d \t",arr[i]);
    }
    return 0;
  
}