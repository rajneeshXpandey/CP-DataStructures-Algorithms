#include<bits/stdc++.h>
using namespace std;

#define int             long long
mt19937_64 				rng(std::chrono::steady_clock::now().time_since_epoch().count());
/* usage - just do rng() */

template<typename T, typename T1>T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1>T amin(T &a, T1 b) {if (b < a)a = b; return a;}

int inf = 1e18;

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
		sort(all(v[i]));
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