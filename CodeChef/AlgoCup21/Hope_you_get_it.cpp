// rajneesh_1708 : Rajneesh Pandey
#include <bits/stdc++.h>
using namespace std;

//    cout << fixed << setprecision(10);
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
#define pqmn priority_queue<int, vector<int>, greater<int>> //minheap
#define mod 1000000007
#define inf 100000000000000000 //1e17
#define Pi acos(-1.0)
#define precise(x, y) fixed << setprecision(y) << x
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int sum(int n)
{
    int s = 0, x = 0;
    if ((n % 2) != 0)
    {
        x = (n + 1) / 2;
        s = (n % mod * x % mod) % mod;
    }
    else
    {
        x = n / 2;
        s = (x % mod * (n + 1) % mod) % mod;
    }
    return s;
}

int sqsum(int n)
{
    int x = 0, s = 0;

    if (n * (n + 1) % 6 == 0)
    {
        x = (n * (n + 1)) / 6;
        s = (x % mod * (2*n+1) % mod) % mod;
    }
    else if (n * ((2 * n) + 1) % 6 == 0)
    {
        x = (n*(2*n+1)) / 6;
        s = (x % mod * (n + 1) % mod) % mod;
    }
    else
    {
        x = ((n+1)*(2*n+1))/6;
        s = (x % mod * n % mod) % mod;
    }

    return s;
}

signed main()
{
    FIO;
    int tt;
    cin >> tt;
    while (tt--)
    {
        int l, r;
        cin >> l >> r;
        int ans1 = (sum(r) - sum(l - 1) +mod) % mod;
        ans1 = (ans1 % mod * ans1 % mod) % mod;
        int ans2 = (sqsum(r) - sqsum(l - 1)+mod) % mod;
        //deb2(ans1,ans2);
        int ans = (ans1 - ans2 + mod) % mod;

      cout <<ans<< endl;
    }
    return 0;
}