#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;
class compare{
    public:
        bool operator()(pair<string,int>& a, pair<string,int>& b)
        {
            if(a.second == b.second)
            {
                return a.first > b.first;
            }
            return a.second < b.second;
        }
};
vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> freq;
    for (auto &w : words)
    {
        freq[w]++;
    }
    priority_queue<pair<string, int>, vector<pair<string, int>>, compare> pq;
    for(auto& word:freq)
    {
        pq.push({word.first, word.second});
    }
    vector<string> result;
    while(k-- && !pq.empty())
    {
        result.push_back(pq.top().first);
        pq.pop();
    }
    return result;
}
int main()
{
    vector<string> words = {"i","love","leetcode","i","love","coding"};
    int k = 2;
    vector<string> ans = topKFrequent(words, k);
    cout << "Top " << k << " frequent words are:\n";
    for (auto &w : ans)
    {
        cout << w << endl;
    }
    return 0;
}