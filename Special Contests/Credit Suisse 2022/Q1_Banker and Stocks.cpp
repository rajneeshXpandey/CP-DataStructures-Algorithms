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
vector<int> prime, lpf;
void sieve(int n)
{
    prime.assign(1, 2);
    lpf.assign(n + 1, 2);

    for (int x = 3; x <= n; x += 2)
    {
        if (lpf[x] == 2)
            prime.push_back(lpf[x] = x);
        for (int i = 0; i < prime.size() && prime[i] <= lpf[x] && prime[i] * x <= n; ++i)
            lpf[prime[i] * x] = prime[i];
    }
}

ll addMOD(ll a, ll b, const ll MOD)
{
    return (a + b) % MOD;
}

ll mulMOD(ll a, ll b, const ll MOD)
{
    // if (double(a) * b <= 1e18) return (a * b) % MOD;

    ll res = 0;
    for (a %= MOD; b > 0; a <<= 1, b >>= 1)
    {
        if (a >= MOD)
            a -= MOD;
        if (b & 1)
        {
            res += a;
            if (res >= MOD)
                res -= MOD;
        }
    }

    return res;
}

ll powMOD(ll x, ll n, const ll MOD)
{
    ll res = 1;
    for (; n > 0; n >>= 1)
    {
        if (n & 1)
            res = mulMOD(res, x, MOD);
        x = mulMOD(x, x, MOD);
    }

    return res;
}

bool mr_test(ll n, int a, ll d, int s)
{
    ll x = powMOD(a, d, n);
    if (x == 1 || x == n - 1)
        return false;

    for (int r = 1; r < s; ++r)
    {
        x = mulMOD(x, x, n);
        if (x == n - 1)
            return false;
    }

    return true;
}

bool miller_rabin(ll n, int k = 5)
{
    if (n < 4)
        return n == 2 || n == 3;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    int s = __builtin_ctz(n - 1);
    ll d = (n - 1) >> s;
    for (int it = 1; it <= 5; ++it)
    {
        int a = 2 + rand() % (n - 3);
        if (mr_test(n, a, d, s))
            return false;
    }

    return true;
}

bool isPrime(ll n)
{
    if (n < 2)
        return false;
    if (n < lpf.size())
        return lpf[n] == n;
    return miller_rabin(n);
}

ll any_divisor_of(ll n)
{
    if (n <= 1)
        return 1;
    if (n < lpf.size())
        return lpf[n];
    if (isPrime(n))
        return n;

    ll d = n;
    for (ll c = 2; d == n; ++c)
    {
        ll x = 2, y = 2, i = 2, k = 2;
        while (true)
        {
            x = (mulMOD(x, x, n) + c);
            if (x >= n)
                x -= n;
            d = __gcd(abs(x - y), n);
            if (d > 1 && n % d == 0)
                break;
            if (i++ == k)
                y = x, k <<= 1;
        }
    }

    return d;
}

bool isSquarePrime(ll n)
{
    ll t = round(sqrt(n));
    return (t * t == n && isPrime(t));
}

bool isCubePrime(ll n)
{
    ll t = round(cbrt(n));
    return (t * t * t == n && isPrime(t));
}

bool isSemiPrime(ll n)
{
    ll d = any_divisor_of(n);
    return isPrime(d) && isPrime(n / d);
}

bool isSphenicPrime(ll n)
{
    ll p = any_divisor_of(n);
    n /= p;
    if (isPrime(n))
        swap(p, n);

    ll q = any_divisor_of(n);
    n /= q;
    return (p != q) && (q != n) && (n != p) && isPrime(p) && isPrime(q) && isPrime(n);
}

ll countFactor(ll n)
{
    int t = sqrt(sqrt(n)) + 1;
    sieve(t);

    ll res = 1;
    for (int p : prime)
    {
        if (1LL * p * p * p * p > n)
            break;
        if (n % p == 0)
        {
            int f = 0;
            do
                ++f;
            while ((n /= p) % p == 0);
            res *= (f + 1);
        }
    }

    if (n == 1)
        return res;
    if (isPrime(n))
        return res * 2;
    if (isSquarePrime(n))
        return res * 3;
    if (isSemiPrime(n))
        return res * 4;
    if (isCubePrime(n))
        return res * 4;
    if (isSphenicPrime(n))
        return res * 8;
    return res * 6;
}
pii numberofDivisors(int &n){
    int oddFactorCount = 0, evenFactorCount = 0;
    for (int i = 1; i*i<=n; i++)
    {
        if (n % i == 0)
        {
            // If divisors are equal, count only one
            if (n / i == i){
                (i&1)?(oddFactorCount++):(evenFactorCount++);
            }
            // Otherwise count both
            else{
                (i & 1) ? (oddFactorCount++) : (evenFactorCount++);
                ((n/i)&1) ? (oddFactorCount++) : (evenFactorCount++);
            } 
        }
    }
    deb2(oddFactorCount, evenFactorCount);
    return {oddFactorCount, evenFactorCount};
}
void solve(){
    int n;
    cin >> n;
    int oddFactorCount = 0, evenFactorCount = 0, expo2=0;
    if (n&1){
        cout<<"SELL"<<endl;
        return;
    }
    int fCount = countFactor(n);
    while(n%2==0){
        n/=2;
        expo2++;
    }
    oddFactorCount = fCount/(expo2+1);
    evenFactorCount = fCount - oddFactorCount;
    if(oddFactorCount==evenFactorCount){
        cout<<"PASS"<<endl;
    }
    else if (oddFactorCount > evenFactorCount){
        cout<<"SELL"<<endl;
    }
    else{
        cout<<"BUY"<<endl;
    }
}

signed main(){
    FastIO;
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int total_testcases = 1;
    //cin >> total_testcases;
    for (int test_case = 1; test_case <= total_testcases; test_case++){
        //cout<<"Case #"<< test_case <<": ";
        solve();
    }        
}