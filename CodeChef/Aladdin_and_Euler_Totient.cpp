#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)

using namespace std;
using ll = long long;
ll subsum(int i);
int eulerPhi(int n);
int M=pow(10,9)+7;


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
        ll a = n*(n+1);
        ll b = (2*n+4);

         cout<<(a%M*b%M)%M/12<<endl;
     
    }
    return 0;
}