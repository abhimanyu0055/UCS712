#include<iostream>
#include<vector>
using namespace std;
bool is_safe(vector<int> &board,int row,int col)
{
    for(int i=0;i<row;i++)
    {
        if(board[i]==col|| abs(board[i]-col)==abs(i-row))
        {
            return false;
        }
    }
    return true;
}
void nqu(int n,int row,vector<int> &board,vector<vector<int>> &solutions)
{
    if(row==n)
    {
        solutions.push_back(board);
        return;
    }
    for (int col=0;col<n;col++)
    {
        if(is_safe(board,row,col))
        {
            board[row]=col;
            nqu(n,row+1,board,solutions);
        }
    }
}
vector<vector<int>> nq(int n)
{
    vector<vector<int>> solutions;
    vector<int> board(n,-1);
    nqu(n,0,board,solutions);
    return solutions;
}
void print_sol(const vector<vector<int>> &solutions)
{
    for (const auto& solution : solutions) {  //iterate each row
        cout << "[";
        for (int col : solution) {            //iterate each element of the row
            cout << col + 1 << " "; 
        }
        cout << "]\n";                          //ok cout<<endl only here easier
    }
}
int main()
{
    int n=4;
    vector<vector<int>> solutions= nq(n);
    print_sol(solutions);

}