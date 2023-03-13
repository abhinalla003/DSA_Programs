//Write a program to implement doubly linked list and its function
//Created on 21-02-2023
//Created by 22CP319
#include<iostream>
using namespace std;
class doull
{
    doull *prev;
    int info;
    doull *next;
public:
    doull(){}
    doull(int data)
    {
        prev=NULL;
        info=data;
        next=NULL;
    }
    void traverse(int dir)
    {
        doull *tp=this;
        if(dir==1)
        {
            //Traversing from first node
            while(tp!=NULL)
            {
                cout<<"Data: - "<<tp->info<<endl;
                tp=tp->next;
            }
        }
        else
        {
            //Traversing from last node
            while(tp->next!=NULL)
            {
                tp=tp->next;
            }
            while(tp!=NULL)
            {
                cout<<"Data: - "<<tp->info<<endl;
                tp=tp->prev;
            }
        }
    }
    //Appending node from last
    void append(doull *newnode)
    {
        doull *tp=this;
        while(tp->next!=NULL)
        {
            tp=tp->next;
        }
        newnode->prev=tp;
        tp->next=newnode;
    }
    //Inserting new node
    void insertNode(doull *newnode, int value)
    {
        doull *tp=this;
        while(tp->info!=value)
            tp=tp->next;
        newnode->next=tp->next;
        newnode->prev=tp;
        doull *new_next=tp->next;
        new_next->prev=newnode;
        tp->next=newnode;
    }
    //Deleting node
    doull* deleteNode(int value)
    {
        doull *tp=this;
        doull *prev=NULL;
        //traverse till value match
        while(tp->info!=value)
        {
            prev=tp;
            tp=tp->next;
        }
        //deleting first node
        if(tp==this)
        {
            doull *r_first=tp->next;
            r_first->prev=NULL;
            delete tp;
            return r_first;
        }
        //Deleting Last Node
        else if(tp->next==NULL)
        {
            doull *ext=tp->prev;
            ext->next=NULL;
            delete tp;
            return this;
        }
        //Deleting intermediate node
        else
        {
            doull *ext=tp->next;
            ext->prev=tp->prev;
            ext=tp->prev;
            ext->next=tp->next;
            delete tp;
            return this;
        }
    }
};
int main()
{
    doull *ob1=new doull(5);
    doull *ob2=new doull(10);
    doull *ob3=new doull(15);
    int ch,trav;
    cout<<endl<<"APPENDING NODE:-"<<endl<<endl;
    ob1->append(ob2);
    ob1->append(ob3);
    cout<<"Enter Traversing Method:"<<endl<<"1: Forward Traverse"<<endl<<"2: Backward Traverse"<<endl<<"Enter Choice:";
    cin>>trav;
    ob1->traverse(trav);
    cout<<"Enter Value after which you want to insert:";
    cin>>ch;

    cout<<endl<<"INSERTING NODE:-"<<endl;
    doull *ob4=new doull(20);
    ob1->insertNode(ob4,ch);
    cout<<"Enter Traversing Method:"<<endl<<"1: Forward Traverse"<<endl<<"2: Backward Traverse"<<endl<<"Enter Choice:";
    cin>>trav;
    ob1->traverse(trav);

    cout<<endl<<"DELETING NODE:-"<<endl;
    cout<<"Enter Deleting Value:";
    cin>>ch;
    doull *r_first=ob1->deleteNode(ch);
    if(r_first!=ob1)
    {
        ob1=r_first;
    }
    cout<<"Enter Traversing Method:"<<endl<<"1: Forward Traverse"<<endl<<"2: Backward Traverse"<<endl<<"Enter Choice:";
    cin>>trav;
    ob1->traverse(trav);
    return 0;
}
