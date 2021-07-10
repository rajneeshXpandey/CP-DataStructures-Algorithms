#include<bits/stdc++.h>

using namespace::std;

long long dp[1001][1001];

int countPalindromicSubsequences(string s) {
       
    const int mod = 1e9+7;
    string text1 = s;
    reverse(s.begin(),s.end());
    string text2 = s;
    int n=text1.size();
    int m=text2.size();

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 or j == 0)
                dp[i][j] = 0;
            else 
            {
             if (text1[i - 1] != text2[j - 1])
                dp[i][j] = (dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1])%mod;
            else
                dp[i][j] = (1 + dp[i][j - 1]+dp[i][j - 1])%mod;   
            }
        }
    }
     return dp[n][m];
    }
int main()
{
    string s;
    cin>>s;
    cout<<countPalindromicSubsequences(s)<<endl;
}
