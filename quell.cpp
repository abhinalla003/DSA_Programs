#include<iostream>
using namespace std;
class node
{
public:
    node *prev;
    int info;
    node *next;
    node(int data)
    {
        info=data;
        prev=NULL;
        next=NULL;
    }
};
class que
{
    node *head;
    node *tail;
public:
    que()
    {
        head=tail=NULL;
    }
};
