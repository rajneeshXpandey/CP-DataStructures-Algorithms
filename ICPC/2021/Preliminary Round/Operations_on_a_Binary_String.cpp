/**
 *    author:  priyanshudangi
 *    created: 04.09.2022 14:43:24
 **/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007

#define endl '\n'
#define in(x, n)                \
    for (int e = 0; e < n; e++) \
    {                           \
        ll y;                   \
        cin >> y;               \
        x.pb(y);                \
    }
#define print(x)           \
    for (auto it : x)      \
        cout << it << ' '; \
    cout << endl;

#define vi vector<ll>
#define vvi vector<vi>
#define ii pair<ll, ll>
#define vii vector<ii>
#define pb push_back
#define F first
#define S second

void solve(ll testcase)
{
    int n, x;
    cin >> n >> x;
    string str;
    cin >> str;

    vector<int> vect;

    int count = 0;
    int ans = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '0')
        {
            count++;
        }
        else
        {
            ans++;
            vect.push_back(count);
            count = 0;
        }
    }

    if (count)
    {
        vect.push_back(count);
    }

    sort(vect.begin(), vect.end());

    for (int i = vect.size() - 1; i >= 0; i--)
    {
        int deduct = 2 * vect[i] + 1;
        if (deduct <= x)
        {
            ans += vect[i];
            x -= deduct;
        }
        else
        {
            int p = (x - 1) / 2;
            if (p <= 0)
            {
                continue;
            }
            ans += p;
            x -= (p * 2 + 1);
        }
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll testcase;
    cin >> testcase;
    ll t = 1;
    while (testcase--)
    {
        solve(t);
        t++;
    }

    // solve(0);

    return 0;
}