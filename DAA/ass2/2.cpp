#include<iostream>
using namespace std;
int platform(int a[],int d[],int n)
{
    int i=0,j=0,p=0;
    int maxp=1;
    while(i<=n && j<=n)
    {
       if(a[i]<=d[j])
       {
        p++;
        i++;
       }
       else
       {
            p--;
            j++;
       }
       maxp= max(maxp,p);
    }
    return maxp;
}
int main()
{
    int arr[6]={900,940,950,1100,1500,1800};
    int dep[6]={910,1200,1120,1130,1900,2000};
    cout<<platform(arr,dep,6);
}