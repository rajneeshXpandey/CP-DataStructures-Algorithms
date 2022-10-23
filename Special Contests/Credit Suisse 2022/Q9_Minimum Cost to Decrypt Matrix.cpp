#pragma GCC optimize("unroll-loops,O3,Ofast")

#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b)  for(int i = a; i <= b; i++)
#define rloop(i, a, b) for(int i = a; i >= b; i--)
#define forn(i, n) loop(i, 0, n-1)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define deb4(x, y, z, zz) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << "," << #zz << "=" << zz << endl
#define ff first
#define ss second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define int long long
#define ll long long
#define sz(v) (ll)(v.size())
#define pb push_back
#define pii pair<int, int>
#define make_unique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin()); //remove Duplicate
#define generate_random(vec) generate(all(vec), rand); // fill vec with ramdom nums
#define rotate_by_k(vec,k) rotate(vec.begin(), vec.begin() + k, vec.end()); // cyclically shift a vector by k.
#define vector_to_set(a) set<int> S(all(a)); // Create a set from a vector
#define binary_rep(n) bitset<32> (n); // binary representation of a number
#define setbits(x) __builtin_popcountll(x)      // count set bits in binary rep
#define zerobefone(x) __builtin_ctzll(x) // zeros before first setbit
#define mod 1000000007   //1e9+7
#define mod1 998244353
#define inf 2000000000000000000 //2e18
#define pi  3.141592653589793238
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define neg cout << "-1" << endl
#define precise(x, y) fixed << setprecision(y) << x // cout<<precise(value,uptodecimalpt)<<endl;

typedef tuple<int, int, int> tuplei;

//assign and update min and max values.
template<typename T, typename T1> T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b) {if (b < a)a = b; return a;}

#define FastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

// mt19937_64 rng(61378913);
/* usage - generate random numbers, just do rng() */
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

inline ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
inline ll power(ll a, ll n){ ll res = 1; while (n > 0){ if (n % 2) res *= a; a *= a,n /= 2;} return res;}
inline void binary(ll n) { std::string binaryMask = std::bitset<64>(n).to_string(); cout<<binaryMask<<endl;}
inline void printArr(vector<int> v){for(auto val : v) cout<<val<<' '; cout<<endl;}

// ********************************* Code Begins ********************************** //

pii maximalSq(vector<vector<char>>& matrix){
    int l = matrix.size();
    vector<vector<int>> dp(l, vector<int>(l, 0));
    int ans = 0;
    for (int i = l - 1; i >= 0; i--)
    {
        for (int j = l - 1; j >= 0; j--)
        {
            if ((i == l - 1 or j == l - 1) and matrix[i][j] == '$')
                dp[i][j] = 1;
            else if (matrix[i][j] == '$')
            {
                dp[i][j] = 1 + min({dp[i + 1][j], dp[i][j + 1], dp[i + 1][j + 1]});
            }
            ans = max(ans, dp[i][j]);
        }
    }
    int cnt=0;
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < l; j++)
        {
            cout << dp[i][j] << ' ';
            
            if(dp[i][j]==ans){
                cnt++;
                for (int p = i; p <= i+ans; p++)
                {
                    for (int q = j; q <= j+ans; q++)
                    {
                        matrix[p][q] == '-';
                    }
                }
            }
        }
        cout << endl;
    }
    return {cnt,ans};
}
void solve(){
    int n;
    cin >> n;
    vector<vector<char>> matrix(n,vector<char>(n));
    forn(i, n){
        forn(j,n)
            cin >> matrix[i][j];
    }
    vector<int> xProjection(n, 0), yProjection(n, 0);
    forn(i, n){
        forn(j,n)
            if(matrix[i][j]=='$')
                xProjection[i]=1,yProjection[j]=1;
    }
    //printArr(xProjection);
    //printArr(yProjection);
    int ans=0;
    forn(i,n){
        if (xProjection[i] == 1 and  yProjection[i]==1){
            int len=0;
            while(i<n and xProjection[i] == 1 and yProjection[i] == 1)
            {
                len++;
                i++;
            }
            i--;
            ans+=len;
            //deb(len);
        }
        else if (xProjection[i] == 1)
        {
            ans++;
        }
        else if (yProjection[i] == 1){
            ans++;
        }
    }
    //pii maxSq = maximalSq(matrix);
    //int ans=0;
    //while (maxSq.ss){
    //    maxSq = maximalSq(matrix);
    //    ans += maxSq.ff;
    //    maxSq.ss=0;
    //}
    ////cout<<maxSq.ss<<endl;
    cout<<ans<<endl;
}

signed main(){
    FastIO;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int total_testcases = 1;
    //cin >> total_testcases;
    for (int test_case = 1; test_case <= total_testcases; test_case++){
        //cout<<"Case #"<< test_case <<": ";
        solve();
    }        
}