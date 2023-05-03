#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)

using namespace std;
using ll = long long;

 vector<string> glob {"a", "b", "c", "d", "e", "f", "g", "h","i","j","k","l","m","n","o","p"};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        string ans="";
        for (size_t i = 0; i < s.length(); i+=4)
        {
            int index = 0;
            string st = "";
            for (size_t j = i; j < i+4; j++)
            {
                st += s[j];
            }
            index = stoi(st,0,2);

            ans += glob[index];
            
        }
        cout<<ans<<endl;
    }
    return 0;
}