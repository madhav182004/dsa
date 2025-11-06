#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
unordered_map<int, bool> rowCheck;
unordered_map<int, bool> topDiagonal;
unordered_map<int, bool> bottomDiagonal;
bool isSafe(int row, int col, vector<vector<char>>& board)
{
    if(rowCheck[row] == true)
    {
        return false;
    }
    if(topDiagonal[col-row] == true)
    {
        return false;
    }
    if(bottomDiagonal[row+col] == true)
    {
        return false;
    }
    return true;
}
void storeSol(vector<vector<char>>& board, vector<vector<string>>& ans)
{
    vector<string> tempSol;
    for(auto vec:board)
    {
        string temp="";
        for(auto ch:vec)
        {
            temp.push_back(ch);
        }
        tempSol.push_back(temp);
    }
    ans.push_back(tempSol);
}
void solve(vector<vector<char>>& board, vector<vector<string>>& ans, int n, int col)
{
    if(col>=n)
    {
        storeSol(board, ans);
        return;
    }
    for(int row = 0;row<n;row++)
    {
        if(isSafe(row, col, board))
        {
            board[row][col] = 'Q';
            rowCheck[row] = true;
            topDiagonal[col-row]=true;
            bottomDiagonal[row+col]=true;

            solve(board, ans, n, col+1);

            board[row][col] = '.';
            rowCheck[row] = false;
            topDiagonal[col-row]=false;
            bottomDiagonal[row+col]=false;
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<vector<char>> board(n, vector<char>(n, '.'));
    int col = 0;
    solve(board, ans, n, col);
    return ans;
}
int main()
{
    int n;
    cout<<"Enter the value of n to check no. of nqueens possible : "<<endl;
    cin>>n;
    vector<vector<string>> ans = solveNQueens(n);
    for(auto vec:ans)
    {
        for(auto ch:vec)
        {
            cout<<ch<<" ";
        }
        cout<<endl;
    }
    return 0;
}