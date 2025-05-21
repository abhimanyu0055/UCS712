#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"enter no. of elements";
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    //imp
    unordered_map<int,int> mapp;
    for(int i=0;i<n;i++)
    {
        mapp[v[i]]= i+1;
    }
    cout<<"enter no. of queries";
    int q;
    cin>>q;
    while(q--)
    {
        int x;
        cin>>x;
        cout<<mapp[x]<<"\t";
    }

}
