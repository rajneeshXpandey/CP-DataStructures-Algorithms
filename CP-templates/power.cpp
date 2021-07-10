// Modulo expo
// result for (a^n)%p

int power(int a, int n, int p) {
    int res = 1;
    while (n > 0)
    {
        if (n % 2)
            res = (res * a)%p, n--;
        else
            a = (a*a)%p, n /= 2;
    }
    return res;
}