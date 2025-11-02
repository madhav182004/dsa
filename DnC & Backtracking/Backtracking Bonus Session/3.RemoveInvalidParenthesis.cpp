#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;

void solve(string& s, unordered_set<string>& ans, int open, int close, int bal, int index, string& output)
{
    if(index >= s.length())
    {
        if(open == 0 && close == 0 && bal == 0)
        {
            ans.insert(output);
        }
        return;
    }
    if(s[index] != '(' && s[index] != ')')
    {
        output.push_back(s[index]);
        solve(s, ans, open, close, bal, index+1, output);
        output.pop_back();
    }
    else
    {
        if(s[index] == '(')
        {
            if(open>0)
            {
                solve(s, ans, open-1, close, bal, index+1, output);
            }
            output.push_back('(');
            solve(s, ans, open, close, bal+1, index+1, output);
            output.pop_back();
        }
        else if(s[index] == ')')
        {
            if(close>0)
            {
                solve(s, ans, open, close-1, bal, index+1, output);
            }
            if(bal>0)
            {
                output.push_back(')');
                solve(s, ans, open, close, bal-1, index+1, output);
                output.pop_back();
            }
        }
    }
}

vector<string> removeInvalidParentheses(string s) {
    unordered_set<string> ans;
    int invalidOpen = 0;
    int invalidClosed = 0;
    int bal = 0;
    int index = 0;
    string output = "";
    for(auto ch:s)
    {
        if(ch == '(')
        {
            invalidOpen++;
        }
        else if(ch == ')')
        {
            if(invalidOpen > 0)
            {
                invalidOpen--;
            }
            else
            {
                invalidClosed++;
            }
        }
    }
    solve(s, ans, invalidOpen, invalidClosed, bal, index, output);
    return vector<string>(ans.begin(), ans.end());
}

int main() {
    string s;
    cout<<"Enter the string: ";
    cin >> s;
    vector<string> res = removeInvalidParentheses(s);
    cout<<"Ouput stirngs: "<<endl;
    for(auto &str : res)
    {
        cout << str << endl;
    }
    return 0;
}
