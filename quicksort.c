#include<stdio.h>

void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[],int x,int y)
{
    int pivot=arr[y];
    int j=x-1;
    for(int i=x;i<y;i++)
    {
        if(arr[i]<pivot)
        {
            j++;
            swap(&arr[j],&arr[i]);
        }
    }
    swap(&arr[j+1],&arr[y]);
    return j+1;

}



void quicksort(int arr[],int a,int b)
{    
   if(a<b)
   {
     int q=partition(arr,a,b);
     quicksort(arr,a,q-1);
     quicksort(arr,q+1,b);
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
    quicksort(arr,0,n-1);
    printf("\n");
    printf("After sorting elements are:\n");
    
    for (int i = 0; i <n; i++)
    {
        printf("%d \t",arr[i]);
    }
    return 0;
  
}