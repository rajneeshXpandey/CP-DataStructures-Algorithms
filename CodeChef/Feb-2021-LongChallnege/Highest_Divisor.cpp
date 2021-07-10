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
    while(t--){
        int n;
        cin>>n;

        for (size_t i = 10; i >=1 ; i--)
        {
            if(n%i==0)
             {cout<<i<<endl;
             break;
             }
        }

    }
    return 0;
}