#include<iostream>
#include<vector>
using namespace std;
bool isSafe(int row, int col, char val, vector<vector<char>>& board)
{
    int n = board.size();
    for(int i=0;i<n;i++)
    {
        if(board[row][i] == val)
        {
            return false;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(board[i][col] == val)
        {
            return false;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(board[3*(row/3)+i/3][3*(col/3)+i%3] == val)
        {
            return false;
        }
    }
    return true;
}
bool solveSudoku(vector<vector<char>>& board)
{
    int n = board.size();
    for(int i = 0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(board[i][j] == '.')
            {
                for(char ch = '1';ch<='9';ch++)
                {
                    if(isSafe(i, j, ch, board))
                    {
                        board[i][j] = ch;
                        bool recAns = solveSudoku(board);
                        if(recAns == true)
                        {
                            return true;
                        }
                        else
                        {
                            board[i][j] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
int main()
{
    cout<<"Enter the sudoku board: "<<endl;
    vector<vector<char>> board(9, vector<char>(9));
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            char ch;
            cin >> ch;
            board[i][j] = ch;
        }
    }
    if(solveSudoku(board))
    {
        cout<<"The solved Sudoku: "<<endl;
        for(auto vec:board)
        {
            for(auto ch:vec)
            {
                cout<<ch<<" ";
            }
            cout<<endl;
        }
    }
    else
    {
        cout<<"No sol. exists."<<endl;
    }
    return 0;
}