//Implement the stack having underflow and overflow condition using "TEMPLATE"
//Created on 24-01-2023
//Created by 22CP319
#include<iostream>
#define SIZE 10
using namespace std;
//Creating class stack using TEMPLATE
template <class S>
class stk
{
    //arr[SIZE] is stack with size 10 and top is variable of integer
    S arr[SIZE];
    int top;
public:
    //Constructor initialize the top pointer with -1
    stk()
    {
        top=-1;
        cout<<"Stack is created..."<<endl;
    }
    //pushS() is function and it doesn't return anything
    //It is used to push the element in the stack
    void pushS()
    {
        S num;
        //checking overflow condition if top pointer is greater than SIZE-1, then stack is overflow
        if(top>SIZE-1)
        {
            cout<<"Stack is overflow"<<endl<<endl;
        }
        else
        {
            //Accepting element from user
            cout<<"Enter value : ";
            cin>>num;
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
        }
        else
        {
            //return the element at stack of index top and then decrement the top by 1
            cout<<"Poped element is "<<arr[top]<<endl;
            return arr[top--];
        }
    }
    //display () is used to display stack till top pointer
    void display()
    {
        //checking the
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
    stk<float> s;
    char ch=0;
    while(ch!='4')
    {
        cout<<endl<<"1. Push Element from stack"<<endl;
        cout<<"2. Pop Element from stack"<<endl;
        cout<<"3. Display stack"<<endl;
        cout<<"4. For Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>ch;
        try
        {
            if((int)ch>=48 && (int)ch<=57)
            {
                switch(ch)
                {
                    case '1': s.pushS();
                            break;
                    case '2': s.popS();
                            break;
                    case '3': s.display();
                            break;
                    case '4': exit(0);
                    default: cout<<"Entered choice is wrong..."<<endl;
                            break;
                }
            }
            else
                throw ch;
        }
        catch(char n)
        {
            cout<<"You have entered Inappropriate choice..."<<endl;
        }
    }
    return 0;
}
