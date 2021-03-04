#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repA(i, a, n) for (int i = a; i <= (n); ++i)
#define repD(i, a, n) for (int i = a; i >= (n); --i)

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    string ans = "";

    s.erase(remove(s.begin(), s.end(), 'A'), s.end());
    s.erase(remove(s.begin(), s.end(), 'E'), s.end());
    s.erase(remove(s.begin(), s.end(), 'I'), s.end());
    s.erase(remove(s.begin(), s.end(), 'O'), s.end());
    s.erase(remove(s.begin(), s.end(), 'U'), s.end());
    s.erase(remove(s.begin(), s.end(), 'Y'), s.end());
    s.erase(remove(s.begin(), s.end(), 'a'), s.end());
    s.erase(remove(s.begin(), s.end(), 'e'), s.end());
    s.erase(remove(s.begin(), s.end(), 'i'), s.end());
    s.erase(remove(s.begin(), s.end(), 'o'), s.end());
    s.erase(remove(s.begin(), s.end(), 'u'), s.end());
    s.erase(remove(s.begin(), s.end(), 'y'), s.end());

    transform(s.begin(), s.end(), s.begin(), ::tolower);
  
    for (int i = 0; i < s.size(); i++)
    {
        ans = ans+"." + s[i];
    }
    cout << ans << endl;

    return 0;
}