#include<iostream>
#include<vector>
using namespace std;

int maxSubArray(vector<int>& v, int start, int end)
{
    if(start == end)
        return v[start];
    
    int maxLeftBorderSum = INT_MIN;
    int maxRightBorderSum = INT_MIN;

    int mid = start + (end - start) / 2;

    int maxLeftSum = maxSubArray(v, start, mid);
    int maxRightSum = maxSubArray(v, mid+1, end);

    int leftBorderSum = 0;
    int rightBorderSum = 0;
    for(int i=mid;i>=start;i--)
    {
        leftBorderSum += v[i];
        if(leftBorderSum > maxLeftBorderSum)
            maxLeftBorderSum = leftBorderSum;
    }
    for(int i=mid+1;i<=end;i++)
    {
        rightBorderSum += v[i];
        if(rightBorderSum > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }

    int crossBorderSum = maxLeftBorderSum + maxRightBorderSum;

    return max(maxLeftSum, max(maxRightSum, crossBorderSum));
}

int main(){
    vector<int> v;
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    cout<< "Enter the array elemets: "<< endl;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    cout<<endl;

    int c = maxSubArray(v, 0, v.size()-1);
    
    cout<< "Output: "<<c;
}