#include<iostream>
using namespace std;
#include<climits>
int maxCrossSum(int arr[],int left,int mid,int right)
{
    int leftSum= INT_MIN;
    int sum=0;
    for(int i=mid;i>=left;i--)
    {
           sum+= arr[i];
           if(sum>leftSum)
           {
            leftSum=sum;
           }
    }
    sum=0;
    int rightSum=INT_MIN;
    for(int i=mid+1;i<=right;i++)
    {
         sum+= arr[i];
           if(sum>rightSum)
           {
            rightSum=sum;
           }
    }

    return leftSum+rightSum;

}
int maxSubArrSum(int arr[],int left,int right)
{
    if (left == right)
        return arr[left];
    int mid= (left+right)/2;
    int leftsum= maxSubArrSum(arr,left,mid);
    int rightsum= maxSubArrSum(arr,mid+1,right);
    int crossSum= maxCrossSum(arr,left,mid,right);

    return max(max(leftsum,rightsum),crossSum);
}
int main()
{
    int arr[8]= {-2, -5, 6, -2, -3, 1, 5, -6};
    int sum= maxSubArrSum(arr,0,7);
    cout<<sum;
}