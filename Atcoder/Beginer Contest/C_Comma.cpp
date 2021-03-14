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
#define pqmn   priority_queue<int,vector<int>,greater<int>> //minheap
#define mod             1000000007
#define inf             100000000000000000 //1e17
#define Pi              acos(-1.0)
#define precise(x,y)    fixed<<setprecision(y)<<x
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

int totalDigits(int n)
{
    int number_of_q = 0;

    for (int i = 1000; i <= n; i *= 1000)
        number_of_q += ((n - i + 1));

    return number_of_q;
}

signed main()
{
    FIO;
    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        int n;cin>>n;
        int num = totalDigits(n);
        //deb(num);
        cout<< num <<endl;
    }
    return 0;
}