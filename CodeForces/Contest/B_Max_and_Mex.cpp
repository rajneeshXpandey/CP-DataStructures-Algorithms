#include<bits/stdc++.h>
using namespace std;

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
#define pqmn   priority_queue<int,vector<int>,greater<int>> //minheap
#define mod             1000000007
#define inf             100000000000000000 //1e17
#define Pi              acos(-1.0)
#define precise(x,y)    fixed<<setprecision(y)<<x
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

int missing(vector<int> array,int start, int end)
{
    if (start > end)
        return end + 1;

    if (start != array[start])
        return start;

    int mid = (start + end) / 2;
    if (array[mid] == mid)
        return missing(array, mid + 1, end);

    return missing(array, start, mid);
}

signed main()
{
    FIO;
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr;
        pqmx max_heap;
        for (int i = 0; i < n; i++)
        {   int x;
            cin>>x;
            arr.pb(x);          
        }
        if(k==0)
          cout<<n<<endl;
        else{  
        sort(all(arr));       
        int miss = missing(arr, 0,n-1);
        int mxx = *max_element(all(arr));
        int val = ceil(ceil(mxx+miss)/ceil(2));      
        if (miss > mxx)
            cout  << n + k << endl;
       else{
           if (binary_search(all(arr), val))
            cout<<n<<endl;
           else 
            cout<<n+1<<endl;  
       }}
               
    }
    return 0;
}