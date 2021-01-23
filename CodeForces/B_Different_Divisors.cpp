#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)

using namespace std;
using ll = long long;

bool isprime(int n){
    if(n==2)
    return true;
    for (size_t i = 2; i < n; i++)
    {
        if(n%i==0)
         return false;
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
        ll d;
        cin>>d;
        int p1 = 1+d;
        int ans;        
        while(isprime(p1)==false) 
                p1++;
        int p2 = p1+d;
         while (isprime(p2) == false)
            p2++;      
        ans = p1*p2;
        cout<<ans<<endl;
        
    }
    return 0;
}