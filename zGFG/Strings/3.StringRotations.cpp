#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

bool areRotations(string& s1, string& s2)
{
    if(s1.length() != s2.length())
    {
        return false;
    }
    string temp = s1+s1;
    return temp.find(s2) != string::npos;
}
int main()
{
    string s1, s2;
    cout << "Enter the string s1: ";
    getline(cin, s1);
    cout << "Enter the string s2: ";
    getline(cin, s2);
    if(areRotations(s1, s2))
    {
        cout<<"Pairs are rotated"<<endl;
    }
    else
    {
        cout<<"Pairs are not rotated"<<endl;
    }
    return 0;
}