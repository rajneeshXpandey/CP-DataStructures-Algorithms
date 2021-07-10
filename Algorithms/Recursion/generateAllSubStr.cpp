#include <bits/stdc++.h>
using namespace std;

void substringASCII(string st, string ans)
{
    if (st.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    int ascii = st[0];
    substringASCII(st.substr(1), ans);
    substringASCII(st.substr(1), ans + st[0]);
    substringASCII(st.substr(1), ans + to_string(ascii));
}

void substring(string st,string ans)
{
    if(st.length()==0)
    {
        cout << ans << endl;
        return;
    }
      substring(st.substr(1), ans);
      substring(st.substr(1),ans + st[0]);
}

int main()
{


    int t = 1;
    //cin>>t;
    while (t--)
    {
          substring("raj","");
          substringASCII("ab","");
    }

    return 0;
}
