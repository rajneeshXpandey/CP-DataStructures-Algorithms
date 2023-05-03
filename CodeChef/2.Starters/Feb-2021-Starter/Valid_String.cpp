#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(long long i=0;i<n;i++)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<long long,long long> pii;
typedef pair<ll,ll> pl;
typedef vector<long long> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
const long long mod = 1'000'000'007;
//========================================


void solve() {
    long long n,c;
    cin>>n>>c;
    string st;

   cin>>st;
   long long count =0;
     long long k = 0;
         while ( k<n and st[k] == '0')
         {
             count++;
             k++;
         }
         long long j = n - 1;
         while (j >= 0 and st[j] == '0')
         {
             count++;
             j--;
         }

     ll invalid=0;
      for (long long i = k; i <=j; i++)
     {
       if (i == j)
         break;
       if (st[i] == '1')
       {
         long long ct = 0;
         while (i <= j and st[i + 1] == '0')
         {
           ct++;
           i++;
         }
         if (ct > c)
           invalid++;
           }
     }
    //  deb(count);
    // deb(invalid);
   if(count>c)invalid++;
    if (invalid > 1)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    long long t = 1;
    cin >> t;
    //deb(t);
    while(t--) {
      solve();
    }
    return 0;
}


