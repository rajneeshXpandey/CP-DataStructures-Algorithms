#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)

using namespace std;
using ll = long long;

int countone(int a[],int n)
{
    int count=0;
    for (size_t i = 0; i < n; i++)
    {
        if(a[i])
         count++;
    }
    return count;   
}

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
        int v[n][3];
        int ans =0;
        for (size_t i = 0; i < n; i++)
        {
           cin>>v[i][0]>>v[i][1]>>v[i][2];  
           int count = countone(v[i],3);
           if(count>=2)
             ans++;
        }
        
        cout<<ans<<endl;
    }
    return 0;
}