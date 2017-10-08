#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <cstring> //not <string>
#include "project_undo_redo.h"
#include "printScreen.h"

using namespace std;
WORD GetConsoleTextAttribute (HANDLE hCon)
{
  CONSOLE_SCREEN_BUFFER_INFO con_info;
  GetConsoleScreenBufferInfo(hCon, &con_info);
  return con_info.wAttributes;
}
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
const int saved_colors = GetConsoleTextAttribute(hConsole);

void Hashtable ( unordered_map<int , bool > &m)
{

     ///Inserting Values
    m[26] = true; ///ctrl+z : UNDO
    m[25] = true; ///ctrl+y: REDO
    m[3] = true; ///ctrl+c : COPY
    m[24] = true; ///ctrl+x : CUT
    m[22] = true ; ///ctrl+v : PASTE
    m[18] = true; ///ctrl+r : REPLACE
    m[19] = true; ///ctrl+s : SAVE
    m[5] = true; ///ctrl+e : COPIED STRING
    m[27] = true; ///ESCAPE : EXIT
    m[6]  = true; ///ctrl+f : FIND
    m[17] = true; ///ctrl+q : INSERT
    m[20] = true; ///ctrl+t : REPLACE ALL
    m[23] = true; ///ctrl+w : DELETE
    m[32] = true; ///space
    m[13] = true; ///enter
    m[10] = true; ///newline
    m[9] = true; ///tab
    for( int i = 33 ; i <= 126 ; i++)
    {
        m[i] = true;
    }


}


