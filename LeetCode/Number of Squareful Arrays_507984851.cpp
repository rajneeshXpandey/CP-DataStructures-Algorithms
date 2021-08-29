class Solution {
public:
    bool is_perfect_square(int x) {
        const auto root = int(sqrt(x) + 0.5);
        return root * root == x;
    }

    int numSquarefulPerms(vector<int> &A) {
        const int N = A.size();
        
        /** Build a graph with an edge between i and j if A[i]+A[j] is 
            a perfect square. */
        vector<int> G[N];

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (is_perfect_square(A[i] + A[j])) {
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
            }
        }
        
        /** Held-Karp Hamiltonian paths DP. */
        int dp[(1 << N)][N];
        memset(dp,0,sizeof(dp));

        for (int i = 0; i < N; i++) {
            dp[1 << i][i] = 1;
        }

        for (int s = 3; s < (1 << N); s++) {
            for (int i = 0; i < N; i++) if (s & (1 << i)) {
                for (auto j : G[i]) if (s & (1 << j)) {
                    dp[s][i] += dp[s ^ (1 << i)][j];
                }
            }
        }

        /** Sum all paths. */
        int ans = 0;
        for (int i = 0; i < N; i++) {
            ans += dp[(1 << N) - 1][i];
        }
        
        /** Divide out permutations of equal elements. */
        for (int i = 0; i < N; i++) {
            int k = 1;
            for (int j = i + 1; j < N; j++) {
                if (A[i] == A[j]) {
                    k++;
                }
            }
            ans /= k;
        }
        
        return ans;
    }
};
