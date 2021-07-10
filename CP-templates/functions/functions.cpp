#include <bits/stdc++.h>
using namespace std;

#define int long long 
typedef pair<int, int> pii;
typedef pair<int, int> pint;
typedef vector<int> vi;
typedef vector<int> vl;
typedef vector<pii> vii;
typedef unordered_map<int, int> umii;
typedef unordered_map<int, int> umint;

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define F first
#define S second
#define f(i, n) for (int i = 0; i < n; i++)
#define fr(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define fo(i, a, n) for (int i = (int)a; i < (int)n; i++)
#define pb push_back
#define mp make_pair
#define pri_que_down priority_queue<int>
#define pri_que_up priority_queue<int, vector<int>, greater<int>>
#define fix(x) fixed << setprecision(x)
#define mod 1e9 + 7;

#define display(v)                          \
    for (int i = 0; i < (int)v.size(); ++i) \
    cout << v[i] << " "
#define aint(v) v.begin(), v.end()
#define read(a)                             \
    for (int i = 0; i < (int)a.size(); ++i) \
    cin >> a[i]
// ---------------------------------------*******************--------------------------------------//

int power(int x, int y)
{
    int p = 1e9 + 7;
    int res = 1;
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
int fact(int n)
{
    if (n <= 1)
        return 1;
    else
        return n * fact(n - 1);
}

int nCr(int n, int r)
{
    if (r == 0 || r == n)
        return 1;
    if (r == 1)
        return n;
    if ((n - r) > r)
        r = n - r;
    int C[r + 1];
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

int HCF_of_two_num(int a, int b)
{
    int c = __gcd(a, b);
    return c;
}
int LCM_of_two_num(int a, int b)
{
    int c = __gcd(a, b);
    c = (a * b) / c;
    return c;
}

int str_to_int(string s)
{
    stringstream geek(s);
    int x = 0;
    geek >> x;
    return x;
}
string int_to_str(int n)
{
    return to_string(n);
}

int HCF_of_Array(int A[], int n)
{
    int i, a;
    a = A[0];
    fo(i, 1, n)
        a = __gcd(a, A[i]);
    return a;
}
int HCF_of_Vector(vector<int> A)
{
    int i, a, n = A.size();
    a = A[0];
    fo(i, 1, n)
        a = __gcd(a, A[i]);
    return a;
}
int LCM_of_Array(int A[], int n)
{
    int i, a, b;
    a = A[0];
    b = A[0];
    fo(i, 1, n)
    {
        b = __gcd(a, A[i]);
        a = (a * A[i]) / b;
    }
    return a;
}

int LCM_of_Vector(vector<int> A)
{
    int i, a, b, n = A.size();
    a = A[0];
    b = A[0];
    fo(i, 1, n)
    {
        b = __gcd(a, A[i]);
        a = (a * A[i]) / b;
    }
    return a;
}

map<int, int> count_freq_arr(int A[], int n)
{
    map<int, int> result;
    int i;
    f(i, n)
        result[A[i]]++;
    return result;
}

map<int, int> count_freq_vector(vector<int> A)
{
    map<int, int> result;
    int i, n = A.size();
    f(i, n)
        result[A[i]]++;
    return result;
}
bool element_present(vector<int> A, int a)
{
    int i, n = A.size();
    set<int> B;
    f(i, n)
        B.insert(A[i]);
    return B.find(a) != B.end();
}

vector<int> change_Arr_to_Vector(int A[], int n)
{
    vector<int> B;
    for (int i = 0; i < n; i++)
        B.pb(A[i]);
    return B;
}

bool chk_prime(int n)
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

void factorize(int n)
{
    int i, count = 0;
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
                                int power(int a,int b)int fact(int n)    
                                int nCr(int n,int r)
                                int HCF_of_two_num(int a,int b)
                                int LCM_of_two_num(int a,int b)
                                int str_to_int(string s)
                                string int_to_str(int n)
                                int HCF_of_Array(int A[],int n)
                                int HCF_of_Vector(vector<int>A)
                                int LCM_of_Array(int A[],int n)
                                int LCM_of_Vector(vector<int>A)
                                map<int,int> count_freq_arr(int A[],int n)
                                map<int,int> count_freq_Vector(vector<int>A)
                                bool element_present(vector<int>A,int a)
                                vector<int> change_Arr_to_Vector(int A[],int n)
                                bool chk_prime(int n)
                                void factorize(int n)
                                void SieveOfEratosthenes(int n)
 *****----------------------------------*******************--------------------------------------*/

void solve()
{
  
}

// ---------------------------------------*******************--------------------------------------//

signed main()
{
    fast;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}