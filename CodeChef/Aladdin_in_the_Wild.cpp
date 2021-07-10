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
       
       stack<int> st;
       st.push(v[0]);
       for(int i=1;i<n;i++)
         {if(st.top()<v[i])
           st.push(v[i]);
           }

         cout<<st.size();
    
    return 0;
}