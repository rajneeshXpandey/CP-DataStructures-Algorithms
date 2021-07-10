#include <bits/stdc++.h>
using namespace std;

int dp[501][501];
class Solution
{
public:
    bool isPalindrome(string s, int i, int j)
    {

        while (i < j)
        {
            if (s[i] != s[j])
                return 0;

            i++;
            j--;
        }
        return 1;
    }

    int MCM(string s, int i, int j)
    {
        //base
        if (i >= j || isPalindrome(s, i, j))
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int mn = INT_MAX;
        for (int k = i; k < j; k++)
        {
            int left, right;
            if (dp[i][k] == -1)
            {
                left = MCM(s, i, k);
                dp[i][k] = left;
            }
            else
                left = dp[i][k];
            if (dp[k + 1][j] == -1)
            {
                right = MCM(s, k + 1, j);
                dp[k + 1][j] = right;
            }
            else
                right = dp[k + 1][j];

            int temp = left + right + 1;

            mn = min(mn, temp);
        }

        return dp[i][j] = mn;
    }

    int palindromicPartition(string str)
    {
        // code here
        memset(dp, -1, sizeof(dp));
        return MCM(str, 0, str.size() - 1);
    }
};


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;

        Solution ob;
        cout << ob.palindromicPartition(str) << "\n";
    }
    return 0;
} 