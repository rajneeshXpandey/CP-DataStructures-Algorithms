#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        transform(s1.begin(),s1.end(),s1.begin(),::tolower);
        transform(s2.begin(),s2.end(),s2.begin(),::tolower);

        char cs1[s1.size()+1];
        strcpy(cs1,s1.c_str());
        char cs2[s2.size() + 1];
        strcpy(cs2, s2.c_str());

        int ans = strcmp(cs1,cs2);

        if(ans<0) cout<<-1<<endl;
        else if(ans==0) cout<<0<<endl;
        else if(ans>0) cout<<1<<endl;
    }
    return 0;
}