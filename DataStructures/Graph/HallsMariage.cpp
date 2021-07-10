#include<bits/stdc++.h>
using namespace std;

#define setbits(x)      __builtin_popcountll(x)
#define max_men 20
#define max_women 50

int preferences[max_men][max_women];
int number_of_preferences[max_men] = {0};
bool chosen[max_women] = {0};
int boys;

bool find_matches(int man)
{
	int woman;
	if (man == boys - 1)
	{
		for (int i = 0; i < number_of_preferences[man]; i++)
		{
			woman = preferences[man][i];
			if (!chosen[woman])
			{
				chosen[woman] = 1;
				cout << "\nBride Groom " << (man + 1) << " marries Bride " << woman;
				return 1;
			}
		}
		return 0;
	}
	else
	{
		for (int i = 0; i < number_of_preferences[man]; i++)
		{
			woman = preferences[man][i];
			if (!chosen[woman])
			{
				chosen[woman] = 1;
				if (find_matches(man + 1))
				{
					cout << "\nBride Groom " << (man + 1) << " marries Bride " << woman;
					return 1;
				}
				else
					chosen[woman] = 0;
			}
		}
		return 0;
	}
}

int main()
{
	cout << "Enter number of Boys :" << endl;
	cin >> boys;
	cout << boys << endl;
	vector<int> boy[boys];
	for (int i = 0; i < boys; i++)
	{
		int num;
		cout << "How many Choices does Boy " << i + 1 << " has?" << endl;
		cin >> num;
		number_of_preferences[i] = num;
		cout << num << endl;
		if (num <= 0)
		{
			cout << "No Matching Exists" << endl;
			exit(0);
		}
		else cout << "Enter all the Choices for Boy " << i + 1 << ":" << endl;
		for (int j = 0; j < num; j++)
		{
			int girl;
			cin >> girl;
			preferences[i][j] = girl;
			boy[i].push_back(girl);
		}
		cout << endl;
	}
	// to represent subsets we exploit binary representation of numbers
	// ith bit is 1 if (i+1)th person is chosen and 0 if not 
	// suppose no. of boys=5
	//  0000 1111
	// and i=6=110(in binary)
	// 110=00110 => 2nd and 3rd bit are set here
	// which means 3rd and 4th person are chosen
	// Note : 1<<boys represents 2^boys in c++
	for (int i = 0; i < (1 << boys); i++)
	{
		int sub = i, cboys = 0, cgirls = 0;
		cboys = setbits(i);
		int idx = boys - 1;
		set<int> girlset;
		vector<int> boysinsubset;
		while (sub)
		{
			if (sub % 2 != 0)
			{
				boysinsubset.push_back(idx);
				for (int j = 0; j < boy[idx].size(); j++)
					girlset.insert(boy[idx][j]);
			}
			idx--;
			sub >>= 1;
		}
		bool condition = (girlset.size() >= cboys);
		if (!condition)
		{
			cout << "No Matching Exists because of bridegrooms ";
			sort(boysinsubset.begin(), boysinsubset.end());
			for (int i = 0; i < boysinsubset.size() - 1; i++)
				cout << (boysinsubset[i] + 1) << ", ";
			cout << (boysinsubset[boysinsubset.size() - 1] + 1);
			cout << " as They have only " << girlset.size() << " brides in preference collectively" << endl;
			exit(0);
		}
	}
	cout << endl << "Valid Matching is Found as Hall's Theorem is Satisfied!" << endl;
	find_matches(0);
	return 0;
}