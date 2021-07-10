#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;

void lcs(int, int, string, string);

int main()
{
    int t, n, k, x, y;

    cin >> t;
    while (t--)
    {
        cin >> x >> y; // Take size of both the strings as input
        string s1, s2;
        cin >> s1 >> s2; // Take both the string as input
        lcs(x, y, s1, s2);
    }
    return 0;
}

int dp[101][101];

void lcs(int n, int m, string text1, string text2)
{

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 or j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[i - 1] != text2[j - 1])
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            else
                dp[i][j] = 1 + dp[i - 1][j - 1];
        }
    }
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= m; j++)
    //     {
    //        cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int l= dp[n][m];
   char lcss[l+1];
   int idx = l;
   lcss[idx] = '\0';
   int i = n, j = m;
   while(i>0 && j>0)
        {

            if (text1[i-1]==text2[j-1])
            {
                lcss[idx-1] = text1[i - 1];
                 i--;
                 j--;
                 idx--;
            }

           else if (dp[i][j-1] > dp[i-1][j])
                   j--;
               
            else
                 i--;
           }
        cout <<lcss<<endl;
    
   
}
