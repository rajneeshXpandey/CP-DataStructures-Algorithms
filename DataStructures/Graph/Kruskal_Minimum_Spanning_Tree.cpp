// rajneesh_1708 : Rajneesh Pandey
#include<bits/stdc++.h>
using namespace std;

//    cout << fixed << setprecision(10);
#define ff              first
#define ss              second
#define all(x)          (x).begin(), (x).end()
#define endl            "\n"
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define int             long long
#define pb              push_back
#define pii             pair<int,int>
#define setbits(x)      __builtin_popcountll(x)
#define zerbefone(x)    __builtin_ctzll(x)
#define pqmx            priority_queue<int> // maxheap
#define pqmn            priority_queue<int,vector<int>,greater<int>> //minheap
#define mod             1000000007
#define inf             100000000000000000 //1e17
#define Pi              acos(-1.0)
#define precise(x,y)    fixed<<setprecision(y)<<x
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

//Disjoint Set Union
int *parent;
int *ranks;

void make_set(int v)
{
    parent[v] = v;
    ranks[v] = 0;
}

int find_parent(int v)
{
    return parent[v] = (parent[v]==v)?v:find_parent(parent[v]);
}

void union_set(int a, int b)
 {
     a = find_parent(a);
     b = find_parent(b);

     if (ranks[a]==ranks[b])
     {
         parent[b] = a;
         ranks[a]++;
     }
     else if(ranks[a]>ranks[b])
        parent[b] = a;
     else
        parent[a] = b;
 }
//

class Edge{

    public:
        int a;
        int b;
        int wt;
};

bool cmp(Edge a,Edge b)
 {
     if(a.wt<b.wt)
       return true;
     else
        return false;
 }

signed main()
{
    FIO;
    int v,e;
    cin>>v>>e;
    Edge arr[e];
    for (int i = 0; i < e; i++)
    {
        cin >> arr[i].a >> arr[i].b >> arr[i].wt;
    }
    // for (int i = 0; i < e; i++)
    // {
    //     cout << arr[i].a << " " << arr[i].b << " " << arr[i].wt<<endl;
    // }

    sort(arr,arr+e,cmp);
    // cout<<"-------------"<<endl;

    // for (int i = 0; i < e; i++)
    // {
    //     cout<<arr[i].a<<" "<<arr[i].b<<" "<<arr[i].wt<<endl;
    // }

    parent = new int[v+1];
    ranks = new int[v+1];

    for (int i = 1; i < v+1; i++)
    {
        make_set(i);
    }
    int sum = 0;

    for (int i = 0; i < e; i++)
    {
        int a = find_parent(arr[i].a);
        int b = find_parent(arr[i].b);
 
       //deb2(a,b);

       if(a!=b)
        {
            sum += arr[i].wt;
            union_set(a,b);
        }
        
    }

    cout<<sum<<endl;
    
    
    return 0;
}