#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")

#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

//  #include <ext/pb_ds/assoc_container.hpp>
//  #include <ext/pb_ds/tree_policy.hpp>
//  using namespace __gnu_pbds;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define per(i, a, b) for (int i = (a)-1; i >= (b); i--)
#define forn(i, n) rep(i, 0, n)
#define rof(i, n) per(i, n, 0)
#define forone(i, n) for (int i = 1; i <= (n); ++i)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define ff first
#define ss second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define int long long
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define make_unique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin()); //remove Duplicate
#define generate_random(vec) generate(all(vec), rand); // fill vec with ramdom nums
#define rotate_by_k(vec,k) rotate(vec.begin(), vec.begin() + k, vec.end()); // cyclically shift a vector by k.
#define vector_to_set(a) set<int> S(all(a)); // Create a set from a vector
#define is_present(vec, key) binary_search(all(vec), key); // Check if an element occurs in a sorted sequence
#define binary_rep(n) bitset<20> (n); // binary representation of a number
#define min4(a,b,c,d) min({a, b, c, d}); // min of four elements
#define min3(a,b,c) min({a, b, c});
#define setbits(x) __builtin_popcountll(x)      // count set bits in binary rep
#define zerbefone(x) __builtin_ctzll(x)
#define pqb priority_queue<int>                               // maxheap
#define pqs priority_queue<int, vector<int>, greater<int>>    // minheap
#define piipqs priority_queue<pii, vector<pii>, greater<pii>> // minheap for pair<int,int>
#define piipqb priority_queue<pii>                            // maxheap for pair<int,int>
#define mod 1000000007   //1e9+7
#define mod1 998244353
#define inf 2000000000000000000 //2e18
#define PI  3.141592653589793238
#define mem0(a) memset(a, 0, sizeof(a))
#define mem1(a) memset(a, -1, sizeof(a))
#define meminf(a) memset(a, 0x7f, sizeof(a))
#define precise(x, y) fixed << setprecision(y) << x
#define FastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

    // find_by_order, order_of_key
    // #define pbds  tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

    mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

// mt19937_64 rng(61378913);
/* usage - just do rng() */

//assign and update min and max values.
template<typename T, typename T1> T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b) {if (b < a)a = b; return a;}

inline ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
inline void printArr(vector<int> v){for(auto val : v) cout<<val<<' '; cout<<endl;}

// *********************** Code Begins ************************ //

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
bool Exist(pbds &s, int x)
{ // this function checks weather the value (x) exists in the set or not.

    if ((s.upper_bound(x)) == s.end())
    {
        return 0;
    }
    return ((*s.upper_bound(x)) == x);
}

void Erase(pbds &s, int x)
{ // this function erases one occurrence of the value (x).

    if (Exist(s, x))
    {
        s.erase(s.upper_bound(x));
    }
}

int FirstIdx(pbds &s, int x)
{ // this function returns the first index of the value (x)..(0 indexing).

    if (!Exist(s, x))
    {
        return -1;
    }
    return (s.order_of_key(x));
}

int Value(pbds &s, int idx)
{ // this function returns the value at the index (idx)..(0 indexing).

    return (*s.find_by_order(idx));
}
int LastIdx(pbds &s, int x)
{ // this function returns the last index of the value (x)..(0 indexing).

    if (!Exist(s, x))
    {
        return -1;
    }
    if (Value(s, (int)s.size() - 1) == x)
    {
        return (int)(s.size()) - 1;
    }
    return FirstIdx(s, *s.lower_bound(x)) - 1;
}
int Count(pbds &s, int x)
{ // this function returns the number of occurrences of the value (x).

    if (!Exist(s, x))
    {
        return 0;
    }
    return LastIdx(s, x) - FirstIdx(s, x) + 1;
}
vector<int> GetHIndexScore(vector<int> &citations_per_paper)
{
    // TODO: Calculate and return h-index score for each paper.
    int n = citations_per_paper.size();
    vector<int> h_index(n,0);
    pbds s;
    h_index[0] = 1;
    s.insert(citations_per_paper[0]);
    for(int i=1;i<n;i++)
    {
        int c = citations_per_paper[i];
        h_index[i] = h_index[i-1];
        s.insert(c);
        int greater_elements = s.size() - s.order_of_key(h_index[i - 1]+1);
        //deb( greater_elements);
        if (greater_elements >= h_index[i - 1]+1)
        {
            h_index[i] = h_index[i-1]+1;
        }
    }
    return h_index;
}

signed main()
{
    FastIO;
    int tests;
    cin >> tests;
    for (int test_case = 1; test_case <= tests; test_case++)
    {
        // Get number of papers for this test case
        int paper_count;
        cin >> paper_count;
        // Get number of citations for each paper
        vector<int> citations(paper_count);
        for (int i = 0; i < paper_count; i++)
        {
            cin >> citations[i];
        }
        vector<int> answer = GetHIndexScore(citations);
        cout << "Case #" << test_case << ": ";
        for (int i = 0; i < answer.size(); i++)
        {
            cout << answer[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
