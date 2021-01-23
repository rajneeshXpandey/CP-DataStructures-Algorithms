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
  
        int n;
        cin>>n;
        vector<int> v(n);
        rep(i,n) cin>>v[i];
         int sum = 0;
           int count = 0;
           for(int i=0;i<n;i++)
             {
                 if(v[i]>0)
                  {sum += v[i];
                  count++;}
             }
             if(count==0)
             {
                 sum+=*max_element(v.begin(),v.end());
                 count++;
             }
         cout<<sum<<" "<<count; 
        cout<<'\n';
    
    return 0;
}