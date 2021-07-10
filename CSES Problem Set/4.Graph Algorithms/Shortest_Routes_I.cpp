#include <bits/stdc++.h>

using namespace std;

#define pii pair<ll, ll>
#define pip pair<ll, pii>
#define ll long long
#define mp make_pair

#define inf 10000000000000000

vector<ll> indeg;
vector<ll> flag;
vector<ll> dist;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, e;
    cin >> n >> e;
    vector<pii> adj[n + 1];
    indeg.resize(n + 1, 0);
    flag.resize(n + 1, 0);
    dist.resize(n + 1, inf);
    for (ll i = 0; i < e; i++)
    {
        ll u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back(mp(v, wt));
        indeg[v]++;
    }

    //  topSort(adj,n);
    dist[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q; // {dist,node}
    q.push(mp(0, 1));
    while (!q.empty())
    {
        auto curr = q.top();
        q.pop();
        flag[curr.second] = 1;
        if (curr.first > dist[curr.second])
            continue;
        for (auto nb : adj[curr.second])
        {
            if (!flag[nb.first] and dist[nb.first] > nb.second + curr.first)
            {
                dist[nb.first] = nb.second + curr.first;
                q.push({dist[nb.first], nb.first});
            }
        }
    }
    for (ll i = 1; i <= n; i++)
        cout << dist[i] << ' ';
    return 0;
}