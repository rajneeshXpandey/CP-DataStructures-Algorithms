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

vector<int> adj[10000];

int dist[10000];
int visited[10000];
vector<int> prime;

bool isPrime(int n)
{
    for (int i = 2; i*i <= n; i++)
    {
        if((n % i)==0) return false;
    }
    return true;
}

void buildPrime()
{
    prime.clear();
    for (int i = 1000; i<=9999; i++)
    {
        if(isPrime(i))
          prime.pb(i);
    }   
}
bool isValid(int a,int b)
{
    int c=0;
    while(a > 0)
    {
        if((a % 10)!=(b%10))
         c++;
        a = a/10;
        b = b/10;
    }
    return (c==1);
}

void buildGraph()
{
       for (int i=0; i<prime.size(); i++)
       {
          for (int j = i+1; j < prime.size(); j++)
          {
              if(isValid(prime[i],prime[j]))
               {
                   adj[prime[i]].pb(prime[j]);
                   adj[prime[j]].pb(prime[i]);
               }
          }
           
       }
       
}

void bfs(int root)
{
    queue<int> q;
    q.push(root);
    int d = 0;
    while (!q.empty())
    {
        int sz = q.size();

        while (sz--)
        {
            int node = q.front();
            if (!visited[node])
                dist[node] = d;
            visited[node] = 1;
            for (auto nb : adj[node])
            {
                if (!visited[nb])
                    q.push(nb);
            }
            q.pop();
        }
        d++;
    }
}

signed main()
{
    FIO;
    int t;
    cin >> t;
    buildPrime();
    buildGraph();
    while (t--)
    {
        int a,b;
        cin>>a>>b;      
        for (int i = 1000; i<10000; i++)
        {
            dist[i]= -1;
            visited[i]=0;
        }
        bfs(a);
        if(dist[b]!=-1)
         cout<<dist[b]<<endl;
        else cout<<"Imposible"<<endl;
    }

    return 0;
}