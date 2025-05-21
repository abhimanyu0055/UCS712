#include<iostream>
using namespace std;
int partition(int arr[],int left,int right)
{
    int pivot= arr[right];
    int i= left-1;
    for(int j=left;j<right;j++)
    {
         if(arr[j]<pivot)
         {
            i++;
            swap(arr[j],arr[i]);
         }
    }
    i++;
    swap(arr[i],arr[right]);
    return i;
}
void quicksort(int arr[],int left,int right)
{
    if(left<right)
    {
    int pidx= partition(arr,left,right);
    quicksort(arr,left,pidx-1);
    quicksort(arr,pidx+1,right);
    }
}
int main()
{
    int a[5]={ 4, 2, 6, 9, 2 };
    quicksort(a,0,4);
    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<"\t";
    }
}