#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;

const int mod = 1'000'000'007;
//========================================

bool cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.first == b.first)
      return a.second < b.second;
      else
          return a.first > b.first;
}

void solve()
{
     int n;
    cin >> n;
    int arr[n];
    for (size_t i = 0; i < n; i++)
        cin >> arr[i];
    vector<pair<int, int>> vp;
    for (int i = 0; i < n; ++i)
        vp.push_back(make_pair(arr[i], i));
    sort(vp.begin(), vp.end(),cmp);
    int ans[n+1];
    for (int i =0; i <n ; i++)
    {    
           ans[vp[i].second] = i+1;
    }

    for (int i = 0; i<n ; i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    cin >> t;
    //deb(t);
    while (t--)
    {
        solve();
    }
    return 0;
}
