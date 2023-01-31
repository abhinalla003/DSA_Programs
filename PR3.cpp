//Write a program which is used to convert infix expression into postfix expression
//Created on 31-01-2023
//Created by 22CP319
#include<iostream>
#include<string>
#define SIZE 100
using namespace std;
//Creating infix to postfix function

class stack1
{
    //arr[SIZE] is stack with size 10 and top is variable of integer
    char arr[SIZE];
    int top;
public:
    //Constructor initialize the top pointer with -1
    stack1()
    {
        top=-1;
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
        }
    }
    //popS() is function with no parameter and it returns integer
    //It is used to pop the element in the stack and return the integer
    char popS()
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
            return arr[top--];
        }
    }

    bool emptyS()
    {
        if(top<0)
            return 1;
        else
            return 0;
    }


    //display() is used to display stack till top pointer
    char topS()
    {
        return arr[top];
    }
};

class convert
{
    string postfix, infix;
    stack1 stk;
public:
    convert()
    {
        cout<<"Enter Infix Expression: ";
        cin>>infix;
    }

    void display()
    {
        cout<<"Postfix Expression: "<<postfix<<endl;
    }

    void infix2postfix()
    {
        char ch, popch;
        for(int i=0;i<infix.length();i++)
        {
            ch=infix[i];
            if(is_empty1(ch))
            {
                if(is_operand(ch))
                {
                    postfix+=ch;
                }
                else if(is_operator(ch))
                {
                    if(stk.emptyS())
                        stk.pushS(ch);
                    else
                    {
                        if(pre(ch)>pre(stk.topS()))
                        {
                            stk.pushS(ch);
                        }
                        else
                        {
                            popch=stk.popS();
                            postfix=postfix+popch;
                            stk.pushS(ch);
                        }
                    }
                }
            }
            else
            {
                while(!stk.emptyS())
                {
                    popch=stk.popS();
                    postfix=postfix+popch;
                }
            }
        }
    }

    int pre(char ch5)
    {
        if(ch5=='+' && ch5=='-')
            return 1;
        else if(ch5=='*' && ch5=='/')
            return 2;
    }

    bool is_empty1(char ch2)
    {
        if(ch2=='\n' || ch2=='\0')
            return 0;
        else
            return 1;
    }

    bool is_operand(char ch3)
    {
       if((ch3>='A' || ch3<='Z') || (ch3>='a' || ch3<='z'))
           return 1;
       else
           return 0;
    }

    bool is_operator(char ch4)
    {
        if(ch4=='+' || ch4=='-' || ch4=='*' || ch4=='/')
            return 1;
        else
            return 0;
    }
};

int main()
{
    convert ob;
    ob.infix2postfix();
    ob.display();
    return 0;
}
