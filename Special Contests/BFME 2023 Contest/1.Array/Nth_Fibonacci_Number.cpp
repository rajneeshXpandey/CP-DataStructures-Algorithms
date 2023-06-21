using namespace std;
class NthFibonacciNumber
{
public:
    // DO NOT read from stdin or write to stdout.
    // Input is given as the function arguments.
    // Output is taken as the function return value.
    int getFibonacciNumber(int n)
    {
        // Code here
        if (n == 0 || n == 1)
            return n;
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
