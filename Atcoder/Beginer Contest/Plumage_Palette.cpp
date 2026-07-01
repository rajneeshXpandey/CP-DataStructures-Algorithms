#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i <= b; i++)
#define rloop(i, a, b) for (int i = a; i >= b; i--)
#define forn(i, n) loop(i, 0, n - 1)
#define ff first
#define ss second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define int long long
#define ll long long
#define ld long double
#define pb push_back
#define generate_random(vect) generate(all(vect), rand); // fill vect with ramdom nums
#define binary_rep(n) bitset<32>(n);                     // binary representation of a number
#define setbits(x) __builtin_popcountll(x)               // count set bits in binary rep
#define zerobefone(x) __builtin_ctzll(x)                 // zeros before first setbit
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define neg cout << "-1" << endl
#define precise(x, y) fixed << setprecision(y) << x // cout<<precise(value,uptodecimalpt)<<endl;

#define FastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

// useful functions
inline ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); } // gcd
// power in mod
inline ll power(ll a, ll n, ll mod)
{
    a %= mod;
    int res = 1;
    while (n)
    {
        if (n & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return res;
}
inline ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
inline ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); } // divide a by b rounded down

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

// numeric values
// #define mod 1000000007   //1e9+7
// #define mod 998244353
#define inf 2000000000000000000 // 2e18
#define pi 3.141592653589793238
double eps = 1e-12;

// ********************************* start ********************************** //

void solve()
{
    int n,m,a,d,b;
    cin >> n >> m;
    unordered_map<int,set<pair<int,int>>> birds;
    set<array<int,3>> arr;
    forn(i, n){
        cin>>a>>d>>b;
        if(d==1 || a==b){
            birds[b].insert({1,m});
        }else{
            birds[a].insert({1,d-1});
            birds[b].insert({d,m});
        }
    }
    vector<int> days(m+2,0);
    for(auto& bird: birds){
        int e = -1;
        for(auto& b: bird.second){
            if(e==-1){
                days[b.first]++;
            }
            else if(e<b.first){
                days[e+1]--;
                days[b.first]++;
            }
            e = max(e,b.second);
        }
        days[e+1]--;
    }
    for(int i=1;i<=m;i++){
        days[i] += days[i-1]; 
        cout<<days[i]<<'\n';
    }
}

signed main()
{
    FastIO;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int total_testcases = 1;
    for (int test_case = 1; test_case <= total_testcases; test_case++)
    {
        // cout<<"Case #"<< test_case <<": ";
        solve();
    }
}