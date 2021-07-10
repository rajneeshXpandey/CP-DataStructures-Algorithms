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

vector<int> *adj;

int *visited;

int *inTime;

int *outTime;

int timer = 1;

void dfs(int root)
{

    visited[root] = 1;
    inTime[root] = timer++;
    for (auto nb : adj[root])
    {
        if (!visited[nb])
            dfs(nb);
    }
    outTime[root] = timer++;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n; //number of nodes = n (1, 2 .....)
    // n-1 : number of edges
    adj  = new vector<int>[n + 1];
    visited = new int[n + 1];
    inTime = new int[n + 1];
    outTime = new int[n + 1];

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);
    cout << "In Time : " << endl;
    for (int i = 1; i < n + 1; i++)
    {
        cout << inTime[i] << " ";
    }
    cout << endl;
    cout << "Out Time : " << endl;
    for (int i = 1; i < n + 1; i++)
    {
        cout << outTime[i] << " ";
    }
    cout << endl;

    return 0;
}