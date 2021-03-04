#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int,int> pii;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
const int mod = 1'000'000'007;
//========================================

// Category 1 : Underweight if BMI ≤18 Category 2 : Normal weight if BMI ∈{19, 20,…, 24} Category 3 : Overweight if BMI ∈{25, 26,…, 29} Category 4 : Obesity if BMI ≥30
 void solve()
{
    int m, h;
    cin >> m >> h;
    int bmi = m / (h * h);
    if (bmi <= 18)
      cout<<1<<endl;
    else if(bmi>18 and bmi<=24)
      cout<<2<<endl;
    else if (bmi > 24 and bmi <= 29)
        cout << 3<< endl;
    else if (bmi > 29 )
        cout << 4 << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    cin >> t;
    //deb(t);
    while(t--) {
      solve();
    }
    return 0;
}


