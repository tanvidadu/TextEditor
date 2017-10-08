#include<bits/stdc++.h>
using namespace std;

class Treenode
{
public:
    int data;
    Treenode * left;
    Treenode * right;

    Treenode(int d)
    {
        data = d;
        left = right = NULL;
    }
};

class Tree
{
public:
    Treenode * root;
    Tree()
    {
        root = NULL;
    }

    void LevelOrderInput()
    {
        int ele;
        cout<<"Enter root info : ";
        cin>>ele;
        cout<<" \n Enter -1 to make its child a Null quantity\n";
        Treenode * temp = new Treenode(ele);
        root = temp;
        queue<Treenode * > q;
        q.push(root);
        while( q.empty() == false)
        {

            int d1  ,d2;
            Treenode * f = q.front();
            q.pop();
            cout<<"\n Enter left child of "<<f->data<<" : ";
            cin>>d1;
            cout<<" Enter right child of " << f->data<<" : ";
            cin>>d2;
            if(d1 != -1)
            {
                Treenode * lchild = new Treenode(d1);
                f->left = lchild;
                q.push(f->left);
            }
            if( d2 != -1)
            {
                Treenode * rchild = new Treenode(d2);
                f->right = rchild;
                q.push(f->right);
            }
        }
    }
};

void Inorder( Treenode * root)
{
    cout<<endl<<" The Inorder Traversal output is "<<endl;
    stack<Treenode * > s;
    s.push(nullptr);
    Treenode * ptr = root;

    do
    {
        while( ptr != NULL)
        {
            s.push(ptr);
            ptr = ptr->left;
        }
        ptr = s.top();
        s.pop();
        bool flag = true;
        while( ptr != NULL && flag != false)
        {
            cout<<ptr->data << " ";
            if(ptr->right == NULL)
            {
                ptr = s.top();
                s.pop();
            }
            else
            {
                ptr = ptr->right;
                flag = false;
            }

        }
    } while( s.empty() == false);
    cout<<endl;
}

int main()
{
    Tree tt;
    tt.LevelOrderInput();
    Inorder(tt.root);
    return 0;
}
