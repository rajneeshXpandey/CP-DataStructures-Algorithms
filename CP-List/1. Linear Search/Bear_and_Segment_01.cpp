#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)

using namespace std;
using ll = long long;

bool count (string st,int i,int n)
{ int c =0;
    for(int j=i;j<n;j++)
     {
         if(st[j]=='1')
             c++;
     }
    
    return (c==0);
}
bool segment(string st)
{
    if(count(st,0,st.length()))
          return false;
    for(auto i=0;i<st.length();i++)
           {
              if(st[i] == '1')
              {
                 if(st[i+1]== '0' && !(count(st,i+1, st.length())))
                     return false;
              }
              
           }
           return true;
}

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
        if(segment(st))
         cout<<"YES";
       else cout<<"NO";
        cout<<'\n';
    }
    return 0;
}