#include<iostream>
#include<vector>
using namespace std;

vector<int> findUnion(vector<int> &a, vector<int> &b) {
    int i = 0;
    int j = 0;
    vector<int> ans;
    while(i<a.size() && j<b.size())
    {
        if(a[i]==b[j])
        {
            if(ans.empty() || ans.back() != a[i]) {
                ans.push_back(a[i]);
            }
            i++;
            j++;
        }
        else if(a[i]<b[j])
        {
            if(ans.empty() || ans.back() != a[i]) {
                ans.push_back(a[i]);
            }
            i++;
        }
        else
        {
            if(ans.empty() || ans.back() != b[j]) {
                ans.push_back(b[j]);
            }
            j++;
        }
    }
    while(i < a.size()) 
    {
        if(ans.empty() || ans.back() != a[i]) {
            ans.push_back(a[i]);
        }
        i++;
    }
    while(j < b.size()) 
    {
        if(ans.empty() || ans.back() != b[j]) {
            ans.push_back(b[j]);
        }
        j++;
    }
    return ans;
}
int main()
{
    int x,y;
    cout<<"Enter the size of the array A:";
    cin>>x;
    cout<<"Enter the size of the array B:";
    cin>>y;
    vector<int> a(x);
    vector<int> b(y);
    vector<int> ans;
    if(x==0 || y==0)
    {
        cout<<"Array is empty";
        return 0;
    }
    cout << "Enter the elements A: ";
    for(int i = 0; i < x; i++) {
        cin >> a[i];
    }
    cout << "Enter the elements B: ";
    for(int i = 0; i < y; i++) {
        cin >> b[i];
    }
    ans = findUnion(a,b);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}
