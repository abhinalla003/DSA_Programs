//Write a program which is used to compute fibonacci series
//Created on 07-02-2023
//Created by 22CP319
#include<iostream>
using namespace std;
int fibo(int n)
{
    if(n==0 || n==1)
    {
        return n;
    }
    else
        return (fibo(n-1)+fibo(n-2));
}
int main()
{
    int n;
    cout<<"Enter a number:";
    cin>>n;
    cout<<"Fibonacci Series of "<<n<<" is :-"<<endl;
    for(int i=0;i<=n;i++)
    {
        if(i==n)
            cout<<fibo(i);
        else
            cout<<fibo(i)<<", ";
    }
    return 0;
}
