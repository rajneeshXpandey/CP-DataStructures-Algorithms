#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef unordered_map<int, int> umii;
typedef unordered_map<ll, ll> umll;

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define F first
#define S second
#define f(i, n) for (int i = 0; i < n; i++)
#define fr(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define fo(i, a, n) for (ll i = (ll)a; i < (ll)n; i++)
#define pb push_back
#define mp make_pair
#define pri_que_down priority_queue<ll>
#define pri_que_up priority_queue<ll, vector<ll>, greater<ll>>
#define fix(x) fixed << setprecision(x)
#define mod 1e9 + 7;

#define display(v)                          \
    for (int i = 0; i < (int)v.size(); ++i) \
    cout << v[i] << " "
#define all(v) v.begin(), v.end()
#define read(a)                             \
    for (int i = 0; i < (int)a.size(); ++i) \
    cin >> a[i]
// ---------------------------------------*******************--------------------------------------//

ll power(ll x, ll y)
{
    ll p = 1e9 + 7;
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
ll fact(ll n)
{
    if (n <= 1)
        return 1;
    else
        return n * fact(n - 1);
}

ll nCr(ll n, ll r)
{
    if (r == 0 || r == n)
        return 1;
    if (r == 1)
        return n;
    if ((n - r) > r)
        r = n - r;
    ll C[r + 1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    int i;
    fo(i, 1, n + 1)
    {
        for (int j = min(i, r); j > 0; j--)
            C[j] = C[j] + C[j - 1];
    }
    return C[r];
}

ll HCF_of_two_num(ll a, ll b)
{
    ll c = __gcd(a, b);
    return c;
}
ll LCM_of_two_num(ll a, ll b)
{
    ll c = __gcd(a, b);
    c = (a * b) / c;
    return c;
}

ll str_to_int(string s)
{
    stringstream geek(s);
    ll x = 0;
    geek >> x;
    return x;
}
string int_to_str(ll n)
{
    return to_string(n);
}

ll HCF_of_Array(ll A[], ll n)
{
    ll i, a;
    a = A[0];
    fo(i, 1, n)
        a = __gcd(a, A[i]);
    return a;
}
ll HCF_of_Vector(vector<ll> A)
{
    ll i, a, n = A.size();
    a = A[0];
    fo(i, 1, n)
        a = __gcd(a, A[i]);
    return a;
}
ll LCM_of_Array(ll A[], ll n)
{
    ll i, a, b;
    a = A[0];
    b = A[0];
    fo(i, 1, n)
    {
        b = __gcd(a, A[i]);
        a = (a * A[i]) / b;
    }
    return a;
}

ll LCM_of_Vector(vector<ll> A)
{
    ll i, a, b, n = A.size();
    a = A[0];
    b = A[0];
    fo(i, 1, n)
    {
        b = __gcd(a, A[i]);
        a = (a * A[i]) / b;
    }
    return a;
}

map<ll, ll> count_freq_arr(ll A[], ll n)
{
    map<ll, ll> result;
    ll i;
    f(i, n)
        result[A[i]]++;
    return result;
}

map<ll, ll> count_freq_vector(vector<ll> A)
{
    map<ll, ll> result;
    ll i, n = A.size();
    f(i, n)
        result[A[i]]++;
    return result;
}
bool element_present(vector<ll> A, ll a)
{
    ll i, n = A.size();
    set<ll> B;
    f(i, n)
        B.insert(A[i]);
    return B.find(a) != B.end();
}

vector<ll> change_Arr_to_Vector(ll A[], ll n)
{
    vector<ll> B;
    for (ll i = 0; i < n; i++)
        B.pb(A[i]);
    return B;
}

bool chk_prime(ll n)
{
    if (n < 2)
        return false;
    f(i, n)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void factorize(ll n)
{
    ll i, count = 0;
    while (!(n % 2))
    {
        n >>= 1;
        count++;
    }
    if (count)
        cout << "2 : " << count << "\n";
    for (i = 3; i <= sqrt(n); i += 2)
    {
        count = 0;
        while (n % i == 0)
        {
            count++;
            n = n / i;
        }
        if (count)
            cout << i << " : " << count << "\n";
    }
    if (n > 2)
        cout << n << " : 1"
             << "\n";
}
void SieveOfEratosthenes(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
        if (prime[p])
            cout << p << " ";
}
/* ---------------------------------------*******************--------------------------------------
                                ll power(ll a,ll b)ll fact(ll n)    
                                ll nCr(ll n,ll r)
                                ll HCF_of_two_num(ll a,ll b)
                                ll LCM_of_two_num(ll a,ll b)
                                ll str_to_int(string s)
                                string int_to_str(ll n)
                                ll HCF_of_Array(ll A[],ll n)
                                ll HCF_of_Vector(vector<ll>A)
                                ll LCM_of_Array(ll A[],ll n)
                                ll LCM_of_Vector(vector<ll>A)
                                map<ll,ll> count_freq_arr(ll A[],ll n)
                                map<ll,ll> count_freq_Vector(vector<ll>A)
                                bool element_present(vector<ll>A,ll a)
                                vector<ll> change_Arr_to_Vector(ll A[],ll n)
                                bool chk_prime(ll n)
                                void factorize(ll n)
                                void SieveOfEratosthenes(int n)
 *****----------------------------------*******************--------------------------------------*/

void solve()
{
  
}

// ---------------------------------------*******************--------------------------------------//

signed main()
{
    fast;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}