/**
 You have to find the longest common subsequence in all the permutations given.
  To solve this lets make a directed graph. 
  The is an edge i -> j, if it is possible to place j after i for a subsequnce. 
  Note that you can place j after i only if in all the permutation j comes after i.
  We can make this graph in O(N * N). The answer would be simply the longest path in this graph.
  The contructed graph will have no cycles so we can do a DAG DP to find the answer in O(V + E)
*/
#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const int M = 10;
const int N = 1000;


int main()
{
        int n, k;
        cin >> n >> k;
        assert(n >= 1 && n <= N);
        assert(k >= 1 && k <= M);
        vector<vector<int>> pos(k, vector<int>(n + 1, -1));
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int temp;
                cin >> temp;
                pos[i][temp] = j;
            }
            for (int j = 1; j <= n; j++)
                assert(pos[i][j] != -1);
        }

        vector<vector<int>> adj(n + 1);
        vector<int> ideg(n + 1), dp(n + 1, 1);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int ok = 1;
                for (int x = 0; x < k; x++)
                {
                    ok &= pos[x][i] > pos[x][j];
                }
                if (ok)
                {
                    adj[i].push_back(j);
                    ideg[j]++;
                }
            }
        }

        queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            if (!ideg[i])
                q.push(i);
        }

        while (q.size())
        {
            int node = q.front();
            q.pop();
            for (int nxt : adj[node])
            {
                dp[nxt] = max(dp[nxt], 1 + dp[node]);
                ideg[nxt]--;
                if (!ideg[nxt])
                {
                    q.push(nxt);
                }
            }
        }

        cout << *max_element(dp.begin(), dp.end()) << "\n";
    
}