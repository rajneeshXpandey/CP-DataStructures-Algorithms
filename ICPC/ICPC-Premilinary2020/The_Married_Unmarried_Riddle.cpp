/**
*    author:  priyanshudangi
*    created: 07.08.2021 18:17:42
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
    string str;
    cin >> str;
    int n = str.length();
    int idxm = -1, idxu = -1;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'M')
        {
            idxm = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (str[i] == 'U')
        {
            idxu = i;
            break;
        }
    }

    if (idxm == -1 || idxu == -1 || idxm > idxu)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
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