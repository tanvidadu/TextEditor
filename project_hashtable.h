#include<bits/stdc++.h>
using namespace std;

void Hashtable ( unordered_map<int , bool > &m)
{
     unordered_map<int , bool > m;
     ///Inserting Values
    m[26] = true; ///ctrl+z : UNDO
    m[25] = true; ///ctrl+y: REDO
    m[3] = true; ///ctrl+c : COPY
    m[24] = true; ///ctrl+x : CUT
    m[22] = true ; ///ctrl+v : PASTE
    m[18] = true; ///ctrl+r : REPLACE
    m[19] = true; ///ctrl+s : SAVE
    m[5] = true; ///ctrl+e : COPIED STRING
    m[4] = true; ///SEARCH
    m[27] = true; ///ESCAPE : EXIT
    m[6]  = true; ///ctrl+f : FIND
    m[17] = true; ///ctrl+q : INSERT
    m[20] = true; ///ctrl+t : REPLACE ALL
    m[23] = true; ///ctrl+w : DELETE
    m[32] = true; ///space
    m[13] = true; ///enter
    for( int i = 48 ; i <= 57 ; i++)
    {
        m[i] = true;
    }
    for( int i = 65 ; i <= 90 ; i++)
    {
        m[i] = true;
    }
    for( int i = 92 ; i <= 122 ; i++)
    {
        m[i] = true;
    }

    return 0;
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
