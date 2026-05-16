#include <bits/stdc++.h>
using namespace std;

// ********************************* start ********************************** //

void solve(){
    long long n,x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    long long dp[x+1];
    dp[0] = 0ll;
    for(int tsum=1;tsum<=x;tsum++){
        dp[tsum] = (long long)2e18;
        for(int i=0;i<n;i++){
            if(tsum>=arr[i])
                dp[tsum] = min(dp[tsum],1ll+dp[tsum-arr[i]]);
        }
    }
    if(dp[x]==2e18) dp[x]=-1;
    cout<<dp[x];
}

signed main(){
    solve();        
}