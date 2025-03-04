#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;

bool canDistribute(vector<int>& counts, vector<int>& quantity, int ithCustomer)
{
    if(ithCustomer == quantity.size())
    {
        return true;
    }
    for(int i=0;i<counts.size();i++)
    {
        if(counts[i] >= quantity[ithCustomer])
        {
            counts[i] -= quantity[ithCustomer];
            if(canDistribute(counts, quantity, ithCustomer + 1))
            {
                return true;
            }
            counts[i] += quantity[ithCustomer];
        }
    }
    return false;
}
int main(){
    vector<int> nums;
    vector<int> quantity;
    int n, q;
    cout<<"Enter the size of nums array: ";
    cin>>n;
    cout<< "Enter the value of array elemets: "<< endl;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        nums.push_back(a);
    }
    cout<<"Enter the size of quantity array: ";
    cin>>q;
    cout<< "Enter the value of array elemets: "<< endl;
    for(int i=0;i<q;i++)
    {
        int a;
        cin>>a;
        quantity.push_back(a);
    }
    cout<<endl;

    unordered_map<int, int> countMap;
    for(auto num:nums)
    {
        countMap[num]++;
    }
    vector<int> counts;
    for(auto j:countMap)
    {
        counts.push_back(j.second);
    }

    bool ans = canDistribute(counts, quantity, 0);
    
    cout<<"Output: "<<ans<<endl;
}