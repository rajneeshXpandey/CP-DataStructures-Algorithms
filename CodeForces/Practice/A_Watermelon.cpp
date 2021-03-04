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

    if(t == 2)
    {
        cout<<"NO"; 
    }
     else{    if(t%2==0)
          cout<<"YES";
        else{
              cout<<"NO";
            }  }
    return 0;
}