#include<stdio.h>
int findmaxm(int arr[],int n)
{
   int maxm=arr[0];
   for(int i=1;i<n;i++)
   {
    if(arr[i]>maxm)
    {
        maxm=arr[i];
    }
   }
   return maxm;

}
void countingsort(int arr[],int n,int pos)
{
  int maxm=(arr[0]/pos)%10;
    for(int i=1;i<n;i++)
    {
        if((arr[i]/pos)%10>maxm)
        {
            maxm=(arr[i]/pos)%10;
        }
    }
    int temp[maxm+5];
    for(int i=0;i<=maxm;i++)
    {
        temp[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        int var=(arr[i]/pos)%10;
        temp[var]++;

    }
    for(int i=1;i<=maxm;i++)
    {
        temp[i]=temp[i]+temp[i-1];
    }
    int output[20];
    for(int i=n-1;i>=0;i--)
    {
         output[temp[(arr[i]/pos)%10]-1]=arr[i];
         temp[(arr[i]/pos)%10]--;
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=output[i];
    }
}

void radixsort(int arr[],int n)
{
   int maxm=findmaxm(arr,n);
   for(int pos=1;maxm/pos>0;pos=pos*10)
   {
    countingsort(arr,n,pos);
   }
}

int main()
{
    int n;
    printf("Enter number of elements in an array\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Before sorting elements are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d \t", arr[i]);
    }
    radixsort(arr, n);
    printf("\n");
    printf("After sorting elements are:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d \t", arr[i]);
    }
    return 0;
}