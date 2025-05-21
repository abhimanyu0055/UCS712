#include<iostream>
using namespace std;

bool binarySearch(int arr[],int k,int n)
{
    int low=0;
    int high=n-1;
    while(low<=high)
    {
        int mid= (low+high)/2;
        if (arr[mid]==k)
        {
            return true;
        }
        else if(arr[mid]<k)
        {
            low= mid+1;
        }
        else
        {
            high= mid-1;
        }
    }
    return false;
}
int main()
{
    int a[5]={12,32,44,69,97};
    if(binarySearch(a,2,5))
    {
        cout<<"found";
    }
    else
    cout<<"not found";
}