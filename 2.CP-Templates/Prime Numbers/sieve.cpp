#include <bits/stdc++.h>
using namespace std;

// Seive of Erotosthenes
const int N=1000001;
vector<bool> prime(N,1);
void sieve() {
    prime[0] = prime[1] = 0;
    for (int i = 2; i * i < N; i++) {
        if (prime[i]) {
            for (int j = i * i; j < N; j += i) {
                prime[j] = 0;
            }
        }
    }
}

/* min Prime for every num  NOTE : arr[i]<= 1e6*/
// after this sieve:
//  min_prime[x] = p > 0 means p is the smallest prime that divides x
//  min_prime[x] = -1 means x is a prime
//  min_prime[x] = -2 means x is either 0 or 1
const int N = 1e6 + 17;
int min_prime[N];
void sieve(int n)
{
    memset(min_prime, -1, sizeof(min_prime));
    min_prime[0] = min_prime[1] = -2;
    for (int i = 2; i * i < n; i++)
    {
        if (min_prime[i] == -1)
        {
            for (int j = i * i; j < n; j += i)
                min_prime[j] = i;
        }
    }
}
/**
 Segmented Seive
 
 a......b;
 step 1 : make array of size b-a+1
 step 2 : generate prime seive from 2 to sqrt(b).
 step 3 : mark the indexes of the multiple of the primes generated 
          starting_index till the end
          starting_index = ceil(a/prime[i])*prime[i] - a (if a==prime[i] then ceil(a/prime[i])++)
*/
vector<int> Prime;
void buildSeive()
{
    int N = 1e4 + 1;
    vector<bool> isPrime(N + 1, 1);
    isPrime[0] = 0;
    isPrime[1] = 0;
    for (int i = 2; i * i <= N; i++)
    {
        for (int j = i * i; j <= N; j += i)
        {
            if (isPrime[i])
                isPrime[j] = 0;
        }
    }
    forn(i, N + 1) if (isPrime[i]) Prime.pb(i);
}
/**
0 1 1 0 1 0 1 0 0 0  1  0  1  0  0  0  1  0  1  0  0  0  1  0  0
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
*/
void rangePrime()
{
    int l, r;
    cin >> l >> r;
    int rootB = sqrt(r);
    vector<bool> rangePrime(r - l + 1, 1);
    for (auto pr : Prime)
    {
        int multiple = ceil((double)l * 1.0 / (double)pr);
        if (multiple == 1)
            multiple++;
        int stIdx = multiple * pr - l;
        for (int j = stIdx; j < rangePrime.size(); j += pr)
        {
            rangePrime[j] = 0;
        }
    }
    int ans = 0;
    for (int i = 0; i < rangePrime.size(); i++)
    {
        if (rangePrime[i])
            ans++;
    }
    cout << ans << endl;
}
