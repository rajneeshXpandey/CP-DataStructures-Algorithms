/**
  Calculating a^(b^c)
  
  a^(p-1) === 1(mod p) // fermat's little theoreom
  so , let b^c = q*(p-1)+rem
    a^(b^c) = a^(q*(p-1)) * a^(rem)
                 |
                 v
                 1 = a^(p-1)
*/
int modexpo(int a, int n, int p) {
    int res = 1;
    while (n > 0)
    {
        if (n % 2)
            res = (res * a)%p;
        a = (a*a)%p;
        n /= 2;
    }
    return res;
}

int rem = modexpo(b,c,mod-1);
cout << modexpo(a, rem,mod) << endl;