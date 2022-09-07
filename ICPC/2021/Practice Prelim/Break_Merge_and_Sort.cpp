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
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, i, j, x, y, cost = 0;
        cin >> n;
        vector<ll> k(n);
        multiset<ll> ms;
        // vector<vector<ll>> vv(n);
        for (i = 0; i < n; i++)
        {
            // 1 2 5 | 4 | 3 7 8
            ll last = 0;
            cin >> k[i];
            cin >> x;
            vi parts;
            for (j = 1; j < k[i]; j++)
            {
                cin >> y;
                if (y < x)
                {
                    // break
                    ms.insert(j - last);
                    parts.pb(j - last);
                    last = j;
                }
                x = y;
            }
            parts.pb(k[i] - last);
            ms.insert(k[i] - last);

            cost += accumulate(all(parts), 0);
            cost -= *max_element(all(parts));
            // 1, 1, 1 -> 1, 2 -> 3
            // cost = 2 + 2 + 3
        }

        // [ 2, 1, 4, 2, 3]

        while (ms.size() > 1)
        {
            x = *ms.begin();
            ms.erase(ms.begin());
            y = *ms.begin();
            ms.erase(ms.begin());

            cost += (x + y);
            ms.insert(x + y);
        }
        cout << cost << "\n";
    }
}