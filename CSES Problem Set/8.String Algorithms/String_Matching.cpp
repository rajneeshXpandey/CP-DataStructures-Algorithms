#include <bits/stdc++.h>
using namespace std;

long long RabinKarp(string s,string ptr){

    const int p = 31;
    const int mod = 1e9 + 9;
    vector<long long> pow(s.size());
    pow[0] = 1;
    for(int i=1;i<s.size();i++){
        pow[i] = (p*pow[i-1])%mod;
        }
    vector<long long> dp(s.size()+1,0);
    for (int i = 0; i < s.size(); i++){
        dp[i+1] = dp[i] + ((s[i] - 'a' + 1) * pow[i])%mod;
    }
    long long hash_ptr = 0;
    for(int j = 0;j<ptr.size();j++)
        hash_ptr = (hash_ptr + (ptr[j] - 'a' + 1) * pow[j])%mod;

    vector<int> match;
    for (int i = 0; i + ptr.size() - 1 < s.size(); i++)
    {
        long long cur_h = (dp[i + ptr.size()] + mod - dp[i]) % mod;
        if (cur_h == hash_ptr * pow[i] % mod)
            match.push_back(i);
    }
    // for(auto m : match) cout<<(m)<<' ';
    return match.size();  
}

long long KMP(string s,string p){ 
  string str = p + "#" + s;
  vector<int> pi(str.size());
  pi[0] = 0;
  for(int i=1;i<str.size();i++){
      int l = pi[i-1];
      while(l>0 and str[i]!=str[l]){
          l = pi[l-1];
      }
      if (str[i] == str[l])
        l++;
      pi[i] = l;  
  }
  int ans = 0;
  for(auto len : pi){
      if(len==p.size()){
         ans++;
      }
  }
  return ans;
}

int main()
{
     string str, pat;
     cin>>str>>pat;
    //  cout<<str<<" "<<pat<<" "<<"\n";
     cout<<KMP(str,pat)<<'\n';
    //  cout<<RabinKarp(str,pat)<<'\n';
    //  cout<<rabin_karp(str,pat)<<'\n';

    return 0;
}
