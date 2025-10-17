#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int fractionalKnapsack(vector<int> &val, vector<int> &wt, int n, int capacity) 
{
    vector<float> valwtRatio;
    for(int i=0;i<n;i++)
    {
        float ratio = (val[i] * 1.0)/wt[i];
        valwtRatio.push_back(ratio);
    }
    priority_queue<pair<float, pair<int, int>>> maxi;
    for(int i=0;i<n;i++)
    {
        maxi.push({valwtRatio[i], {val[i], wt[i]}});
    }
    int totalVal = 0;
    while(capacity != 0 && !maxi.empty())
    {
        auto front = maxi.top();
        float ratio = front.first;
        int value = front.second.first;
        int weight = front.second.second;
        maxi.pop();
        if(capacity >= weight)
        {
            totalVal += value;
            capacity = capacity-weight;
        }
        else
        {
            int valueToInclude = ratio * capacity;
            totalVal += valueToInclude;
            capacity = 0;
            break;
        }
    }
    return totalVal;
}
int main() 
{
    int n, capacity;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> val(n);
    vector<int> wt(n);
    cout << "Enter the values: ";
    for(int i = 0; i < n; i++) {
        cin >> val[i];
    }
    cout << "Enter the weights: ";
    for(int i = 0; i < n; i++) {
        cin >> wt[i];
    }
    cout << "Enter the capacity: ";
    cin >> capacity;
    int ans = fractionalKnapsack(val, wt, n, capacity);
    cout<<"Ans : "<<ans<<endl;
    return 0;
}
