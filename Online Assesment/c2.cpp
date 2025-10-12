#include <bits/stdc++.h>
#include <iostream>
using namespace std;

long minimizeSystemCost(int k, vector<int> machines)
{
    int n = machines.size();
    if (n <= k + 1)
        return 0;
    vector<long> diff(n - 1), prefix(n, 0);
    for (int i = 1; i < n; ++i)
        diff[i - 1] = abs(machines[i] - machines[i - 1]);
    for (int i = 1; i < n; ++i)
        prefix[i] = prefix[i - 1] + diff[i - 1];

    long total = prefix[n - 1], minCost = LONG_MAX;
    int left, right;

    for (int i = 0; i + k <= n; ++i){
        left = i - 1;
        right = i + k;
        long removed = prefix[i + k - 1] - prefix[i];
        if (i > 0)
            removed += abs(machines[i] - machines[i - 1]);
        if (i + k < n)
            removed += abs(machines[i + k] - machines[i + k - 1]);
        if (i > 0 && i + k < n)
            removed -= abs(machines[i + k] - machines[i - 1]);
        minCost = min(minCost, total - removed);
    }
    return minCost;
}

int main()
{
    vector<int> machines = {3, 9, 4, 2, 16};
    int k = 3;
    cout << minimizeSystemCost(k, machines) << endl;
    return 0;
}