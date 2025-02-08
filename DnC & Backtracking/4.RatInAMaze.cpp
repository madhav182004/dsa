#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int newx, int newy, int row, int col, int maze[][4], vector<vector<bool> > visited)
{
    if(newx>=0&&newy>=0 && newx<row&&newy<col && maze[newx][newy]==1 && visited[newx][newy]==false)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void printAllPath(int maze[][4], int row, int col, int srcx, int srcy, string& output, vector<vector<bool> >& visited)
{
    if(srcx == row-1 && srcy == col-1)
    {
        cout<<output<<endl;
        return;
    }

    //UP
    int newx = srcx - 1;
    int newy = srcy;
    if(isSafe(newx, newy, row, col, maze, visited))
    {
        visited[newx][newy]=true;
        output.push_back('U');
        printAllPath(maze, row, col, newx, newy, output, visited);
        output.pop_back();
        visited[newx][newy]=false;
    }

    //RIGHT
    newx = srcx;
    newy = srcy + 1;
    if(isSafe(newx, newy, row, col, maze, visited))
    {
        visited[newx][newy]=true;
        output.push_back('R');
        printAllPath(maze, row, col, newx, newy, output, visited);
        output.pop_back();
        visited[newx][newy]=false;
    }

    //DOWN
    newx = srcx + 1;
    newy = srcy;
    if(isSafe(newx, newy, row, col, maze, visited))
    {
        visited[newx][newy]=true;
        output.push_back('D');
        printAllPath(maze, row, col, newx, newy, output, visited);
        output.pop_back();
        visited[newx][newy]=false;
    }

    //LEFT
    newx = srcx;
    newy = srcy - 1;
    if(isSafe(newx, newy, row, col, maze, visited))
    {
        visited[newx][newy]=true;
        output.push_back('L');
        printAllPath(maze, row, col, newx, newy, output, visited);
        output.pop_back();
        visited[newx][newy]=false;
    }
}

int main()
{
    int maze[4][4]={
        {1,0,0,0},
        {1,1,0,0},
        {1,1,1,0},
        {1,1,1,1}
    };
    int row = 4;
    int col = 4;
    int srcx=0;
    int srcy=0;

    string output = "";

    vector<vector<bool> > visited(row, (vector<bool>(col, false)));

    if(maze[0][0]==0)
    {
        cout<<"No path exists"<<endl;
    }
    else
    {
        printAllPath(maze, row, col, srcx, srcy, output, visited);
    }

}