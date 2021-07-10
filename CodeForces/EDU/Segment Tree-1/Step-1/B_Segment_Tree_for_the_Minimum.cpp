#include <bits/stdc++.h>
using namespace std;

#define int long long

int st[400001];

void buildST(int s, int e, int idx, int arr[])
{
    if (s == e)
    {
        st[idx] = arr[s];
        return;
    }
    int mid = (s + e) / 2;
    buildST(s, mid, 2 * idx + 1, arr);
    buildST(mid + 1, e, 2 * idx + 2, arr);

    st[idx] = min(st[2 * idx + 1],st[2 * idx + 2]);
}

int minRangeQuery(int L, int R, int s, int e, int idx)
{
    //complete overlap
    if (L <= s and R >= e)
        return st[idx];
    //no overlap
    else if (L > e or R < s)
        return 1e17;
    //partial overlap
    int mid = (s + e) / 2;
    int left = minRangeQuery(L, R, s, mid, 2 * idx + 1);
    int right = minRangeQuery(L, R, mid + 1, e, 2 * idx + 2);
    return min(left,right);
}

void updateQuery(int i, int val, int s, int e, int idx, int arr[])
{
    if (s == e)
    { // check if needed for the updation in arr also
        arr[i] = val;
        st[idx] = val;
        return;
    }

    int mid = (s + e) / 2;
    if (i <= mid)
        updateQuery(i, val, s, mid, 2 * idx + 1, arr);
    else if (i > mid)
        updateQuery(i, val, mid + 1, e, 2 * idx + 2, arr);

    st[idx] = min(st[2 * idx + 1], st[2 * idx + 2]);
}

signed main()
{
    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        int n, m;
        cin >> n >> m;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        buildST(0, n - 1, 0, arr);
        // for(int i=0;i<4*n;i++)
        //   cout<<st[i]<<" ";
        //   cout<<endl;
        for (int i = 0; i < m; i++)
        {
            int q;
            cin >> q;
            if (q == 1)
            {
                int idx, v;
                cin >> idx >> v;
                updateQuery(idx, v, 0, n - 1, 0, arr);
            }
            else if (q == 2)
            {
                int l, r;
                cin >> l >> r;
                int min = minRangeQuery(l, r - 1, 0, n - 1, 0);
                cout << min << endl;
            }
        }
    }
    return 0;
}