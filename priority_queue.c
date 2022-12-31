#include<stdio.h>
struct p_q{
    int id;
    int key;
}pq[20];
int us=0;

void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void max_heapify(int n,int i)
{
   int large=i;
   int lc=2*i+1;
   int rc=2*i+2;
   if(lc<n&&pq[lc].key>pq[large].key)
   {
    large=lc;
   }
   if(rc<n&&pq[rc].key>pq[large].key)
   {
    large=rc;
   }
   if(large!=i)
   {
     swap(&pq[i].key,&pq[large].key);
     swap(&pq[i].id,&pq[large].id);
     max_heapify(n,large);
   }
}
  struct p_q find_max()
  {
    return pq[0];
  }
  struct p_q delete_max()
  {
    struct p_q temp=pq[0];
    us--;
    pq[0].id=pq[us].id;
    pq[0].key=pq[us].key;
    max_heapify(us,0);
    return temp;
  }

   void increase_key(int i,int key)
   {
     if(key<pq[i].key)
     {
        return;
     }
     else{
        pq[i].key=key;
        while(i>0&&key>pq[(i-1)/2].key)
        {   
            swap(&pq[i].key,&pq[(i-1)/2].key);
            swap(&pq[i].id,&pq[(i-1)/2].id);
            i=(i-1)/2;
        }
     }
   }

   void insertkey(int id,int key)
   {
    us=us+1;
    if(us==1)
     {
        pq[us-1].key=key;
        pq[us-1].id=id;

     }
     else{
        pq[us-1].id=id;
        pq[us-1].key=-99999;
        increase_key(us-1,key);
     }
   }

int main()
{
   
   insertkey(3,7);
   insertkey(4,9);
   insertkey(5,1);
   insertkey(9,8);
   for(int i=0;i<us;i++)
   {
    printf(" %d  %d  ",pq[i].id ,pq[i].key);
   }
   printf("\n");
   struct p_q ans=find_max();
   printf("%d %d",ans.id,ans.key);
   struct p_q tmp=delete_max();
   printf("\n%d %d",tmp.id,tmp.key);
    struct p_q ans2=find_max();
   printf("\n%d %d",ans2.id,ans2.key);
    return 0;
}