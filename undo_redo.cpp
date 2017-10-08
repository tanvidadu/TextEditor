#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

struct node
{
    char info[100000];
    node *next;
    node *prev;
    ~node(){
        if(next!=NULL){
            delete next;
            next = NULL;
        }
    }

};

class dqueue
{
    public:
        node *head,*tail;
        int top;   ///counts no of elements in dqueue
        void insert(char value[]);
        void delstart();
        void delend(char val[]);
        void display();
        dqueue()
        {
            top = 0;
            head = NULL;
            tail = NULL;
        }

    ~dqueue(){
        if(head!=NULL){
            delete head;
            head = NULL;
            top=0;
        }
    }
};

void dqueue::insert(char value[])
{
    struct node *temp;
    int ch;
    if (top == 11)
        delstart();

    if (top == 0)
    {
        head = new (struct node);
        strcpy(head->info, value);
        head->next = NULL;
        head->prev = NULL;
        tail = head;
    }
    else
    {
                temp = new (struct node);
                strcpy(temp->info, value);
                temp->next = NULL;
                temp->prev = tail;
                tail->next = temp;
                tail = temp;
    }
    top++;

}


void dqueue::delstart()
{
    if (top<= 0)
        return;
            struct node * temp = head;
            head = head->next;
            head->prev = NULL;
            temp->next = NULL;
            delete temp;
            top--;
}
void dqueue::delend(char val[])
{
    if (top<= 0)
        return;
            struct node * temp ;
            strcpy(val,tail->info);
            temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            temp->prev = NULL;
            delete temp;
            top--;
}

void dqueue::display()
{
    struct node *temp;
    int ch;
    if (top<= 0)
    {
        cout<<"Deque Underflow"<<endl;
        return;
    }
            temp = head;
            while (temp != NULL)
            {
                cout<<temp->info<<"\n";
                temp = temp->next;
            }
            cout<<endl;
}
 void Undo(char a[],long &i, dqueue *dl, dqueue *redo)
{
    if( a[i-1] != ' ')
    {
        if (strcmp(dl->tail->info,a))
    dl->insert(a);
    }
    char temp[100000];
    if (dl->top-1)
    {
        dl->delend(temp);
        system ("cls");

        cout<<dl->tail->info;
        i=strlen(dl->tail->info);
        strcpy(a,dl->tail->info);
        a[i]='\0';
        redo->insert(temp);
    }
}
void Redo(char a[],long &i, dqueue *dl, dqueue *redo)
{
            char temp[100000];
            if (redo->top){
            redo->delend(temp);
            system ("cls");
            cout<<temp;
            strcpy(a,temp);
            i=strlen(temp);
            a[i]='\0';
            dl->insert(temp);}
}
int main()
{
    dqueue *dl=new dqueue,*redo=new dqueue;
    long i=0;
    char a[100000],ch;
    while (1)
    {
        ch=_getch();
        switch(ch)
        {

        case 25: Redo(a,i,dl,redo); break;
        case 26: if (dl->top)
                        Undo(a,i,dl,redo);
                 break;
        case 27: a[i]='\0';
                dl->insert(a);
                delete redo;
                delete dl;
                return 0;
        case ' ':
        case '\t':
        case '\n':     dl->insert(a);
                    a[i++]=ch;
                    a[i+1]='\0';
                    cout<<ch;
                    if( ch == '\n')
                    {
                        cout<<endl;
                    }
                    if (redo->top)
                    delete redo;
                    break;
        default:    a[i++]=ch;
                    a[i+1]='\0';
                    cout<<ch;
                    if (redo->top)
                    delete redo;
                    break;
        }

    }

}

/**ASCII VALUES
27- ESCAPE-EXIT
26- CTRL Z-UNDO
25- CTRL Y-REDO
6-  CTRL F-FIND
24- CTRL X-CUT
3-  CTRL C-COPY
22- CTRL V-PASTE
17- CTRL Q-INSERT
23- CTRL W-DELETE
18- CTRL R-REPLACE ONE
20- CTRL T-REPLACE ALL
5-  CTRL E-SHOW COPIED STRING
**/
