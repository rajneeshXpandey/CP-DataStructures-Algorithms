#include<iostream>
// #include<algorithm>
#include<fstream>
#include<vector>
#include<string>
#include<chrono>
#include<random>
using namespace std;

#define rep(i, a, b)    for(int i = (a); i < (b); ++i)
#define per(i, a, b)    for(int i = (a) ; i >= (b); i--)
#define forn(i,n)       rep(i,0,(n))
#define rof(i,n)        per(i,(n)-1,0)
#define dbg(x)          cout << #x << "=" << x << endl
#define dbg2(x, y)      cout << #x << "=" << x << "," << #y << "=" << y << endl
#define dbg3(x, y,z)    cout << #x << "=" << x << "," << #y << "=" << y <<"," << #z << "=" << z << endl
#define ff              first
#define ss              second
#define mp              make_pair
#define all(x)          (x).begin(), (x).end()
#define endl            "\n"
#define int             long long
#define ll              long long
#define pb              push_back
#define pii             pair<int,int>
#define setbits(x)      __builtin_popcountll(x)
#define zerbefone(x)    __builtin_ctzll(x)
#define pqb             priority_queue<int> // maxheap
#define pqs             priority_queue<int,vector<int>,greater<int>> // minheap
#define piipqs          priority_queue<pii,vector<pii>,greater<pii>> // minheap for pair<int,int>
#define piipqb          priority_queue<pii> // maxheap for pair<int,int>
#define mod             1000000007
#define mod2            998244353
#define memt(a)         memset(a,true,sizeof(a))
#define memf(a)         memset(a,false,sizeof(a))
#define mem0(a)         memset(a,0,sizeof(a))
#define mem1(a)         memset(a,-1,sizeof(a))
#define meminf(a)       memset(a,0x7f,sizeof(a))
#define precise(x,y)    fixed<<setprecision(y)<<x
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define yes             cout<<"YES"<<endl
#define no              cout<<"NO"<<endl
#define minus           cout<<-1<<endl
// #define oset            tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> // set
// #define osetpii         tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update> //like multiset
mt19937_64 				rng(std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 rng(61378913);
/* usage - just do rng() */

template<typename T, typename T1>T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1>T amin(T &a, T1 b) {if (b < a)a = b; return a;}

int inf = 2000000000000000000; //2e18

// ****************************************** Code Begins ****************************************** //

int custom_rand(int tnum)
{
	if (tnum < 20)
		return rng() % 100000 + 1;
	else if (tnum < 25)
		return rng() % 1000 + 1;
	return rng() % 100 + 1;
}

void solve(int tnum)
{
	ofstream in;
	string file = "input/input_" + to_string(tnum) + ".txt";
	int n[4];
	vector<int> v[4];
	in.open(file);
	forn(i, 4)
	{
		n[i] = custom_rand(tnum);
		in << n[i] << endl;
		v[i].resize(n[i]);
		forn(j, n[i])
		{
			v[i][j] = rng() % inf + 1;
			in << v[i][j] << " ";
		}
		in << endl;
		// sort(all(v[i]));
	}
	in.close();
	int ptr[4] = {0};
	pair<int, vector<int>> best = {inf, {inf, inf, inf, inf}};

	ofstream os;
	file = "output/output_" + to_string(tnum) + ".txt";
	os.open(file);
	while (1)
	{
		pii mn = {inf, -1};
		pii mx = { -inf, -1};
		vector<int> curr_window;
		forn(i, 4)
		{
			amin(mn, mp(v[i][ptr[i]], i));
			amax(mx, mp(v[i][ptr[i]], i));
			curr_window.push_back(v[i][ptr[i]]);
		}
		amin(best, mp(mx.ff - mn.ff, curr_window));
		ptr[mn.ss]++;
		if (ptr[mn.ss] == n[mn.ss])
		{
			int ansmin = inf, ansmax = -inf;
			forn(j, 4)
			{
				amin(ansmin, best.ss[j]);
				amax(ansmax, best.ss[j]);
			}
			int finalans = (ansmax - ansmin);
			os << finalans << endl;
			break;
		}
	}
	os.close();
}

signed main()
{
	int tt = 1;
	// cin >> tt;
	for (int tnum = 1; tnum <= tt; tnum++)
		solve(tnum);
}