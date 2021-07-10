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

int dp[100001][3];

int vacation(int a[],int b[],int c[],int d,int n,char prevTask)
{
    if(prevTask=='A')
    {
        if(d==n)
          return 0;
        if(dp[d][0]!=-1)
          return dp[d][0];
    return dp[d][0] =max(b[d] + vacation(a, b, c, d + 1,n, 'B') ,c[d] + vacation(a, b, c, d + 1,n, 'C'));
    }
    else if(prevTask=='B')
    {
        if (d == n)
            return 0;
        if (dp[d][1] != -1)
            return dp[d][1];
       return dp[d][1] = max(a[d] + vacation(a, b, c,d+1, n, 'A') , c[d] + vacation(a, b, c, d+1,n, 'C'));
       
    }
    else
    {
        if (d == n)
            return 0;
        if (dp[d][2] != -1)
            return dp[d][2];
      return  dp[d][2] = max(a[d] + vacation(a, b, c,d+1, n , 'A'), b[d] + vacation(a, b, c, d+1,n , 'B'));
      
    }
}

signed main()
{
    FIO;
    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
      memset(dp,-1,sizeof(dp));
      int n;
      cin>>n;
      int a[n], b[n] , c[n];
      for (int i = 0; i < n; i++)
      {
          cin>>a[i]>>b[i]>>c[i];
      }
      
      vector<int> v(3);

      v.pb(a[0]+  vacation(a, b, c, 1,n, 'A'));
      v.pb(b[0] + vacation(a, b, c, 1,n,'B'));
      v.pb(c[0] + vacation(a, b, c, 1,n, 'C'));

      int max_point = *max_element(v.begin(), v.end());

      cout << max_point << endl;
       
    }
    return 0;
}