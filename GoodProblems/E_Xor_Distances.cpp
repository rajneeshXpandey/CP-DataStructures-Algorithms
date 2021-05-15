#include <bits/stdc++.h>
using namespace std;

//    cout << fixed << setprecision(10);
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define int long long
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define setbits(x) __builtin_popcountll(x)
#define zerbefone(x) __builtin_ctzll(x)
#define pqmx priority_queue<int>                            // maxheap
#define pqmn priority_queue<int, vector<int>, greater<int>> //minheap
#define mod 1000000007
#define inf 100000000000000000 //1e17
#define Pi acos(-1.0)
#define precise(x, y) fixed << setprecision(y) << x
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main()
{
    int N;
    cin >> N;
    vector<vector<ll>> edge(N), weight(N);
    for (int i = 1; i < N; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        edge[--u].push_back(--v);
        edge[v].push_back(u);
        weight[u].push_back(w);
        weight[v].push_back(w);
    }
    vector<ll> dist(N, -1);
    std::queue<int> que;
    que.push(0);
    dist[0] = 0;
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (int i = 0; i < edge[now].size(); i++)
        {
            int next = edge[now][i];
            ll sum = dist[now] ^ weight[now][i];
            if (dist[next] == -1)
            {
                dist[next] = sum;
                que.push(next);
            }
        }
    }
     ll ans = 0;
     //amazing way to calculate sum ..etc in O(n*60)
    for (int i = 0; i < 60; i++)
    {
        vector<int> cnt(2);
        for (int j = 0; j < N; j++)
            cnt[dist[j] >> i & 1]++;
        ans += (1ll << i) % mod * cnt[0] % mod * cnt[1];
        ans %= mod;
    }
    cout << ans<< endl;
}

