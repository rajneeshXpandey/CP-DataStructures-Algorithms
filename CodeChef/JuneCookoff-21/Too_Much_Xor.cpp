#include "bits/stdc++.h"
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define forn(i, n) rep(i, 0, (n))
#define rof(i, n) per(i, (n)-1, 0)
#define dbg(x) cout << #x << "=" << x << endl
#define dbg2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define dbg3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define ff first
#define ss second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define int    long long
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define setbits(x) __builtin_popcountll(x)
#define zerbefone(x) __builtin_ctzll(x)
#define pqb priority_queue<int>                               // maxheap
#define pqs priority_queue<int, vector<int>, greater<int>>    // minheap
#define piipqs priority_queue<pii, vector<pii>, greater<pii>> // minheap for pair<int,int>
#define piipqb priority_queue<pii>                            // maxheap for pair<int,int>
#define mod 1000000007
#define mod2 998244353
#define inf 2000000000000000000 //2e18
#define memt(a) memset(a, true, sizeof(a))
#define memf(a) memset(a, false, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define mem1(a) memset(a, -1, sizeof(a))
#define meminf(a) memset(a, 0x7f, sizeof(a))
#define precise(x, y) fixed << setprecision(y) << x
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << -1 << endl
// #define oset            tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> // set
// #define osetpii         tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update> //like multiset
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 rng(61378913);
/* usage - just do rng() */

// ****************************************** Code Begins ****************************************** //

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    bool flag = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i])
            flag = 0;
    }
    if (n == 1)
        cout << 0 << endl;
    else if (flag) // all 0
        cout << -1 << endl;
    else if (n == 2)
    {
        if (v[0] == v[1])
            cout << -1 << endl;
        else
            cout << 0 << endl;
    }
    else if (n == 3)
    {
        if (v[0] == v[2])
        {
            if (v[1] == v[0])
            {
                cout << 1 << endl;
                cout << "1 3 2\n";
            }
            else
                cout << 0 << endl;
        }
        else
        {
            if (!v[1])
            {
                if (v[0])
                    cout << "1\n1 2 3\n";
                else
                    cout << "1\n3 2 1\n";
            }
            else
                cout << -1 << endl;
        }
    }
    else // n>=4
    {
        vector<tuple<int, int, int>> ans;
        if (v[0])
        {
            ans.push_back({1, 3, 2});
            ans.push_back({1, 2, 4});
            ans.push_back({3, 4, 2});
            for (int i = 3; i <= n; i += 2)
                ans.push_back({1, 2, i});
            for (int i = 4; i <= n; i += 2)
                ans.push_back({1, 3, i});
        }
        else
        {
            int idx = 0;
            while (!v[idx])
                idx++;
            if (idx % 2)
            {
                for (int i = 1; i < n; i += 2)
                    if (i != idx)
                        ans.push_back({1, idx + 1, i + 1});
                for (int i = 2; i < n; i += 2)
                    ans.push_back({2, 4, i + 1});
            }
            else
            {
                for (int i = 1; i < n; i += 2)
                    ans.push_back({1, idx + 1, i + 1});
                for (int i = 2; i < n; i += 2)
                    ans.push_back({2, 4, i + 1});
            }
        }
        assert(ans.size() <= 3 * n);
        cout << ans.size() << endl;
        for (auto &[a, b, c] : ans)
            cout << a << " " << b << " " << c << endl;
    }
}

signed main()
{
    FIO;
    int tt = 1;
    cin >> tt;
    for (int i = 1; i <= tt; i++)
        solve();
}