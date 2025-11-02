#include<iostream>
#include<vector>
#include<string>
using namespace std;

int numTilePossibilities(vector<int>& freq)
{
    int ans = 0;
    for(int i=0;i<26;i++)
    {
        if(freq[i] != 0)
        {
            ans++;
            freq[i]--;
            int recAns = numTilePossibilities(freq);
            ans+=recAns;
            freq[i]++;
        }
    }
    return ans;
}
int main()
{
    string tiles;
    cout<<"Enter the tiles: ";
    getline(cin, tiles);
    vector<int> freq(26, 0);
    for(auto ch:tiles)
    {
        freq[ch - 'A']++;
    }
    int ans = numTilePossibilities(freq);
    cout<<"Number of tiles Possible : "<<ans<<endl;
}
