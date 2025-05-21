#include<iostream>
#include<vector>
using namespace std;

bool is_safe(vector<vector<int> >&grid,int row,int col,int num)
{
    for(int i=0;i<grid.size();i++)
    {
        if(grid[row][i]==num)
        {
            return false;
        }
        if(grid[i][col]==num)
        {
            return false;
        }
        if(grid[3*(row/3)+ i/3][3*(col/3)+ i%3]==num)
        {
            return false;
        }
    }
    return true;
}

bool solve_sudoku(vector<vector<int>> &grid)
{
    for(int i=0;i<grid.size();i++)
    {
        for(int j=0;j<grid.size();j++)
        {
            if(grid[i][j]==0)
            {
                for(int num=1;num<=9;num++)
                {
                    if(is_safe(grid,i,j,num))
                    {
                        grid[i][j]=num;
                        if(solve_sudoku(grid))
                        return true;
                        grid[i][j]=0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void print_grid(vector<vector<int>> &grid)
{
    for(const auto &row:grid)
    {
        for(int col:row)
        {
            cout<<col<<" ";
        }
        cout<<"\n";
    }
}


int main()
{
    vector<vector<int>> grid={ {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}};
    if(solve_sudoku(grid))
    {
        print_grid(grid);
    }
    else{
        cout<<"no solution";
    }

}