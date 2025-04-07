#include<iostream>
#include<vector>
using namespace std;

    // int solve(string& word1, string& word2, int i, int j)
    // {
    //     int ans;
    //     if(i >= word1.length())
    //     {
    //         return word2.length()-j;
    //     }
    //     if(j >= word2.length())
    //     {
    //         return word1.length()-i;
    //     }
    //     if(word1[i] == word2[j])
    //     {
    //         ans = 0+solve(word1, word2, i+1, j+1);
    //     }
    //     else
    //     {
    //         int option1 = 1 + solve(word1, word2, i, j+1);
    //         int option2 = 1 + solve(word1, word2, i+1, j);
    //         int option3 = 1 + solve(word1, word2, i+1, j+1);
    //         ans = min(option1, min(option2, option3));
    //     }
    //     return ans;
    // }
    // int solveUsingMemo(string& word1, string& word2, int i, int j, vector<vector<int> >& dp)
    // {
    //     if(i >= word1.length())
    //     {
    //         return word2.length()-j;
    //     }
    //     if(j >= word2.length())
    //     {
    //         return word1.length()-i;
    //     }
    //     if(dp[i][j] != -1)
    //     {
    //         return dp[i][j];
    //     }
    //     if(word1[i] == word2[j])
    //     {
    //         dp[i][j] = 0+solveUsingMemo(word1, word2, i+1, j+1, dp);
    //     }
    //     else
    //     {
    //         int option1 = 1 + solveUsingMemo(word1, word2, i, j+1, dp);
    //         int option2 = 1 + solveUsingMemo(word1, word2, i+1, j, dp);
    //         int option3 = 1 + solveUsingMemo(word1, word2, i+1, j+1, dp);
    //         dp[i][j] = min(option1, min(option2, option3));
    //     }
    //     return dp[i][j];
    // }
    // int solveUsingTabulation(string& a, string& b)
    // {
    //     vector<vector<int> >dp(a.length()+1, vector<int>(b.length()+1, -1));
    //     for(int col=0;col<=b.length();col++)
    //     {
    //         dp[a.length()][col] = b.length() - col;
    //     }
    //     for(int row=0;row<=a.length();row++)
    //     {
    //         dp[row][b.length()] = a.length() - row;
    //     }

    //     for(int i = a.length() - 1; i>=0; i--)
    //     {
    //         for(int j = b.length() - 1;j>=0;j--)
    //         {
    //             if(a[i] == b[j])
    //             {
    //                 dp[i][j] = 0+dp[i+1][j+1];
    //             }
    //             else
    //             {
    //                 int option1 = 1 + dp[i][j+1];
    //                 int option2 = 1 + dp[i+1][j];
    //                 int option3 = 1 + dp[i+1][j+1];
    //                 dp[i][j] = min(option1, min(option2, option3));
    //             }
    //         }
    //     }
    //     return dp[0][0];
    // }
int solveUsingTabulationSO(string& a, string& b)
{
    vector<int> curr(a.length()+1, -1);
    vector<int> next(a.length()+1, -1);

    //abhi ke liye bhul jao
    // for(int col=0;col<=b.length();col++)
    // {
    //     dp[a.length()][col] = b.length() - col;
    // }
    //mujhe curr ke last dabbe me b.length()-j save karna hai
    for(int row=0;row<=a.length();row++)
    {
        next[row] = a.length() - row;
    }
    
    for(int j = b.length() - 1;j>=0;j--)
    {
        //har naye col ke last dabbe me ans insert karo
        curr[a.length()] = b.length()-j;
        for(int i = a.length() - 1; i>=0; i--)
        {
            if(a[i] == b[j])
            {
                curr[i] = 0+next[i+1];
            }
            else
            {
                int option1 = 1 + next[i];
                int option2 = 1 + curr[i+1];
                int option3 = 1 + next[i+1];
                curr[i] = min(option1, min(option2, option3));
            }
        }
        next = curr;
    }
    return next[0];
}
int main()
{
    string a, b;
    cout << "Enter str1 : ";
    getline(cin, a);
    cout << "Enter str2 : ";
    getline(cin, b);
    int ans = solveUsingTabulationSO(a, b);
    cout<<"No. of min opreations :" << ans;
    return 0;
}