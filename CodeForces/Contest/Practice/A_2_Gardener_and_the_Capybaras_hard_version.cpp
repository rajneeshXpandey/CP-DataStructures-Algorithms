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
inline ll power(ll a, ll n){a %= mod; int res = 1; while(n){if (n & 1) res = (res * a) % mod; a = (a * a) % mod;n >>= 1;} return res;}
inline void binary(ll n) { std::string binaryMask = std::bitset<64>(n).to_string(); cout<<binaryMask<<endl;}
inline void assign1ton(vector<int> &v) { iota(v.begin(), v.end(), 1); }
template<typename T> inline void printDS(T ds){for(auto val : ds) cout<<val<<' '; cout<<endl;}

// ********************************* Here we go!! ********************************** //

void solve(){
    string s;
    cin >> s;
    int n=sz(s);
    int a=0,b=0;
    forn(i,n){
        if(s[i]=='a')
            a++;
        else
            b++;
    }
        
    if(s[0]!=s[n-1]){
        if (s[0] == 'a')
        {
            int i = 0;
            int cnt = 0;
            while (i < n)
            {
                if (cnt > 0)
                    break;
                while (i < n && s[i] != 'b')
                    i++;
                if (i == n)
                    break;
                while (i < n && s[i] != 'a')
                    i++;
                if (i == n)
                    break;
                cnt++;
            }
            if (!cnt)
            {
                if (a == 1)
                {
                    cout<< s[0] << ' ';
                    loop(j,1,n-2) cout<< s[j];
                    cout<< " ";
                    cout<< s[n - 1] << ' ';
                    cout<<endl;
                    return;
                }
                else
                {
                    int j = 0;
                    while (s[j + 1] == 'a')
                        cout<< s[j++];
                    cout<< ' ' << s[j++] << ' ';
                    while (j < n)
                        cout<< s[j++];
                    cout<<endl;
                    return;
                }
            }
            else
            {
                int j = 0;
                while (s[j] != 'b')
                    cout<< s[j++];
                cout<< " ";
                while (j < n - 1)
                    cout<< s[j++];
                cout<< " ";
                cout<< s[n - 1] << '\n';
                return;
            }
        }
        else
        {
            int i = 0;
            int cnt = 0;
            while (i < n)
            {
                if (cnt > 0)
                    break;
                while (i < n && s[i] != 'a')
                    i++;
                if (i == n)
                    break;
                while (i < n && s[i] != 'b')
                    i++;
                if (i == n)
                    break;
                cnt++;
            }
            if (cnt == 0)
            {
                if (b == 1)
                {
                    cout<< s[0] << ' ' << s[1] << ' ';
                    loop(j, 2, n-1) cout<< s[j];
                    cout<<endl;
                    return;
                }
                else
                {

                    cout<< s[0] << ' ';
                    int j = 1;
                    while (s[j] != 'a')
                        cout<< s[j++];
                    cout<< ' ';
                    while (j < n)
                        cout<< s[j++];
                    cout<<endl;
                    return;
                }
            }
            else
            {
                int j = 0;
                while (s[j] != 'a')
                    cout<< s[j++];
                cout<< ' ' << s[j++] << ' ';
                while (j < n)
                    cout<< s[j++];
                cout<< '\n';
            }
        }
    }
    else{
        cout << s[0] << " " << s.substr(1, n - 2) << ' ' << s[n - 1] << endl;
    }
}

signed main(){
    FastIO;
    //freopen("s.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int total_testcases = 1;
    cin >> total_testcases;
    for (int test_case = 1; test_case <= total_testcases; test_case++){
        //cout<<"Case #"<< test_case <<": ";
        solve();
    }        
}