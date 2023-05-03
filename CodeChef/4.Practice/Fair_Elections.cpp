#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)

using namespace std;
using ll = long long;

int sum(int v[],int n)
{
    int sums = 0;
    for (size_t i = 0; i < n; i++)
    {
        sums += v[i];
    }

     return sums;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int jo[n];
        for (size_t i = 0; i < n; i++)
            cin >> jo[i];

        int ja[m];
        for (size_t i = 0; i < m; i++)
            cin >> ja[i];

        sort(jo,jo+n);
        sort(ja,ja+m);

            
            int sumo = sum(jo, n);
            int suma = sum(ja, m);
            int j = m-1;
            if(sumo>suma)
             cout<<"0"<<endl;
          else { int count = 0;
            for (int i = 0; i < n; i++)
            {
                sumo = sumo - jo[i] + ja[j];
                suma = suma + jo[i] - ja[j];
                count++;
                j--;
                if (sumo > suma or j < 0)
                    break;                  
                }
   
            if(sumo>suma)
              cout<<count<<endl;             
            else cout<<"-1"<<endl;
      }
        
    
    }
    return 0;
}