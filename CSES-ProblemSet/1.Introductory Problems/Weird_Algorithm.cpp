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
        long long n;
        cin>>n;
        cout<<n<<" ";
        while(n>1)
        {
           if(n%2==0)
             { n = n/2;
             cout<<n<<" ";
             }
            else{
                n = n*3+1;
                cout<<n<<" ";
            }   
        }
    
        cout<<'\n';
    }
    return 0;
}