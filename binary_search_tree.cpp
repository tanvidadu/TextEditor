#include<bits/stdc++.h>
using namespace std;


class Treenode
{
public:
    int info;
    Treenode * left;
    Treenode * right;

    Treenode(int d)
    {
        info = d;
        left = right = NULL;
    }

};

Treenode*  Search ( Treenode * root , int ele , int mode = 0 );

class Tree
{
public:
    Treenode * root;

    Tree()
    {
        root = NULL;
    }

    void Insert ( int ele)
    {
        Treenode * temp = new Treenode(ele);
        if( root == NULL)
        {
            root = temp;
        }
        else

        {

         Treenode * par = Search( root , ele , 1);
        {
            if( par->info > ele)
            {
                par->left = temp;
            }
            else
            {
                par->right = temp;
            }
        }
        }
    }


     void DeleteA ( Treenode * temp , Treenode * par )
 {


        Treenode * child;
     if(temp-> left == NULL && temp-> right == NULL)
     {
         child = NULL;
     }
     else if ( temp-> left == NULL )
     {
         child = temp->right;
     }
     else if ( temp-> right == NULL)
     {
         child = temp->left;
     }

     if( par == NULL)     {
         root = child;
     }
     else
     {
         if( par-> left == temp)
         {
             par->left = child;
         }
         else
         {
             par->right = child;
         }
     }

 }
 void DeleteB (  Treenode * ptr , Treenode * par )
 {
     Treenode * suc , * sucpar;
     suc = ptr->right;
     sucpar = ptr;
     while( suc->left != NULL)
     {
         sucpar = suc;
         suc = suc->left;
     }
     DeleteA(suc , sucpar);
     if( par == NULL)
     {
         root = suc;
     }
     else
     {
         if( par->left == ptr)
         {
             par->left = suc;
         }
         else
         {
             par->right = suc;
         }
     }
     suc->left = ptr->left;
     suc->right = ptr->right;
 }

 void Delete( int ele)
 {
     Treenode * temp = Search( root , ele , 0);
     Treenode * par = Search( root , ele, 2);
     if( temp == NULL)
     {
         cout<<"Item doesn't exist"<<endl;
         return;
     }
     else
     {
         if( temp->left != NULL && temp->right != NULL)
         {
             DeleteB( temp , par);
         }
         else
         {
             DeleteA(temp , par);
         }
     }
 }
};

Treenode*  Search ( Treenode * root , int ele , int mode )  ///mode 1 : insert ; 0 : search ; 2: delete
{
    Treenode * par  = NULL;
    Treenode *  node = root;
    if( root == NULL)
    {
        return NULL;
    }
    while( node != NULL)
    {
        if( node->info > ele)
        {
            par = node;
            node = node->left;

        }
        else if ( node->info == ele)
        {
            if( mode == 0  )
            {
                return node;

            }
            else if ( mode == 2)
            {
                return par;
            }
        }
        else
        {
            par = node;
            node = node->right;
        }
    }
    if( mode == 1)
    {
        return par;
    }
    else
    {
        return NULL;
    }
}

void Preorder ( Treenode * root)
{
    stack<Treenode*> s;
    s.push ( NULL);
    Treenode * ptr = root;
    while( ptr != NULL)
    {
        cout<<ptr->info<<" ";
        if( ptr-> right != NULL)
        {
            s.push( ptr->right);
        }
        if( ptr-> left != NULL)
        {
            ptr = ptr->left;
        }
        else
        {
            ptr = s.top();
            s.pop();
        }
    }

    cout<<endl;
}

void Inorder ( Treenode * root)
{
    stack<Treenode * > s;
    s.push( NULL);
    Treenode * ptr = root;
    int count = 0;
    do

        {
        while( ptr != NULL)
    {
        s.push( ptr);
        ptr = ptr->left;
    }
    ptr = s.top();
    s.pop();

    bool d = true;
    while( ptr != NULL && d == true)
    {
        cout<<ptr->info<<" ";
        count++;
        if( ptr->right == NULL)
        {

            ptr = s.top();
            s.pop();
        }
        else
        {
            ptr = ptr->right;
            d = false;
        }
    }
    }while( !s.empty());
    cout<<endl;

}

void Postorder ( Treenode * root)
{
    stack< pair< Treenode * , bool > > s; /// true - node , false - right

    Treenode * ptr = root;
    s.push( make_pair(nullptr , true));
    int count = 0;
    while (count < 7)
    {
        while( ptr != NULL)
    {
        s.push( make_pair(ptr , true));
        if( ptr-> right != NULL)
        {
            s.push( make_pair( ptr->right , false));
        }
        ptr = ptr->left;
    }
    pair < Treenode * , bool > x = s.top();
    s.pop();
    ptr = x.first;
    while( x.second == true)
    {
        cout<<x.first->info<<" ";
        count++;
        x = s.top();
        s.pop();
        ptr = x.first;
    }
    if( x.second == false)
    {
        x.second = true;
    }
    }
    cout<<endl;
}


int main()
{
    Tree tt;
    tt.Insert(10);
    tt.Insert(5);
    tt.Insert(17);
    tt.Insert(16);
    tt.Insert(20);
    tt.Insert(3);
    tt.Insert(6);

    Preorder( tt.root);
    Inorder( tt.root);
    //Postorder(tt.root);
    int ele;
    cin>>ele;
    //tt.Delete(ele);
    //Postorder(tt.root);
}
