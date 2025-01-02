#include<iostream>
using namespace std;

void subsequenceString(string str, string output, int index)
{
    if(index>=str.length())
    {
        cout << output << endl;
        return;
    }
    char ch = str[index];

    //exclude
    subsequenceString(str, output, index+1);

    //include
    output.push_back(ch);
    subsequenceString(str, output, index+1);
}

int main()
{
    string str = "abc";
    string output = "";
    int index = 0;
    subsequenceString(str, output, index);
}