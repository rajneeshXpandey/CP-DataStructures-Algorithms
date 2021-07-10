#include <bits/stdc++.h>
using namespace std;

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
#define pqmn priority_queue<int, vector<int>, greater<int>> // minheap
#define mod 1000000007
#define inf 100000000000000000 //1e17
#define Pi acos(-1.0)
#define precise(x, y) fixed << setprecision(y) << x
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool regular(char arr[], int n)
{
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == '(')
            st.push('(');
        if (st.size() == 0)
            return 0;
        if (arr[i] == ')')
            st.pop();
    }
    return !(st.size());
}

signed main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        string s;
        cin >> s;
        int n = s.size();
        char arr1[n];
        char arr2[n];
        if (s[0] == s[n - 1])
        {
            cout << "NO" << endl;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (s[i] == s[0])
                {
                    arr1[i] = '(';
                    arr2[i] = '(';
                }
                else if (s[i] == s[n - 1])
                {
                    arr1[i] = ')';
                    arr2[i] = ')';
                }
            }

            for (int i = 0; i < n; i++)
            {
                if (s[i] != s[0] and s[i] != s[n - 1])
                {
                    arr1[i] = '(';
                    arr2[i] = ')';
                }
            }

            if (regular(arr1, n) or regular(arr2, n))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}