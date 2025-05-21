#include<iostream>
#include<vector>
using namespace std;

#define V 4

bool is_safe(int v,bool graph[V][V],vector<int> &color, int c)
{
    for(int i=0;i<V;i++)
    {
        if(graph[v][i] && color[i]==c)
        return false;
    }
    return true;
}

bool graph_color_u(bool graph[V][V],int m,vector<int> &color,int v)
{
    if(v==V)
    {
        return true;
    }
    for(int c=1;c<=m;c++)
    {
        if(is_safe(v,graph,color,c))
        {
            color[v]=c;
            if(graph_color_u(graph,m,color,v+1))
            return true;
            color[v]=0;
        }
        
    }
    return false;
}

void graph_color(bool graph[V][V],int m)
{
    vector<int> color(V,0);
    if(!graph_color_u(graph,m,color,0))
    {
        cout<<"no solution exists";
        return;
    }
    else{
        cout<<"solution existes: following are the assigned colors \n";
        for(int i=0;i<V;i++)
        {
            cout<<color[i]<<"\t";
        }
    }
}
int main()
{
    bool graph[V][V]= { {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 1},
    {1, 0, 1, 0}
};
int m=3;
graph_color(graph,m);
}
