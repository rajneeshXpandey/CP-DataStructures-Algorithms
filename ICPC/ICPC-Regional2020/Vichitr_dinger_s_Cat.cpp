#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> vect;
    map<int, int> count;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vect.push_back(x);
        count[x] += 1;
    }
    unordered_map<int, int> small;
    int last = 0;
    for (auto x : count)
    {
        //		cout << x.first << " " << x.second << "\t";
        small[x.first] = last;
        last += x.second;
    }
    //	cout << endl;
    //	for(auto p: small){
    //		cout << p.first << " " << p.second << "\t";
    //	}
    //	cout << endl;
    //	cout << endl;

    for (int i = 0; i < n; i++)
    {
        int x = vect[i];
        int left = small[x];
        int current = count[x];
        int right = n - left - current;
        current--;
        int ans = 0;
        if (left >= right)
        {
            ans = right;
            int add = min(left - right, current);
            ans += add;
            current -= add;
            ans += current / 2;
        }
        else
        {
            ans = left;
            int add = min(right - left, current);
            ans += add;
            current -= add;
            ans += current / 2;
        }
        cout << ans * 2 + 1 << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
