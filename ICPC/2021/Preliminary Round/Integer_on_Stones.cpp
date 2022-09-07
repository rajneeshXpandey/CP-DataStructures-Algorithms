#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int, int>;
#define fi first
#define se second
#define mp make_pair

#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
long long binpow(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, n;
        cin >> a >> n;
        ll pow = n / 2;
        ll ans;
        if (a < 0)
            ans = 1;
        else if (a == 0)
            ans = 0;
        else
            ans = binpow(a, pow, MOD);
        cout << ans << "\n";
    }
}
/*
1 <= T <= 100000
-10^9 <= A <= 10^9
A != 0
2 <= N <= 10^9
N is always even
*/
