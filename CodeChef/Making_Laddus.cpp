#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repA(i, a, n) for (int i = a; i <= (n); ++i)
#define repD(i, a, n) for (int i = a; i >= (n); --i)

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, k, n;
        cin >> x >> y >> k >> n;
        vector<int> w(n);
        vector<int> c(n);

        rep(i, n) cin >> w[i] >> c[i];

        int need = x - y;
        int i;
        bool flag = false;
        for (i = 0; i < n; i++)
        {
            if (need <= w[i] and c[i] <= k)
            {
                flag = true;
                break;
            }
        }

        if (flag)
            cout << "LuckyChef" << '\n';
        else
            cout << "UnluckyChef" << '\n';
    }
    return 0;
}