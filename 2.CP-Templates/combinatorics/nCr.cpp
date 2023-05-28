const int N = 1e6+1;
vector<int> fac(N);
int mod = 1e9 + 7;

void pre() // call this func to precalculate
{
    fac[0] = 1;
    for (int i = 1; i < N; i++)
        fac[i] = (fac[i - 1] * i)%mod; // (a*b)%m = ((a%m)*(b%m))%m
}

int modinv(int a){
    return power(a,mod-2,mod);
}

int nCr(int n, int r){
    int numerator = fac[n],
    denominator = (fac[n - r] * fac[r]) % mod;
    denominator = modinv(denominator); // now denominator is the mod mult inverse
    int ncr = (numerator * denominator) % mod;
    return ncr;
}
