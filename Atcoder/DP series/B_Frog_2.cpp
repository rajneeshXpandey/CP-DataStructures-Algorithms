#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define int long long
#define pb push_back
#define pii pair<int, int>
#define setbits(x) __builtin_popcountll(x)
#define zerbefone(x) __builtin_ctzll(x)
#define pqmx priority_queue<int>                            // maxheap
#define pqmn priority_queue<int, vector<int>, greater<int>> // minheap
#define mod 1000000007
#define inf 100000000000000000 //1e17
#define Pi acos(-1.0)
#define precise(x, y) fixed << setprecision(y) << x
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int dp[100001];

int mincost(int arr[], int n ,int k)
{
    //base
    if(n<=k-1)
    {
        //base
        if (n == 0)
            return 0;
        if (n == 1)
            return abs(arr[0] - arr[1]);

        if (dp[n] != -1)
            return dp[n];

        vector<int> vec;

        for (int i = 1; i <= k-1; i++)
        {
            vec.pb(abs(arr[n] - arr[n - i]) + mincost(arr, n - i, k-1));
        }
        return dp[n] = *min_element(vec.begin(), vec.end());
    }
   
    if (dp[n] != -1)
        return dp[n];

    vector<int> v;
   
    for (int i = 1; i <= k; i++)
    {
        v.pb(abs(arr[n]-arr[n-i])+mincost(arr, n-i,k));
    }
    return dp[n] = *min_element(v.begin(),v.end());
}

signed main()
{
    FIO;
    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        memset(dp, -1, sizeof(dp));
        int n,k;
        cin >> n>>k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << mincost(arr, n - 1,k);
    }
    return 0;
}