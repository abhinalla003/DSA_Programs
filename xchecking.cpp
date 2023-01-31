#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<char> ob;
    ob.push('a');
    ob.push('b');
    ob.push('h');
    ob.push('i');
    ob.push('s');
    ob.push('h');
    ob.push('e');
    ob.push('k');
    char popch;
    popch=ob.pop();
    cout<<"Popped: "<<popch<<endl;
    popch=ob.pop();
    cout<<"Popped: "<<popch<<endl;
    popch=ob.pop();
    cout<<"Popped: "<<popch<<endl;
    popch=ob.pop();
    cout<<"Popped: "<<popch<<endl;
    return 0;
}
