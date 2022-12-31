#include<stdio.h>//insertion sort

int main()

{
     int i ,arr[15],n,key;
    printf("enter no of elements");
    scanf("%d",&n);
    printf("enter the array");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("before sorting array is \n");
     for(i=0;i<n;i++)
    {   
        
        printf("%d",arr[i]);
        printf("\t");
    }
    sorting(arr,n);
    printf("after sorting array is \n");
     for(i=0;i<n;i++)
    {   
        
        printf("%d",arr[i]);
        printf("\t");
    }
    return 0;
}
int sorting(int arr[],int a)
{
   for(int i=1;i<a;i++)
   {
   int var=arr[i];
   int j=i-1;
   while(j>=0&&var<arr[j])
    {
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=var;
   }
}