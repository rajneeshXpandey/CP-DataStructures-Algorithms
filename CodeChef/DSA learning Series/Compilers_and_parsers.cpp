#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        string st;
        cin>>st;
        int o=0;
        int c=0;
        int l=0;
        for (int i = 0; i < st.size(); i++)
        {
           if(o>=c)
           { if (st[i] == '<')
                o++;
            else if (st[i] == '>')
                c++;
           }
            if (c==o)
                l = i + 1;
            if (c > o)
                break;
        }   
        cout<<l<<endl;
    }
    return 0;
}