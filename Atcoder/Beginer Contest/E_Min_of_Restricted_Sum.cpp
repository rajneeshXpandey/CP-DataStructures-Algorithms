#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <bitset>
#include <numeric>
#include <climits>
using namespace std;

#define loop(i, a, b) for (int i = a; i <= b; i++)
#define rloop(i, a, b) for (int i = a; i >= b; i--)
#define forn(i, n) loop(i, 0, n - 1)
#define tuplei tuple<int, int, int>;

// assign and update min and max values.
template <typename T, typename T1>
T amax(T &a, T1 b)
{
    if (b > a)
        a = b;
    return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b)
{
    if (b < a)
        a = b;
    return a;
}

#define FastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

// Debugging
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define deb4(x, y, z, zz) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << "," << #zz << "=" << zz << endl
template <typename T>
inline void printDS(T dataStructure)
{
    for (auto val : dataStructure)
        cout << val << ' ';
    cout << endl;
}
template <typename T>
inline void print(T anything) { cout << anything << "\n"; }

// Data structures
#define max_heap priority_queue<int>                            // maxpq
#define min_heap priority_queue<int, vector<int>, greater<int>> // minpq

// numeric values
// #define mod 1000000007   //1e9+7
// #define mod 998244353
#define inf 2000000000000000000 // 2e18
#define pi 3.141592653589793238
double eps = 1e-12;

// ********************************* start ********************************** //

// This function merges two sorted subarrays arr[l..m] and arr[m+1..r]
// and also counts inversions in the whole subarray arr[l..r]
int countAndMerge(vector<int> &arr, int l, int m, int r)
{

    // Counts in two subarrays
    int n1 = m - l + 1, n2 = r - m;

    // Set up two vectors for left and right halves
    vector<int> left(n1), right(n2);
    for (int i = 0; i < n1; i++)
        left[i] = arr[i + l];
    for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    // Initialize inversion count (or result) and merge two halves
    int res = 0;
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {

        // No increment in inversion count if left[] has a
        // smaller or equal element
        if (left[i] <= right[j])
            arr[k++] = left[i++];

        // If right is smaller, then it is smaller than n1-i
        // elements because left[] is sorted
        else
        {
            arr[k++] = right[j++];
            res += (n1 - i);
        }
    }

    // Merge remaining elements
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];

    return res;
}

// Function to count inversions in the array
int countInv(vector<int> &arr, int l, int r)
{
    int res = 0;
    if (l < r)
    {
        int m = (r + l) / 2;

        // Recursively count inversions in the left and
        // right halves
        res += countInv(arr, l, m);
        res += countInv(arr, m + 1, r);

        // Count inversions such that greater element is in
        // the left half and smaller in the right half
        res += countAndMerge(arr, l, m, r);
    }
    return res;
}

int inversionCount(vector<int> &arr)
{
    int n = arr.size();
    return countInv(arr, 0, n - 1);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    forn(i, n) cin >> arr[i];
    int cur = inversionCount(arr);
    vector<vector<int>> pos(m);
    for (int i = 0; i < n; i++)
    {
        pos[arr[i]].push_back(i);
    }
    cout << cur << "\n";
    for (int i = m - 1; i > 0; i--)
    {
        int kk = pos[i].size();
        for (int j = 0; j < kk; j++)
        {
            int x = pos[i][j];
            int tot = j - (n - 1 - x - (kk - j - 1));
            cur += tot;
        }
        cout << cur << "\n";
    }
}

signed main()
{
    FastIO;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int total_testcases = 1;
    // cin >> total_testcases;
    for (int test_case = 1; test_case <= total_testcases; test_case++)
    {
        // cout<<"Case #"<< test_case <<": ";
        solve();
    }
}