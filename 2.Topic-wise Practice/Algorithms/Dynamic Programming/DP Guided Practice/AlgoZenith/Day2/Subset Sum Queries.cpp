#include <bits/stdc++.h>
using namespace std;

#define ll long long

int dp[101][100001];
bool checkTargetSum(vector<int> &arr, int level, int sum_remaining, int n)
{
    // base
    if (level == n)
    {
        if (sum_remaining != 0)
            return 0;
        else
            return 1;
    }
    // pruning
    if (sum_remaining < 0)
        return 0;
    // check caching
    if (dp[level][sum_remaining] != -1)
        return dp[level][sum_remaining];
    // transition
    bool isPossibleNotTake = checkTargetSum(arr, level + 1, sum_remaining, n);
    bool isPossibleTake = checkTargetSum(arr, level + 1, sum_remaining - arr[level], n);
    // save and return
    return dp[level][sum_remaining] = (isPossibleNotTake || isPossibleTake);
}

void getIndexes(vector<int> &arr, vector<int> &v, int level, int sum_remaining, int n)
{
    if (level == n)
    {
        return;
    }
    if (checkTargetSum(arr, level + 1, sum_remaining, n))
    { // don't take
        getIndexes(arr, v, level + 1, sum_remaining, n);
    }
    else if (checkTargetSum(arr, level + 1, sum_remaining - arr[level], n))
    { // take
        v.push_back(level);
        getIndexes(arr, v, level + 1, sum_remaining - arr[level], n);
    }
}
vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries)
{
    int n = arr.size();
    int q = queries.size();
    vector<vector<int>> result;
    memset(dp, -1, sizeof(dp));
    for (auto target : queries)
    {
        vector<int> index_of_elements;
        if (checkTargetSum(arr, 0, target, n))
            getIndexes(arr, index_of_elements, 0, target, n);
        else
            index_of_elements.push_back(-1);
        result.push_back(index_of_elements);
    }
    return result;
}
/*
Description 

Given an array of size N , and Q queries, for each query, you need to get the indices of the elements of the array whose subset-sum is equal to the queried sum sum-i , 
if possible return arr, else return − 1 .
Input Format 
Complete the Function subset_queries( vector &arr, vector &queries ) that takes vector a and queries vector as input. 
Output Format Return a vector<vector<int>> having 0 -based indices of the elements of the array whose subset-sum is equal to the queried sum sum-i 
for each i t h query, if possible, else return vector { − 1 }. 

Constraints 1 ≤ N ≤ 100 , size of vector < int > arr 1 ≤ Q ≤ 10 5 , size of vector<int> queries 1≤arr[i]≤10^5 1≤sumi≤10^5
*/

void solve()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)
        cin >> queries[i];
    auto ans = subset_queries(arr, queries);

    // checker.
    if (ans.size() != Q)
    {
        cout << 101 << endl;
        return;
    }
    for (int i = 0; i < Q; i++)
    {
        auto x = ans[i];
        if (x.size() == 0)
        {
            cout << 101 << endl;
            continue;
        }
        if (x.size() == 1 && x[0] == -1)
        {
            cout << -1 << endl;
            continue;
        }
        ll sum = 0, p = -10;
        for (auto y : x)
        {
            if (y < 0 || y >= N || p >= y)
            { // valid 0-indexed.
                sum = -1111;
                break;
            }
            p = y;
            sum += arr[y];
        }
        if (sum == queries[i])
        {
            cout << 1 << endl;
        }
        else
            cout << 101 << endl;
    }
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--)
    {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}