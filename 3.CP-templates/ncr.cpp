int fc[300001];

int pwmd(int a, int n = mod - 2)
{
    if (!n)
        return 1;
    int pt = pwmd(a, n / 2);
    pt *= pt, pt %= mod;
    if (n & 1)
        pt *= a, pt %= mod;
    return pt;
}

int nCr(int n, int r)
{
    if (r > n)
        return 0;
    int den = (pwmd(fc[r]) * pwmd(fc[n - r])) % mod;
    return fc[n] * den % mod;
}

int main(){
    // preprocessing
    fc[0] = 1;
    for (int i = 1; i <= 200000; ++i)
        fc[i] = i * fc[i - 1] % mod;
}
