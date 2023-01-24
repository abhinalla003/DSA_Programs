//Implement the stack having underflow and overflow condition
//Created on 24-01-2023
//Created by 22CP319
#include<iostream>
#define SIZE 10
using namespace std;
//Creating class stack
class stk
{
    //arr[SIZE] is stack with size 10 and top is variable of integer
    int arr[SIZE];
    int top;
public:
    //Constructor initialize the top pointer with -1
    stk()
    {
        top=-1;
        cout<<"Stack is created..."<<endl<<endl;
    }
    //pushS() is function with parameter num as integer variable amd it doesn't return anything
    //It is used to push the element in the stack accepting one argument
    void pushS(int num)
    {
        //checking overflow condition if top pointer is greater than SIZE-1, then stack is overflow
        if(top>SIZE-1)
        {
            cout<<"Stack is overflow"<<endl<<endl;
            exit(0);
        }
        else
        {
            //incrementing top pointer then assigning the value
            arr[++top]=num;
            cout<<"Pushed element is "<<num<<endl;
        }
    }
    //popS() is function with no parameter and it returns integer
    //It is used to pop the element in the stack and return the integer
    int popS()
    {
        //checking underflow condition if top pointer is less than 0, then stack is underflow
        if(top<0)
        {
            cout<<"Stack is underflow"<<endl<<endl;
            exit(0);
        }
        else
        {
            //return the element at stack of index top and then decrement the top by 1
            cout<<"Poped element is "<<arr[top]<<endl;
            return arr[top--];
        }
    }
    //display() is used to display stack till top pointer
    void display()
    {
        if(top<0)
            cout<<endl<<"Stack is empty and can't print"<<endl;
        else
        {
            cout<<endl<<"Elements of stack are:"<<endl;
            for(int i=0;i<=top;i++)
                cout<<"Element of "<<i+1<<" : "<<arr[i]<<endl;
        }
    }
};
int main()
{
    stk s;
    s.pushS(8);
    s.pushS(11);
    s.pushS(12);
    s.pushS(15);
    s.pushS(19);
    cout<<endl;
    s.popS();
    s.popS();
    s.popS();
    s.display();
    return 0;
}
