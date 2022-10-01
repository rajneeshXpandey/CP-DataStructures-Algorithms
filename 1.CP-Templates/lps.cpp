vector<int> lps(string &s) {
    int n = sz(s);
    vector<int> f(n, 0);
    for (int i = 1; i < n; i++) {
        int j = f[i - 1];
        while (j > 0 && s[i] != s[j])
            j = f[j - 1];
        if (s[i] == s[j])
            j++;
        f[i] = j;
    }
    return f;
}