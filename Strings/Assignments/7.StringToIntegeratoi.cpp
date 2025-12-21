#include<iostream>
#include<vector>
#include<string>
using namespace std;

int myAtoi(string s)
{
    int num=0, i=0, sign=1;
    while(s[i] == ' ')
    {
        i++;
    }
    if(i<s.size() && (s[i] == '-' || s[i] == '+'))
    {
        sign = s[i] == '+' ? 1:-1;
        i++;
    }
    while(i<s.size() && isdigit(s[i]))
    {
        //condition to handle overflow
        if(num > INT_MAX/10 || (num == INT_MAX/10 && s[i] > '7'))
        {
            return sign == -1 ? INT_MIN : INT_MAX;
        }
        num = num*10+(s[i] - '0');
        i++;
    }
    return num*sign;
}
int main()
{
    string s;
    cout << "Enter the string s: ";
    getline(cin, s);
    int ans = myAtoi(s);
    cout<< "Integer of the given string is : "<<ans<<endl;
    return 0;
}