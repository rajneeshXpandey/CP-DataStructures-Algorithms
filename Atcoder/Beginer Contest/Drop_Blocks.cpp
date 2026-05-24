#include <bits/stdc++.h>
using namespace std;

#define N (int)3e+5

int main(void)
{
    int a[N + 1] = {};
    int c[N + 1] = {};
    int n, q, t, x, mn = 0;

    cin >> n >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> t >> x;
        if (t == 1)
        {
            a[x]++;
            c[a[x]]++;
            if (c[a[x]] == n)
                mn = a[x];
        }
        if (t == 2)
        {
            if (x + mn > q)
                cout << 0 << endl;
            else
                cout << c[x + mn] << endl;
        }
    }

    return 0;
}
