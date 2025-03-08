#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <bitset>
#include <numeric>
#include <climits>
using namespace std;

#define loop(i, a, b) for (int i = a; i <= b; i++)
#define rloop(i, a, b) for (int i = a; i >= b; i--)
#define forn(i, n) loop(i, 0, n - 1)
#define tuplei tuple<int, int, int>;

// assign and update min and max values.
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

#define FastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

// Debugging
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define deb4(x, y, z, zz) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << "," << #zz << "=" << zz << endl
template <typename T>
inline void printDS(T dataStructure)
{
    for (auto val : dataStructure)
        cout << val << ' ';
    cout << endl;
}
template <typename T>
inline void print(T anything) { cout << anything << "\n"; }

// Data structures
#define max_heap priority_queue<int>                            // maxpq
#define min_heap priority_queue<int, vector<int>, greater<int>> // minpq

// numeric values
// #define mod 1000000007   //1e9+7
// #define mod 998244353
#define inf 2000000000000000000 // 2e18
#define pi 3.141592653589793238
double eps = 1e-12;

// ********************************* start ********************************** //

void solve()
{
    long long b, w;
    cin>>b>>w;
    vector<long long> black(b), white(w);
    forn(i,b) cin>>black[i];
    forn(i,w) cin>>white[i];
    sort(black.begin(), black.end());
    sort(white.begin(), white.end());
    long long maxSum = 0, count = 0;
    long long bpointer = -10ll, wpointer = -10ll;
    rloop(i, b-1, 0){
        if(black[i] > 0){
            maxSum += black[i];
            count++;
        }
        else{
            bpointer = i;
            break;
        }
    }
    rloop(i, w-1, max(0ll, w-count)){
        if(white[i] > 0){
            maxSum += white[i];
        }
        else{
            wpointer = i;
            break;
        }
    }
    if (bpointer == -10ll)
    {
        cout << maxSum << endl;
        return;
    }
    if(wpointer == -10ll){
        wpointer = max(-1ll,w-count-1);
    }
    if (bpointer >= 0 && wpointer >= 0){
        int got = black[bpointer] + white[wpointer];
        while ((bpointer >= 0 && wpointer >= 0) && ((maxSum + got) >= maxSum)){
            maxSum += got;
            bpointer--;
            wpointer--;
            got = black[bpointer] + white[wpointer];
        }
    }
    cout << maxSum << endl;
}

signed main()
{
    FastIO;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int total_testcases = 1;
    // cin >> total_testcases;
    for (int test_case = 1; test_case <= total_testcases; test_case++)
    {
        // cout<<"Case #"<< test_case <<": ";
        solve();
    }
}