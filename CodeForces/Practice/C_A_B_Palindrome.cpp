#include "bits/stdc++.h"
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

template <typename A, typename B>
string to_string(pair<A, B> p)
{
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <size_t N>
string to_string(bitset<N> v)
{
    string res = "";
    for (size_t i = 0; i < N; i++)
    {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}
template <typename A>
string to_string(A v)
{
    bool first = true;
    string res = "{";
    for (const auto &x : v)
    {
        if (!first)
        {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
//   cout << fixed << setprecision(10);
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define per(i, a, b) for (int i = (a)-1; i >= (b); i--)
#define forn(i, n) rep(i, 0, n)
#define rof(i, n) per(i, n, 0)
#define forone(i, n) for (int i = 1; i <= (n); ++i)
#define dbg(x) cout << #x << "=" << x << endl
#define dbg2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define dbg3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define ff first
#define ss second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define int long long
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
#define inf 100000000000000000 //1e17
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
// #define oset            tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 rng(61378913);
/* usage - just do rng() */

// *************************** Code Begins **************************** //

void solve()
{

    int a, b;
    cin >> a >> b;
    int z = a, o = b;
    string s;
    cin >> s;
    for (auto st : s)
    {
        if (st == '0')
            a--;
        if (st == '1')
            b--;
    }
    int i = 0, j = s.size() - 1;
    while (i < j)
    {
        if ((s[i] == '?' and s[j] != '?') or (s[i] != '?' and s[j] == '?'))
        {
            if (s[i] == '?')
            {
                s[i] = s[j];
                s[j] == '0' ? a-- : b--;
            }
            else if (s[j] == '?')
            {
                s[j] = s[i];
                s[i] == '0' ? a-- : b--;
            }
            else
            {
                cout << "-1" << endl;
                return;
            }
        }
        else if (s[i] != s[j] and s[j] != '?' and s[i] != '?')
        {
            cout << "-1" << endl;
            return;
        }
        i++;
        j--;
    }
    i = 0, j = s.size() - 1;
    while (i < j)
    {
        if (s[i] == '?' and s[j] == '?')
        {
            if (a >= 2)
            {
                s[i] = '0';
                s[j] = '0';
                a -= 2;
            }
            else if (b >= 2)
            {
                s[i] = '1';
                s[j] = '1';
                b -= 2;
            }
            else
            {
                cout << "-1" << endl;
                return;
            }
        }
        i++;
        j--;
    }
    if (s[s.size() / 2] == '?')
    {
        if (a > 0)
        {
            s[i] = '0';
            a--;
        }
        else if (b > 0)
        {
            s[i] = '1';
            b--;
        }
        else
        {
            cout << "-1" << endl;
            return;
        }
    }
    if (a == 0 and b == 0)
        cout << s << endl;
    else
        cout << "-1" << endl;
}

signed main()
{
    FIO;
    int tt = 1;
    cin >> tt;
    for (int i = 1; i <= tt; i++)
        solve();
}