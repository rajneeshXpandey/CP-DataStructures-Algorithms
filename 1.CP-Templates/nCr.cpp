const int N = 1e6+1;
vector<int> fac(N);
int m = 1e9 + 7;

void pre() // call this func to precalculate
{
    fac[0] = 1;
    for (int i = 1; i < N; i++)
        fac[i] = (fac[i - 1] * i)%m; // (a*b)%m = ((a%m)*(b%m))%m
}

int modexpo(int a, int n)
{
    int res = 1;
    while (n > 0)
    {
        if (n % 2)
            res = (res * a) % m;
        a = (a * a) % m;
        n /= 2;
    }
    return res;
}

int modinv(int a)
{
    return modexpo(a, m - 2);
}

int nCr(int n, int r)
{
    int numerator = fac[n],
    denominator = (fac[n - r] * fac[r]) % m;
    denominator = modinv(denominator); // now denominator is the mod mult inverse
    int ncr = (numerator * denominator) % m;
    return ncr;
}
