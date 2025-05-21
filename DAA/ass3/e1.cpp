#include<iostream>
#include<vector>
using namespace std;

void countSubsets(vector<int>& arr, int target, int index, int& count) {
    if (target == 0) {
        count++;
        return;
    }

    for (int i = index; i < arr.size(); i++) {
        if (arr[i] <= target) {
            countSubsets(arr, target - arr[i], i + 1, count);
        }
    }
}
int getSubsetCount(vector<int>& arr, int target) {
    int count = 0;
    countSubsets(arr, target, 0, count);
    return count;
}
int main()
{
    vector<int> arr= {2, 3, 7, 8, 10};
    int target=10;
    int subsetCount=  getSubsetCount(arr,target);
    cout<<"no. of subsets with given sum: "<<getSubsetCount;

}