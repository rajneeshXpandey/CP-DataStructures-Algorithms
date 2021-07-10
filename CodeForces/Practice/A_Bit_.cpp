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
    int t=1;
    //cin>>t;
    while(t--){
        int n;
        cin>>n;
        int x=0;
        for (size_t i = 0; i < n; i++)
        {
            string s;
             cin>>s;
            if(s=="++X" or s=="X++")
              x++;
            else if (s == "--X" or s == "X--")
                x--;             
        }
        cout<<x<<endl;
    }
    return 0;
}