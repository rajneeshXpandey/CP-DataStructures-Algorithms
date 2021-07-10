#include <bits/stdc++.h>

#define rep(i,n) for(int i=1;i<=(n);++i)


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

        int idx[200001];
        memset(idx,0,sizeof(idx));
        for (size_t i = 1; i <= n; i++)
        {
            idx[v[i]]++;
        }
        int j=1;
        while (1)
        {
            if(idx[j]==0)
              {cout<<j<<endl;
              break;}
           j++;   
        }
        

    return 0;
}