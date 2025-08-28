#include<iostream>
#include<unordered_map>
using namespace std;

bool isSubset(int a1[], int a2[], int n, int m)
{
    unordered_map<int, int> map;
    bool ans = true;
    for(int i=0;i<n;i++)
    {
        map[a1[i]]++;
    }
    for(int i=0;i<m;i++)
    {
        if(map.find(a2[i]) == map.end())
        {
            ans = false;
            break;
        }
        else
        {
            if(map[a2[i]] > 0)
            {
                map[a2[i]]--;
            }
            else
            {
                ans = false;
                break;
            }
        }
    }
    return ans;
}
int main()
{
    int a1[8] = {11, 7, 1, 13, 21, 3, 7, 3};
    int a2[5] = {11, 3, 7, 1, 7};
    if(isSubset(a1, a2, 8, 5))
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;
}