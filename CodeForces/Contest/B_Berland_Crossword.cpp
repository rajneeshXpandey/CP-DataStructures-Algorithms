#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define all(x)          (x).begin(), (x).end()
#define endl            "\n"
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define int             long long
#define pb              push_back
#define pii             pair<int,int>
#define setbits(x)      __builtin_popcountll(x)
#define zerbefone(x)    __builtin_ctzll(x)
#define pqmx             priority_queue<int> // maxheap
#define pqmn             priority_queue<int,vector<int>,greater<int> > // minheap
#define mod             1000000007
#define inf             100000000000000000 //1e17
#define Pi              acos(-1.0)
#define precise(x,y)    fixed<<setprecision(y)<<x
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main()
{
    FIO;
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin>>n;
        int iu,ir,id,il;
        cin>>iu>>ir>>id>>il;
        bool ok = false;
        for (int mask = 0; mask < 16; mask++)
        {
            int u=iu, r=ir, d=id, l=il;
            if (mask & 1)
            {
                u--;
                l--;
                  }
              if (mask & 2)
                  {
                      r--;
                      u--;
                  }
              if (mask & 4)
                  {
                      r--;
                      d--;
                  }
             if (mask & 8)
                  {
                      d--;
                      l--;
                  }
                  vector<int> minmax;
                  minmax.pb(u);
                  minmax.pb(r);
                  minmax.pb(d);
                  minmax.pb(l);

                  int mx = *max_element(minmax.begin(), minmax.end());
                  int mn = *min_element(minmax.begin(), minmax.end());

                  if (mn >= 0 and mx <= (n - 2))
                      {
                        ok = true;
                        break;
                      }
        }
       
       if(ok)cout << "YES" << endl;
       else
          cout << "NO" << endl;
    }
    return 0;
}