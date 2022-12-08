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
//#define int long long
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

// ********************************* Code Begins ********************************** //

void solve(){
    int A,B,C;
    cin >> A >> B >> C;
    //loop(x,0,100){
    //    if((A^x)+(B^x)==(C^x)){
    //        cout<<x<<endl;
    //        return;
    //    }
    //}
    /*
       A^x + B^x = C^x
        2   , 3 ,   13
       0010  0011   1101

    * just perform bitwise opreration on each bit and check if it is possible or not.
    start performing bitwise xor on the eq
       1: 0^x + 1^x = 1^x -> for x=0
       2: 1^x + 1^x = 0^x -> for x=1 ....if (no x can equate this 1) return NO
    also take care of carry

    for 2,5,7 -> 0
        2,3,13 -> NO
        7,0,7  -> 0
        2, 7, 6 -> 3
        1,6,6 -> 1
    */
    int bita[28],bitb[28],bitc[28],bitx[29];
    memset(bita,0,sizeof(bita));
    memset(bitb,0,sizeof(bitb));
    memset(bitc,0,sizeof(bitc));
    memset(bitx,0,sizeof(bitx));
    forn(i,28){
        bita[i] = ((A>>i)&1);
        bitb[i] = ((B>>i)&1);
        bitc[i] = ((C>>i)&1);
    }
    int carry=0;
    int prevcarry=0;
    auto check = [&](int x,int i){
        prevcarry = carry;
        int val = (carry + (bita[i]^x) + (bitb[i]^x));
        //deb4(i,x,val,carry);
        if(val>=2)
            carry=1;
        else carry = 0;
        val=(val%2);
        if(val == (bitc[i]^x))
            return true;
        return false;
    };
    forn(i,28){
        // eq => bita[i]^x + bitb[i]^x = bitc[i]^x
        int x=0;
        if(check(x,i)){
            bitx[i] = x;
        }
        else{
            x=1;
            carry = prevcarry;
            if(check(x,i)){
                bitx[i] = x;
            }
            else{
                no;
                return;
            }
        }
    }
    int X=0;
    for(int i=27;i>=0;i--){
        //cout<<bitx[i];
        X = X + (bitx[i] * (1<<i));
    }
    //cout<<endl;
    //deb(X);
    if((A^X)+(B^X)==(C^X)){
        yes;
        return;
    }
    no;
}

signed main(){
    FastIO;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int total_testcases = 1;
    cin >> total_testcases;
    for (int test_case = 1; test_case <= total_testcases; test_case++){
        //cout<<"Case #"<< test_case <<": ";
        solve();
    }        
}