
#include<stdio.h>
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectionsort(int arr[],int a,int b)
{
    for(int i=a;i<b-1;i++)
    {
        int min=i;
        for(int j=i+1;j<b;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }

        }
        swap(&arr[i],&arr[min]);
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
    selectionsort(arr,0,n);
    printf("\n");
    printf("After sorting elements are:\n");
    
    for (int i = 0; i <n; i++)
    {
        printf("%d \t",arr[i]);
    }
    return 0;
  
}