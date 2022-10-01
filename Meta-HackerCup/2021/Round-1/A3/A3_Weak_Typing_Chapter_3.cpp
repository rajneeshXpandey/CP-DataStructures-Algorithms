// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define per(i, a, b) for (int i = (a)-1; i >= (b); i--)
#define forn(i, n) rep(i, 0, n)
#define rof(i, n) per(i, n, 0)
#define forone(i, n) for (int i = 1; i <= (n); ++i)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define ff first
#define ss second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define int long long
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define removeDuplicate(x) \
    sort(all(x));          \
    x.erase(unique(all(x)), x.end())       //remove Duplicate
#define setbits(x) __builtin_popcountll(x) // count set bits in binary rep
#define zerbefone(x) __builtin_ctzll(x)
#define pqb priority_queue<int>                               // maxheap
#define pqs priority_queue<int, vector<int>, greater<int>>    // minheap
#define piipqs priority_queue<pii, vector<pii>, greater<pii>> // minheap for pair<int,int>
#define piipqb priority_queue<pii>                            // maxheap for pair<int,int>
#define mod 1000000007                                        //1e9+7
#define mod1 998244353
#define inf 2000000000000000000 //2e18
#define PI 3.141592653589793238
#define mem0(a) memset(a, 0, sizeof(a))
#define mem1(a) memset(a, -1, sizeof(a))
#define meminf(a) memset(a, 0x7f, sizeof(a))
#define precise(x, y) fixed << setprecision(y) << x
#define FastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
// #define oset  tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 rng(61378913);
/* usage - just do rng() */

//assign and update min and max values.
template <typename T, typename T1>
T amax(T &a, T1 b)
{
    if (b > a)
        a = b;
    return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b)
{
    if (b < a)
        a = b;
    return a;
}

// *********************** Code Begins ************************ //

int add(int a, int b)
{
    return (a + b);
}
int sub(int a, int b)
{
    return ((a + b) % mod + mod) % mod;
}
int mul(int a, int b)
{
    return (a * b) % mod;
}
vector<vector<int>> mult(vector<vector<int>> a, vector<vector<int>> b)
{
    vector<vector<int>> c (a.size(),vector<int>(b[0].size()));
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b[0].size(); j++)
        {
            for (int k = 0; k < a[0].size(); k++)
            {
                c[i][j] = (c[i][j]+(a[i][k]*b[k][j])) % mod;
            }
        }
    }
    return c;
}


void solve()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    /*
Notes: All of the transitions after reading a letter in ch2 are strar combinations of the following 6 values:
 -total
 -perStep
 -os
 -Fs
 -xs
 -1 (the constant)
 
We can write each of these three transitions as a 6x6 matrix, and then apply this matrix to move to the next step.
Then, to efficiently handle the "double" operation, we can store a prefix product of all matricies we have
yet processed, effectively squaring our current total.

Details on what exactly the transitions are are described in the code.
 */

                              //total, perStep, os, Fs, xs, 1
    vector<vector<int>> state = {{0}, {0}, {0}, {0}, {0}, {1}};

    vector<vector<int>> prefixTransition(6, vector<int>(6, 0));

    for (int i=0; i<6; i++) prefixTransition[i][i]=1;

    for (char c : str)
    {
        vector<vector<int>> t;
        if (c == 'F')
            t = {
                {1, 1, 0, 0, 0, 0}, //newTotal = total + perStep
                {0, 1, 0, 0, 0, 0}, //newPerStep = perStep
                {0, 0, 1, 0, 0, 0}, //newOs = os
                {0, 0, 0, 1, 0, 1}, //newFs = Fs + 1
                {0, 0, 0, 0, 1, 0}, //newXs = xs
                {0, 0, 0, 0, 0, 1}, //new1 = 1
            };
        else if (c == 'O')
            t = {
                {1, 1, 0, 0, 1, 0}, //newTotal = total + perStep + xs
                {0, 1, 0, 0, 1, 0}, //newPerStep = perStep + xs
                {0, 0, 1, 1, 1, 1}, //newOs = 1 + xs + Fs + os
                {0, 0, 0, 0, 0, 0}, //newFs = 0
                {0, 0, 0, 0, 0, 0}, //newXs = 0
                {0, 0, 0, 0, 0, 1}, //new1 = 1
            };
        else if (c == 'X')
            t = {
                {1, 1, 1, 0, 0, 0}, //newTotal = total + perStep + xs
                {0, 1, 1, 0, 0, 0}, //newPerStep = perStep + os
                {0, 0, 0, 0, 0, 0}, //newOs = 0
                {0, 0, 0, 0, 0, 0}, //newFs = 0
                {0, 0, 1, 1, 1, 1}, //newXs = 1 + xs + Fs + os
                {0, 0, 0, 0, 0, 1}, //new1 = 1
            };
        else if (c == '.')
            t = prefixTransition;
        
        prefixTransition = mult(t, prefixTransition);
	}
    int finalTotal=mult(prefixTransition, state)[0][0];

    cout << finalTotal<<endl;
}

signed main()
{
    FastIO;

    freopen("weak_typing_chapter_3_input.txt", "r", stdin);
    freopen("A3_op.txt", "w", stdout);

    int tt = 1;
    cin >> tt;
    for (int i = 1; i <= tt; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
}