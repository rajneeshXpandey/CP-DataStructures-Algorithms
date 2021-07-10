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
        int n,c;
        cin>>n>>c;
        vector<int> v(n);
        rep(i,n) cin>>v[i];
        int sum = 0;
        int i;
        for (size_t i = 0; i < n; i++)
        {
            sum += v[i];

        }
         if(sum<=c)
            cout<<"Yes"<<endl;
         else
            cout<<"No"<<endl;
         
         
    }
    return 0;
}