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
        ll k,d;
        cin>>n>>k>>d;
        vector<int> v(n);
        rep(i,n) cin>>v[i];

        ll sum = 0;

        rep(i, n) sum+=v[i];

         int numdays = 0;
          
        if(sum>=k)
         {
             numdays = sum / k;
             if(numdays>d)
              cout<<d<<endl;
             else
               cout<<numdays<<endl;
         }
         if(sum<k)
          {
              cout<<"0"<<endl;
          }
    }
    return 0;
}