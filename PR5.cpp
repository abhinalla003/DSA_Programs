//Write a program to implement linked list and have function to traverse and append node in list
//Created on 07-02-2023
//Created by 22CP319
#include<iostream>
using namespace std;
class ll
{
    int info;
    ll *next;
public:
    ll(){}
    ll(int data)
    {
        info=data;
        next=NULL;
    }
    void traverse()
    {
        ll *tp=this;
        while(tp!=NULL)
        {
            cout<<"Data: - "<<tp->info<<endl;
            tp=tp->next;
        }
    }
    void append(ll *newnode)
    {
        ll *tp=this;
        while(tp->next!=NULL)
        {
            tp=tp->next;
        }
        tp->next=newnode;
    }
    void insertNode(ll *newnode, int value)
    {
        ll *tp=this;
        while(tp->info!=value)
            tp=tp->next;
        newnode->next=tp->next;
        tp->next=newnode;
    }
    ll* deleteNode(int value)
    {
        ll *tp=this;
        ll*prev=NULL;
        while(tp->info!=value)
        {
            prev=tp;
            tp=tp->next;
        }
        if(tp==this)
        {
            ll *r_first=tp->next;
            delete tp;
            return r_first;
        }
        else
        {
            prev->next=tp->next;
            delete tp;
            return this;
        }
    }
};
int main()
{
    ll *ob1=new ll(5);
    //ob->traverse();

    ll *ob2=new ll(10);
    ob1->append(ob2);
    //ob1->traverse();

    int ch;
    cout<<"Enter Value after which you want to insert:";
    cin>>ch;
    ll *ob3=new ll(15);
    ob1->insertNode(ob3,ch);
    ob1->traverse();

    cout<<"Enter Deleting Value:";
    cin>>ch;
    ll *r_first=ob1->deleteNode(ch);
    if(r_first!=ob1)
    {
        ob1=r_first;
    }
    ob1->traverse();
    return 0;
}
