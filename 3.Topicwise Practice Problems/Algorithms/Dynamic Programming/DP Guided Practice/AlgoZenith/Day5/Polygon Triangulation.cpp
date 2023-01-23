#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

int n;
vector<vector<ll>> dp;
vector<ll> a;
ll rec(int i, int j)
{
    if (abs(j - i) == 1)
        return 0;
    auto &ans = dp[i][j];
    if (ans != -1)
        return ans;
    ans = 1e18;
    for (int k = i + 1; k <= j - 1; k++)
        ans = min(ans, a[i] * a[k] * a[j] + rec(i, k) + rec(k, j));
    return ans;
}
ll minTriangulation(vector<ll> &v)
{
    n = v.size();
    a = v;
    dp.assign(n + 1, vector<ll>(n + 1, -1));
    return rec(0, n - 1);
}
void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    auto ans = minTriangulation(v);
    cout << ans << endl;
    assert(ans > 0);
}
/*
Description

You have a convex n-sided convex polygon where each vertex has an integer value vi
. You are given an integer array values where v[j] is the value of the ith
 vertex (i.e., clockwise order).

You will triangulate the convex polygon into n-2 triangles. 
For each triangle, the value of that triangle is the product of the values of its vertices, and the total score of the triangulation is the sum of these values over all
n−2 triangles in the triangulation.

Output the smallest possible total score that you can achieve with some triangulation of the polygon.


Input Format

First Line contains T - the number of test cases. 
The First Line of each test case contains n - the number of vertices of the convex polygon.
The second line of each test case contains n
 space-separated values v[i] of the vertices in clockwise order.


Output Format

For each test case, Output the smallest possible total score that you can achieve with some triangulation of the polygon.


Constraints

T => 1000
v[i] => 10000
n => 100 
*/
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // int i = 1;
    cin >> t;
    while (t--)
    {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}