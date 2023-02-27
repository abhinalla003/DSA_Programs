//Write a program to match the brackets and order of the brackets. Return the total type of brackets.
//Using Stack approach
//Created on 27-02-23
//Created by 22CP319
#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool match(char sttop, char s1char)
{
    if(sttop=='(' && s1char==')')
        return true;
    else if(sttop=='{' && s1char=='}')
        return true;
    else if(sttop=='[' && s1char==']')
        return true;
    else
        return false;
}
void checkBrackets(string s1)
{
    stack<char> st1;
    int top=-1, cnt=0;
    for(int i=0;i<s1.length();i++)
    {
        if(s1[i]=='(' || s1[i]=='{' || s1[i]=='[')
            st1.push(s1[i]);
        else if(s1[i]==')' || s1[i]=='}' || s1[i]==']')
        {
            if(match(st1.top(),s1[i]))
            {
                cnt++;
                st1.pop();
            }
            else
            {
                cout<<"Incorrect brackets..."<<endl;
                exit(0);
            }
        }
        else
        {
            cout<<"Incorrect brackets..."<<endl;
            exit(0);
        }
    }
    cout<<"No.of pair of brackets is "<<cnt<<endl;
    cout<<"Correct brackets and order of the brackets also correct..."<<endl;
}
int main()
{
    string str;
    cout<<"Enter String: ";
    cin>>str;
    checkBrackets(str);
    return 0;
}