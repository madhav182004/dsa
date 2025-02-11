#include<iostream>
using namespace std;

int minDistance(string& word1, string& word2, int i, int j)
{
    int ans;
    if(i >= word1.length())
    {
        return word2.length()-j;
    }
    if(j >= word2.length())
    {
        return word1.length()-i;
    }
    if(word1[i] == word2[j])
    {
        ans = 0 + minDistance(word1, word2, i+1, j+1);
    }
    else
    {
        int option1 = 1 + minDistance(word1, word2, i, j+1);
        int option2 = 1 + minDistance(word1, word2, i+1, j);
        int option3 = 1 + minDistance(word1, word2, i+1, j+1);
        ans = min(option1, min(option2, option3));
    }
    return ans;
}
int main()
{
    string word1, word2;
    cout << "Enter the word1: ";
    getline(cin, word1);
    cout << "Enter the word2: ";
    getline(cin, word2);
    int i = 0;
    int j = 0;
    int ans = minDistance(word1, word2, i, j);
    cout << "Output: " << ans << endl;
    return 0;
}