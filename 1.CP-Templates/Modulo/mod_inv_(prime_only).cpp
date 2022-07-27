
int modexpo(int a, int n, int p)
{
    int res = 1;
    while (n > 0)
    {
        if (n % 2)
            res = (res * a) % p;
        a = (a * a) % p;
        n /= 2;
    }
    return res;
}

int modinv(int a, int m) {
    return modexpo(a, m - 2, m);
}