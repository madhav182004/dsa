#include<iostream>
using namespace std;

string removeOccurance(string& s, string& part)
{
    int found = s.find(part);
    if(found != string::npos)
    {
        string left = s.substr(0, found);
        string right = s.substr(found+part.size(), s.size());
        s = left + right;

        removeOccurance(s, part);
    }
    return s;
}
int main()
{
    string s, part;
    cout << "Enter the string : ";
    cin>>s;
    cout << "Enter the part string : ";
    cin>>part;
    string ans = removeOccurance(s, part);
    cout<<"The final string is :" << ans;
    return 0;
}