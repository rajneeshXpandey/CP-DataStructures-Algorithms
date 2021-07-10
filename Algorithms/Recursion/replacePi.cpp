#include <bits/stdc++.h>
using namespace std;

void replacePi(string st)
{
   //base case
    if(st.length()==0)
     return;

     //checking condition
    if(st[0]=='p' and st[1]=='i')
      {
          cout<<"3.14";
          //calling
          replacePi(st.substr(2));
      } 
    else
    {
        cout<<st[0];
        //calling
        replacePi(st.substr(1));
    }
      
}

int main()
{
    int t = 1;
    //cin>>t;
    while (t--)
    {
        string st = "piippipiiiiipp";
        replacePi(st);
    }

    return 0;
}
