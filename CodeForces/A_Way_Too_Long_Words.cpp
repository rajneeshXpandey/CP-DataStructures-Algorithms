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
        string s;
        cin>>s;
        int size= s.size();
        if(size > 10)
        {  
            string  mid = to_string(size-2);
            string ans = s[0]+mid+s[size-1];
            cout<<ans<<endl;
        }
        else
        {
              cout<<s<<endl;
        }

    }
    return 0;
}