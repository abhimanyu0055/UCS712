#include<iostream>
using namespace std;
void merge(int arr[],int left,int mid,int right)
{
    int *merged= new int[right-left+1];
    int p=left;
    int q=mid+1;
    int x=0;
    while(p<=mid && q<=right)
    {
        if(arr[p]<arr[q])
        {
            merged[x++]=arr[p++];
        }
        else
        {
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
}
void mergesort(int arr[],int left,int right)
{
     if(left<right)
     {
        int mid= left + (right-left)/2;
        mergesort(arr,left,mid) ;
        mergesort(arr,mid+1,right);
        merge(arr,left,mid,right);
     }
}
int main()
{
    int a[6]= { 12, 11, 13, 5, 6, 7 } ;
    mergesort(a,0,5);
    for(int i=0;i<6;i++)
    {
        cout<<a[i]<<"\t";
    }
}