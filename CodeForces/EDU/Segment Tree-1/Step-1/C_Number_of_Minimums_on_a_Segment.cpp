#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii  pair<int,int>

pii st[400001];

pii node_value(pii a,pii b)
{
    if(a.first > b.first) return b;
    if(a.first < b.first) return a;
    else
    {
         return {a.first, a.second+b.second};
    }
    
}

void buildST(int s, int e, int idx, int arr[])
{
    if (s == e)
    {
        st[idx] = {arr[s],1};
        return;
    }
    int mid = (s + e) / 2;
    buildST(s, mid, 2 * idx + 1, arr);
    buildST(mid + 1, e, 2 * idx + 2, arr);

    st[idx] = node_value(st[2 * idx + 1], st[2 * idx + 2]);
}

pii minRangeQuery(int L, int R, int s, int e, int idx)
{
    //complete overlap
    if (L <= s and R >= e)
    {
        return st[idx];
    }
        
    //no overlap
    else if (L > e or R < s)
        return {1e17,0};
    //partial overlap
    int mid = (s + e) / 2;
    pii left = minRangeQuery(L, R, s, mid, 2 * idx + 1);
    pii right = minRangeQuery(L, R, mid + 1, e, 2 * idx + 2);
    return node_value(left, right);
}

void updateQuery(int i, int val, int s, int e, int idx, int arr[])
{
    if (s == e)
    { 
        st[idx] = {val,1};
        return;
    }

    int mid = (s + e) / 2;
    if (i <= mid)
        updateQuery(i, val, s, mid, 2 * idx + 1, arr);
    else if (i > mid)
        updateQuery(i, val, mid + 1, e, 2 * idx + 2, arr);

    st[idx] = node_value(st[2 * idx + 1], st[2 * idx + 2]);
}
signed main()
{
    
        int n, m;
        cin >> n >> m;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        buildST(0, n - 1, 0, arr);

        for (int i = 0; i < m; i++)
        {
            int q;
            cin >> q;
            if (q == 1)
            {
                int idx, v;
                cin >> idx>>v;
                updateQuery(idx, v, 0, n - 1, 0, arr);
            }
            else if (q == 2)
            {
                int l, r;
                cin >> l >> r;
                pii min = minRangeQuery(l, r - 1, 0, n - 1, 0);
                cout << min.first << " " << min.second << endl;
            }
        }
    return 0;
}