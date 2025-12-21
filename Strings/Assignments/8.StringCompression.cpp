#include<iostream>
#include<vector>
#include<string>
using namespace std;

int compress(vector<char>& s) {
    int index = 0;
    int count = 1;
    char prev = s[0];
    for(int i=1;i<s.size();i++)
    {
        if(s[i] == prev)
        {
            count++;
        }
        else
        {
            s[index++] = prev;
            if(count > 1)
            {
                int start = index;
                while(count)
                {
                    s[index++] = (count%10) + '0';
                    count = count / 10;
                }
                reverse(s.begin() + start, s.begin() + index);
            }
            prev = s[i];
            count = 1;
        }
    }
    s[index++] = prev;
    if(count > 1)
    {
        int start = index;
        while(count)
        {
            s[index++] = (count%10) + '0';
            count = count / 10;
        }
        reverse(s.begin() + start, s.begin() + index);
    }
    return index;
}
int main()
{
    int n;
    cout << "Enter the size of chars array: ";
    cin>>n;
    cout << "Enter the characters of chars array: ";
    vector<char> s(n);
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    int ans = compress(s);
    cout<< "Ans : "<<ans<<endl;
    return 0;
}