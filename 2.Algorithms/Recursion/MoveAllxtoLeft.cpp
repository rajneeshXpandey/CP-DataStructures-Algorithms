#include <bits/stdc++.h>
using namespace std;

string moveXtoleft(string st)
{
    if(st=="")
    return "";

     string nextsub = moveXtoleft(st.substr(1));
     if(st[0]=='x')
     {
        return (nextsub +st[0]);  
     }
     else{
         return st[0]+nextsub;
     }

}

int main()
{


    int t = 1;
    //cin>>t;
    while (t--)
    {
        cout<<moveXtoleft("axxbdxcefxhix");
    }

    return 0;
}
