#include<iostream>
using namespace std;
int merge(int arr[],int left,int mid,int right)
{
    int *merged= new int[right-left+1];
    int p=left;
    int q=mid+1;
    int x=0;
    int count=0;
    while(p<=mid && q<=right)
    {
        if(arr[p]<=arr[q])
        {
            merged[x++]=arr[p++];
        }
        else
        {
            count+= mid-p+1;
            merged[x++]=arr[q++];
        }
    }
    while(p<=mid)
    {
         merged[x++]=arr[p++];
    }
    while(q<=right)
    {
          merged[x++]=arr[q++];
    }
    for(int i=0;i<right-left+1;i++)
    {
        arr[i+left]=merged[i];
    }
    delete[] merged;
    return count;
}
int mergesort(int arr[],int left,int right)
{
     if(left>=right)
     return 0;

        int count=0;
        int mid= left + (right-left)/2;
       count+= mergesort(arr,left,mid) ;
       count+= mergesort(arr,mid+1,right);
       count+= merge(arr,left,mid,right);
        return count;
     
    
}
int main()
{
    int a[6]= { 12, 11, 13, 5, 6, 7 } ;
   int x= mergesort(a,0,5);
    // for(int i=0;i<6;i++)
    // {
    //     cout<<a[i]<<"\t";
    // }
    cout<<x;
}