int recur6(char *test,char subStr[], char *p, int &z)
{
    int x=strlen(subStr),y=3;
    char *pCurrent = strstr( p, subStr ); ///left over string for find
    if (pCurrent==NULL)    ///end of string
        return 2;
        int o=1;
        string s(test),u(pCurrent);
        s = s.substr(0, s.size() - u.size());
        while (o==1 && (y!=2 || y!=1)){
        ///system("cls");
        PrintScreen();
        cout<<s;    ///print screen in white
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        cout<<subStr; ///print screen in blue
        SetConsoleTextAttribute(hConsole, saved_colors);
        cout<<pCurrent+x; ///print again in white
        y=_getch();
        y-=48;
        if (y==2){  ///to move to next word
        pCurrent++;
        o=recur6 (test,subStr,pCurrent,z);
        if (o==1)     ///to move to previous word
            pCurrent--;
        }
        if (y==1)     ///starting of file
            return 1;
        if (y==-35)     //-35 stands for enter in _getch
        {
            z=strlen(test)-strlen(pCurrent);
            return 2;
        }
        }
        return 2;
}
void cut(char* test, char *extra,int Copy,int Delete, int &f)
{
    char subStr[100];
    int z=-1;
    ///system("cls");
    PrintScreen();
    cout<<test<<endl;
    if (Delete)
    cout<<"Enter substring to be deleted- ";
    else if (Copy)
    cout<<"Enter substring to be copied- ";
    else
    cout<<"Enter substring to be cut- ";
    gets(subStr);
    if(strlen(subStr)){    ///agar enter press kia to kya fayda dhundne ka! ulta extra ko bi khaali kar jaaega
    char *pCurrent = strstr( test, subStr );
    if (pCurrent==NULL)
        {cout<<"Not Found";      /// to check whether string exists
        getch();}
    else{
        int q=recur6(test,subStr,test,z); ///to find the required string
        if (q==1)
            {cout<<"\nReached start of Document."; getch();}
        if (q==2 && z==-1)
            {cout<<"\nReached end of Document."; getch();}
            if (z>-1)
                {
                    if (Delete==0) /// no to deleted or to store the substring in extra
                    strcpy(extra,subStr);
                    if (Copy==0){ ///to delete the string from text editor
                    int i,j;
                    j=z;
                    i=z+strlen(subStr);
                    for (;test[i];i++,j++)
                        test[j]=test[i];
                        system("cls");
                        test[j]='\0';}
                    if (!Delete)   /// extra has been copied
                     f=1;
                }
        }

}
}
void find(char *test)
{
    char subStr[100];
    int z=-1;
    ///system("cls");
    PrintScreen();
    cout<<test<<endl;
    cout<<"Enter substring to be found- ";
    gets(subStr);
    if(strlen(subStr)){
    char *pCurrent = strstr( test, subStr ); ///check it substring exist before passing to recur6
    if (pCurrent==NULL)
        {cout<<"Not Found";
        getch();}
    else{
        int q=recur6(test,subStr,test,z);
        if (q==1)
            {cout<<"\nReached start of Document."; getch();}
        if (q==2 && z==-1)
            {cout<<"\nReached end of Document."; getch();}

        }

}}
void paste(char *test,char *extra)
{
     char subStr[100],start[]="~~";
    int z=-1;
    ///system("cls");
    PrintScreen();
    cout<<test<<endl;
    cout<<"Enter substring after which pasting needs to be done (enter \"~~\" if want to paste in beginning)- ";
    gets(subStr);
    if (!strcmp(subStr,start)) /// if begining of the file
    {
        int i,j,k=0;
        string q(test);
        i=j=0;
        for (;extra[k];k++,i++)
            test[i]=extra[k];
        for (;q[j];i++,j++)
            test[i]=q[j];
        test[i]='\0';
    }
    else if(strlen(subStr)){        /// check to ensure string contains a value
        char *pCurrent = strstr( test, subStr );
    if (pCurrent==NULL)
        {
            cout<<"Not Found";
            getch();
        }
    else{
        int q=recur6(test,subStr,test,z);
        if (q==1)
            {cout<<"\nReached start of Document."; getch();}
        if (q==2 && z==-1)
            {cout<<"\nReached end of Document."; getch();}
            if (z>-1)
                {
                    string q(test);
                    int i,j,k=0;
                    i=j=(z+strlen(subStr));
                    for (;extra[k];k++,i++)
                        test[i]=extra[k];
                    for (;q[j];i++,j++)
                        test[i]=q[j];
                    test[i]='\0';
                }
        }


}
}
void Replace1(char test[],char subStr[],char sub2[])
{
    int z=-1;
    char *pCurrent = strstr( test, subStr ); ///to find the required string
    if (pCurrent==NULL)
        {
            cout<<"Not Found";
            getch();
            }
    else{
        int q=recur6(test,subStr,test,z);
        if (q==1)
            {cout<<"\nReached start of Document."; getch();}
        if (q==2 && z==-1)
            {cout<<"\nReached end of Document."; getch();}
            if (z>-1)  /// string found and its index is in z
                {
                    string q(test);
                    int i,j,k=0;
                    i=j=z;
                    for (;sub2[k];i++,k++)
                        test[i]=sub2[k];
                    j+=strlen(subStr);
                    for (;q[j];j++,i++)
                        test[i]=q[j];
                    test[i]='\0';

                }
        }

}
void ReplaceAll(char test[],char subStr[],char sub2[])
{
    char *pCurrent = strstr( test, subStr ); ///to find the string in test
    while (pCurrent){ ///loop for repetitive words
        int z=strlen(test)-strlen(pCurrent);
                    string q(test);
                    int i,j,k=0;
                    i=j=z;
                    for (;sub2[k];i++,k++)
                        test[i]=sub2[k];
                    j+=strlen(subStr);
                    for (;q[j];j++,i++)
                        test[i]=q[j];
                    test[i]='\0';
        pCurrent = strstr( test, subStr );

}}
void replacecommon(char subStr[],char sub2[],char test[])
{
    ///system("cls");
    ///PrintScreen();
    cout<<endl;
    cout<<"Enter substring to be replaced- ";
    gets(subStr);
    cout<<"Enter substring to replace previous substring- ";
    gets(sub2);
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
        dl->delend(temp); ///
        ///system ("cls");
        PrintScreen();
        cout<<dl->tail->info; ///print previous string
        i=strlen(dl->tail->info);
        strcpy(a,dl->tail->info); ///change a
        a[i]='\0';
        redo->insert(temp); ///move original to redo dequeue
    }
}
void Redo(char a[],long &i, dqueue *dl, dqueue *redo)
{
            char temp[100000];
            if (redo->top){
            redo->delend(temp);
            ///system ("cls");
            PrintScreen();
            cout<<temp; ///print string from redo
            strcpy(a,temp); ///change a
            i=strlen(temp);
            a[i]='\0';
            dl->insert(temp); ///move to undo dequeue
            }
}
int main()
{
    ///PrintScreen();
    unordered_map<int , bool > m;
     Hashtable(m);
    char *test = new char [100000] ; ///original string
    int f=0; ///f=flag for empty "extra"
    char r; ///to take individual character
    long int i = 0 ; ///to keep count of test
    test[i] = '\0';
    char *extra=new char[100]; ///stores string after cut and copy operations
    char *subStr=new char[100]; ///string to be found
    char *sub2=new char[100];
    dqueue *dl=new dqueue,*redo=new dqueue;
    ///long i=0;
    ///char a[100000],ch;
    ///Trie tree;
    while (1){
    ///system("cls");
    PrintScreen();
    cout<<test;
    r=_getch();
    if( m.count(r)>0)
    {
        switch(r)
    {
        case 6: find(test); break;                ///find

        case 24: cut(test,extra,0,0,f);
                  dl->insert(test);
                  if (redo->top)
                    delete redo;
                  break;     ///cut
        case 3: cut(test,extra,1,0,f);
                  break;     ///copy
        case 23: cut(test,extra,0,1,f);
                 dl->insert(test);
                 if (redo->top)
                    delete redo;
                 break;     ///delete
        case 22: if (f)                            ///paste
                    paste(test,extra);
                else
                    {cout<<"Nothing to paste."; getch(); }
                    dl->insert(test);
                break;
        case 17: char extra2[100];                 ///insert
                cout<<"Enter subtring to be inserted- ";
                gets(extra2);
                paste(test,extra2);
                dl->insert(test);
                if (redo->top)
                    delete redo;
                break;
        case 18:                                   ///Replace one
            replacecommon(subStr,sub2,test);
            if(strlen(subStr) && strlen(sub2))
                Replace1(test,subStr,sub2);
                dl->insert(test);
                if (redo->top)
                    delete redo;
            break;
        case 20:                                   ///Replace all
            replacecommon(subStr,sub2,test);
            if(strlen(subStr) && strlen(sub2))
                ReplaceAll(test,subStr,sub2);
                dl->insert(test);
                if (redo->top)
                    delete redo;
            break;
        case 5: if (f)                            ///show copied string
                    {cout<<extra; getch();}
                else
                    {cout<<"Nothing to show."; getch(); }
                break;
        case 27:                                   ///exit
            delete [] test; delete [] subStr; delete [] sub2; delete [] extra;
            test[i]='\0';
                dl->insert(test);
                delete redo;
                delete dl;

            return 0;
            break;
        case 25: Redo(test,i,dl,redo); break;
        case 26: if (dl->top)
                Undo(test,i,dl,redo);
                 break;
        case ' ':
        case '\t':
        case '\n':
                    if( test[i-1] != ' ' && test[i-1] != '\n' && test[i-1] != '\t')
                    {
                        dl->insert(test);
                    }
                    test[i]=r;
                    test[++i]='\0';
                    ///system("cls");
                    PrintScreen();
                    cout<<test;
                    if (redo->top)
                    delete redo;
                    break;
        default : test[i] = r;
                  i++;
                  test[i] = '\0';
                  ///system("cls");
                  ///PrintScreen();
                  cout<<test;
                  if (redo->top)
                    delete redo;
                    break;
    }
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
