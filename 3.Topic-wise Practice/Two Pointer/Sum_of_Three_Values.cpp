#include "bits/stdc++.h"
using namespace std;

//  #include <ext/pb_ds/assoc_container.hpp>
//  #include <ext/pb_ds/tree_policy.hpp>
//  using namespace __gnu_pbds;

#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define ff first
#define ss second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define int long
#define pb push_back
#define pii pair<int, int>

#define FastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

    // find_by_order, order_of_key
    // #define pbds  tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

    mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// *********************** Code Begins ************************ //

void solve(){
    int n, t;
    cin >> n >> t;
    vector<pii> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i].ff; v[i].ss = i+1;
    }
    sort(all(v));
    for (int i = 0; i < n; i++)
    {
        int k = n-1;
        for (int j = i + 1; j < k; j++)
        {
            while (v[k].ff > (t - v[i].ff - v[j].ff))
                k--;
            if (v[i].ff + v[j].ff + v[k].ff == t and j<k)
            {
                cout<<v[i].ss<<" "<< v[j].ss<<" "<<v[k].ss;
                return;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
}
/*

x = 12

  i j        k

1 2 3 5 5 7 11

*/
signed main()
{

    //freopen("test_input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    FastIO;
    int tt = 1;
    for (int i = 1; i <= tt; i++)
        {            
         // cout<<"Case #"<< i <<": "; 
         solve();
        }        
}