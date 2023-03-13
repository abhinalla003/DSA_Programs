//Write a c++ program to implement stack using linked list
//Created on 28-02-2023
//Created by 22CP319
#include<iostream>
using namespace std;
//class for linked list
class node
{
public:
    int info;
    node *prev;
    node(int data)
    {
        info=data;
        prev=NULL;
    }
};
//class for stack
class stk
{
    node *top;
public:
    //Constructor for initialization of the top
    stk()
    {
        top=NULL;
    }
    //pushS() accepts one argument and push it to the stack by linking address
    void pushS(int data)
    {
        node *tmp = new node(data);
        //if stack is full, it happens when the memory of PC is going to finish
        if(!tmp)
        {
            cout<<"Stack Overflow..."<<endl;
            exit(1);
        }
        //assigning data to new node
        tmp->info=data;
        //adding address of top to new node next field
        tmp->prev=top;
        //assigning new node to top as a "new top"
        top=tmp;
    }

    //peek() is a function for returning topmost element of the stack. Return type is int
    int peek()
    {
        if(top!=NULL)
            return (top->info);
        else
        {
            cout<<"Stack is Empty..."<<endl;
        }
    }

    //popS() is a function used to remove top element from stack
    void popS()
    {
        node *tmp;
        //if stack is empty, it happens when all elements are popped off or stack not having single element in it
        if(top==NULL)
        {
            cout<<"Stack Underflow..."<<endl;
            exit(0);
        }
        else
        {
            tmp=top;
            //assign top next field to tmp. Then tmp points to top's below element
            top=top->prev;
            //delete the topmost element from stack
            delete tmp;
        }
    }

    //display() function is used to display all elements of stack
    void display()
    {
        node *tmp;
        if(top==NULL)
        {
            cout<<"Stack Underflow..."<<endl;
            exit(1);
        }
        else
        {
            tmp=top;
            cout<<"Data:- ";
            while(tmp!=NULL)
            {
                cout<<tmp->info;
                tmp=tmp->prev;
                if(tmp!=NULL)
                    cout<<" -> ";
            }
            cout<<endl;
        }
    }
};
int main()
{
    stk s;
    int n,ch=1;
    while(ch)
    {
        cout<<endl<<"1. Push Element in the stack"<<endl;
        cout<<"2. Pop Element in the stack"<<endl;
        cout<<"3. Peek Operation"<<endl;
        cout<<"4. Display the stack"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter your choice:";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"Enter Value: ";
            cin>>n;
            s.pushS(n);
            break;
        case 2:
            s.popS();
            break;
        case 3:
            cout<<"Top Element is "<<s.peek()<<endl;
            break;
        case 4:
            cout<<"Stack Elements: "<<endl;
            s.display();
            break;
        case 5:
            exit(0);
            break;
        }
    }
    return 0;
}
