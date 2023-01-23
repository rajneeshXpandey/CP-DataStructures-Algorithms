
//1-base //better to use 2 hashes

/*
    const int p = 31;
    const int m = 1e9 + 9;
*/
int power(int x, int y, int p) {
    int res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
int modinv(int a, int m) {
    return power(a, m - 2, m);
}
struct Hash{
    vector<int> pref,powers,inv_powers;
    int p,m;
    Hash(string &s,int _p,int _m): p(_p) , m(_m)
    {
        int n=s.size();
        powers.resize(n+1,0);
        pref.resize(n+1,0);
        inv_powers.resize(n+1,0);
        powers[0]=1;
        int p_inv=modinv(p,m);
        inv_powers[0]=1;
        for(int i=1;i<=n;i++){
            pref[i]=(pref[i-1]+(s[i-1]-'a'+1)*powers[i-1])%m;
            powers[i]=(powers[i-1]*p)%m;
            inv_powers[i]=(inv_powers[i-1]*p_inv)%m;
        }
    }
    int get(int l,int r){
        return ((pref[r]-pref[l-1]+m)*inv_powers[l-1])%m;
    }
};