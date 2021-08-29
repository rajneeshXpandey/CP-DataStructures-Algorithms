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

unordered_map<string, int> mp;

    bool isScramble(string s1, string s2)
    {

        if (s1.size() != s2.size())
            return false;
        if (s1 == "" or s2 == "")
            return false;
        if (s1 == s2)
            return true;
        string key = s1 + "_" + s2;
        if (mp.find(key) != mp.end())
            return mp[key];
        bool flag = false;
        int n = s1.size();
        for (int i = 1; i <= n - 1; i++)
        {
            if ((isScramble(s1.substr(0, i), s2.substr(n - i, i)) and isScramble(s1.substr(i, n - i), s2.substr(0, n - i))) or (isScramble(s1.substr(0, i), s2.substr(0, i)) and isScramble(s1.substr(i, n - i), s2.substr(i, n - i))))
            {
                flag = true;
                break;
            }
        }
        return mp[key] = flag;
    }


signed main()
{
    FIO;
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        string s1,s2;
        cin>>s1>>s2;
        cout<< isScramble(s1, s2)<<endl;;
    }
    return 0;
}