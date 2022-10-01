#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e18;
#define FastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

/***********************/	
int dp[21][(1<<20)+1];
int minPowerSum(int idx,int mask,int &n,vector<int> &a){
	if(idx==n) return 0;
	if(dp[idx][mask]!=-1) return dp[idx][mask];
	if(mask&(1<<idx)) 
		return dp[idx][mask] = minPowerSum(idx+1,mask,n,a);
	int minPow = inf; // min pow sum with a[idx] as one ele.
	for(int i=0;i<n;i++){
		if(i==idx or (mask&(1<<i))) continue;
		int new_mask = (mask | (1<<idx) | (1<<i));
		minPow = min(minPow,
				(a[idx]^a[i])+minPowerSum(idx+1,new_mask,n,a));
	}
	return dp[idx][mask] = minPow;
}

int maxPowerSum(int idx,int mask,int &n,vector<int> &a){
	if(idx==n) return 0;
	if(dp[idx][mask]!=-1) return dp[idx][mask];
	if(mask&(1<<idx)) 
		return dp[idx][mask] = maxPowerSum(idx+1,mask,n,a);
	int maxPow = -inf; // max pow sum with a[idx] as one ele.
	for(int i=0;i<n;i++){
		if(i==idx or (mask&(1<<i))) continue;
		int new_mask = (mask | (1<<idx) | (1<<i));
		maxPow = max(maxPow,
				(a[idx]^a[i])+maxPowerSum(idx+1,new_mask,n,a));
	}
	return dp[idx][mask] = maxPow;
}

signed main() {
	FastIO;
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	// for(int i=0;i<n;i++) cout<<a[i]<<' ';
	memset(dp,-1,sizeof(dp));
	int minPower = minPowerSum(0,0,n,a);
	memset(dp,-1,sizeof(dp));
	int  maxPower=maxPowerSum(0,0,n,a);
	cout<<minPower<<' '<<maxPower<<endl;
}