#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int maxMeetings(vector<int> &st, vector<int> &end, int n) 
{
    vector<pair<int, int>> time;
    for(int i=0;i<n;i++)
    {
        time.push_back({end[i], st[i]});//end, start
    }
    sort(time.begin(), time.end());//sort using end
    int count = 1;
    int prevStart = time[0].second;
    int prevEnd = time[0].first;
    for(int i=1;i<n;i++)
    {
        int currStart = time[i].second;
        int currEnd = time[i].first;
        if(currStart > prevEnd)
        {
            count++;
            prevStart = currStart;
            prevEnd = currEnd;
        }
    }
    return count;
}
int main() 
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> st(n);
    vector<int> end(n);
    cout << "Enter the starting times: ";
    for(int i = 0; i < n; i++) {
        cin >> st[i];
    }
    cout << "Enter the ending times: ";
    for(int i = 0; i < n; i++) {
        cin >> end[i];
    }
    int ans = maxMeetings(st, end, n);
    cout<<"Max Meetings : "<<ans<<endl;
    return 0;
}
