#include <bits/stdc++.h>
using namespace std;

void reverse(string s)
{
    if(s.length()==0)
     return;  
    string temp = s.substr(1);
    reverse(temp); 
    cout<<s[0];
}

int main()
{

    string st = "binod";
    
    int t = 1;
    //cin>>t;
    while (t--)
    {
        reverse(st);
    }

    return 0;
}
