#include<bits/stdc++.h>
using namespace std;

//    cout << fixed << setprecision(10);
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
#define pqmx            priority_queue<int> // maxheap
#define pqmn   priority_queue<int,vector<int>,greater<int>> //minheap
#define mod             1000000007
#define inf             100000000000000000 //1e17
#define Pi              acos(-1.0)
#define precise(x,y)    fixed<<setprecision(y)<<x
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

int dp[21][21];

int LCS(string a, string b)
{
    int n = a.size();
    int m = b.size();

   for (int i = 0; i <= n; i++)
   {
       for (int j = 0; j <= m; j++)
       {
           if(i==0 and j==0)
            dp[i][j]=0;
       }       
   }
   for(int i=1;i<=n;i++)
   {
       for (int j = 1; j <=m; j++)
       {
           
           if(a[i-1]==b[j-1])
            dp[i][j] = 1+dp[i-1][j-1];
           else
           {
               dp[i][j] = 0;
           }            
        }       
   }
   int mx = INT_MIN;
   for (int i = 0; i <= n; i++)
   {
       for (int j = 0; j <= m; j++)
       {
           mx = max(mx,dp[i][j]);
       }
   }

   return mx;
}


signed main()
{
    FIO;
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        string a,b;
        cin>>a>>b;
        // cout<<a<<" "<<b;
        // cout<<endl;
        int n = a.size();
        int m = b.size();
        memset(dp,0,sizeof(dp));
        int lcs = LCS(a,b);
        
        cout<<m+n-(2*lcs)<<endl;

    }
    return 0;
}