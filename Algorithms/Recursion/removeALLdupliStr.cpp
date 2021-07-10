#include <bits/stdc++.h>
using namespace std;

string removeDuplicates(string st)
{
    if(st == "")
      return "";
     string temp = removeDuplicates(st.substr(1));
   if (st[0] == temp[0])
       return temp;
   else
   {
       return (st[0] + temp);
    }  
}

int main()
{

    int t = 1;
    //cin>>t;
    while (t--)
    {
        cout<<removeDuplicates("aabcc")<<endl;
    }

    return 0;
}
