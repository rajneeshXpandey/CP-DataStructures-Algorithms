#include <bits/stdc++.h>
using namespace std;

string keypadArr[]={"","./","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void KeyPad(string st,string ans)
{
      if(st=="")
       {
           cout<<ans<<endl;
           return ;
       }
     
     string code = keypadArr[st[0]-'0'];

     for (size_t i = 0; i < code.length(); i++)
     {
         KeyPad(st.substr(1),ans+code[i]);
     }

}

int main()
{
    int t = 1;
    //cin>>t;
    while (t--)
    {
        KeyPad("234","");
    }

    return 0;
}
