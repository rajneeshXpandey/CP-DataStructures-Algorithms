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
        int n;
        cin>>n;
        ll st= -(10e10+2);
        ll en = 10e10 + 2;
        int c=0;
        for (size_t i = 0; i < n; i++)
        { 
            char query;
            ll x;
            cin>>query>>x;
            if(query=='L'){
                if(x<en)
                  {en = x;c++} 
            }
            else if(query=='R'){
                if(x>st)
                  {st = x;c++}   
            }
        }
          if(en-st-1 >0)
           cout<<(en-st-1)<<endl;
          else
          {
               cout<<"-1"<<endl;
          }
           
    }
    return 0;
}