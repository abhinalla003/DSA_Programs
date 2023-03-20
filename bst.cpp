//Implement Binary Search Tree. Define functions like traversal, searching.
//Created on: 14-03-2023
//Created by 22CP319
#include<iostream>
using namespace std;
class bst {
    int info;
    bst *right;
    bst *left;
public:
    bst() {}
    bst(int val) {
        info=val;
        right=left=NULL;
    }
    void insertNode(int val) {
        bst *newNode=new bst(val);
        bst *tp=this;
        if(tp->info>val)
        {
            if(tp->left==NULL)
            {
                tp->left=newNode;
            }
            else
            {
                tp=tp->left;
                tp->insertNode(val);
            }
        }
        else if(tp->info<val)
        {
            if(tp->right==NULL)
            {
                tp->right=newNode;
            }
            else
            {
                tp=tp->right;
                tp->insertNode(val);
            }
        }
    }

    void searchNode(int val) {
        bst *tp=this;
        static int cnt=0;
        if(tp->info==val) {
            cout<<"Value is in BST..."<<endl;
            cout<<"Level of BST is "<<cnt<<"..."<<endl;
        }
        else {
            if(tp->info>val)
            {
                tp=tp->left;
                if(tp==NULL)
                    cout<<"Value is not in BST..."<<endl;
                else
                {
                    cnt++;
                    tp->searchNode(val);
                }
            }
            if(tp->info<val)
            {
                tp=tp->right;
                if(tp==NULL)
                    cout<<"Value is not in BST..."<<endl;
                else
                {
                    cnt++;
                    tp->searchNode(val);
                }
            }
        }
    }

    void traversal(bst *tmp)
    {
        int ch;
        cout<<"1 Inorder"<<endl;
        cout<<"2 Preorder"<<endl;
        cout<<"3 Postorder"<<endl;
        cout<<"4 Exit"<<endl;
        cout<<"Enter choice:";
        cin>>ch;
        switch(ch)
        {
        case 1:
            intrav(tmp);
            break;
        case 2:
            pretrav(tmp);
            break;
        case 3:
            posttrav(tmp);
            break;
        case 4:
            exit(0);
        }
    }
    void intrav(bst *tmp)
    {
        if(tmp==NULL)
            return;
        intrav(tmp->left);
        cout<<tmp->info<<endl;
        intrav(tmp->right);
    }
    void pretrav(bst *tmp)
    {
        if(tmp==NULL)
            return;
        cout<<tmp->info<<endl;
        pretrav(tmp->left);
        pretrav(tmp->right);
    }
    void posttrav(bst *tmp)
    {
        if(tmp==NULL)
            return;
        posttrav(tmp->left);
        posttrav(tmp->right);
        cout<<tmp->info<<endl;
    }
};
int main() {
    bst *root=new bst(5);
    int n,ch=1;
    while(ch>0)
    {
        cout<<endl<<"1. Add element in BST"<<endl;
        cout<<"2. Search value in BST"<<endl;
        cout<<"3. Traversal BST"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Enter Value: ";
                cin>>n;
                root->insertNode(n);
                break;
            case 2:
                cout<<"Enter Searching Value: ";
                cin>>n;
                root->searchNode(n);
                break;
            case 3:
                root->traversal(root);
                break;
            case 4:
                exit(0);
                break;
        }
    }
    return 0;
}
