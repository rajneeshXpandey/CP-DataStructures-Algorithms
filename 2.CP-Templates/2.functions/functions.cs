using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;

class Program
{
    const long MOD = 1000000007;
    static void FastIO() => System.Console.OutputEncoding = System.Text.Encoding.UTF8;

    // -------------------------------- Utility Functions --------------------------------

    static long Power(long x, long y)
    {
        long res = 1;
        x %= MOD;
        while (y > 0)
        {
            if ((y & 1) == 1)
                res = (res * x) % MOD;
            y >>= 1;
            x = (x * x) % MOD;
        }
        return res;
    }

    static long Fact(long n)
    {
        if (n <= 1) return 1;
        return n * Fact(n - 1);
    }

    static long NCr(int n, int r)
    {
        if (r == 0 || r == n) return 1;
        if (r == 1) return n;
        if ((n - r) > r) r = n - r;
        long[] C = new long[r + 1];
        C[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = Math.Min(i, r); j > 0; j--)
                C[j] = C[j] + C[j - 1];
        }
        return C[r];
    }

    static long HCF(long a, long b)
    {
        return b == 0 ? a : HCF(b, a % b);
    }

    static long LCM(long a, long b)
    {
        return (a * b) / HCF(a, b);
    }

    static long StrToInt(string s)
    {
        return long.Parse(s);
    }

    static string IntToStr(long n)
    {
        return n.ToString();
    }

    static long HCFofArray(long[] arr)
    {
        long res = arr[0];
        for (int i = 1; i < arr.Length; i++)
            res = HCF(res, arr[i]);
        return res;
    }

    static long HCFofVector(List<long> arr)
    {
        long res = arr[0];
        for (int i = 1; i < arr.Count; i++)
            res = HCF(res, arr[i]);
        return res;
    }

    static long LCMofArray(long[] arr)
    {
        long res = arr[0];
        for (int i = 1; i < arr.Length; i++)
            res = (res * arr[i]) / HCF(res, arr[i]);
        return res;
    }

    static long LCMofVector(List<long> arr)
    {
        long res = arr[0];
        for (int i = 1; i < arr.Count; i++)
            res = (res * arr[i]) / HCF(res, arr[i]);
        return res;
    }

    static Dictionary<long, long> CountFreqArray(long[] arr)
    {
        var dict = new Dictionary<long, long>();
        foreach (var x in arr)
        {
            if (dict.ContainsKey(x)) dict[x]++;
            else dict[x] = 1;
        }
        return dict;
    }

    static Dictionary<long, long> CountFreqVector(List<long> arr)
    {
        var dict = new Dictionary<long, long>();
        foreach (var x in arr)
        {
            if (dict.ContainsKey(x)) dict[x]++;
            else dict[x] = 1;
        }
        return dict;
    }

    static bool ElementPresent(List<long> arr, long a)
    {
        return arr.Contains(a);
    }

    static List<long> ChangeArrToVector(long[] arr)
    {
        return new List<long>(arr);
    }

    static bool ChkPrime(long n)
    {
        if (n < 2) return false;
        for (long i = 2; i * i <= n; i++)
            if (n % i == 0) return false;
        return true;
    }

    static void Factorize(long n)
    {
        int count = 0;
        while (n % 2 == 0)
        {
            n >>= 1;
            count++;
        }
        if (count > 0) Console.WriteLine($"2 : {count}");
        for (long i = 3; i * i <= n; i += 2)
        {
            count = 0;
            while (n % i == 0)
            {
                count++;
                n /= i;
            }
            if (count > 0) Console.WriteLine($"{i} : {count}");
        }
        if (n > 2) Console.WriteLine($"{n} : 1");
    }

    static void SieveOfEratosthenes(int n)
    {
        bool[] prime = Enumerable.Repeat(true, n + 1).ToArray();
        for (int p = 2; p * p <= n; p++)
        {
            if (prime[p])
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
        }
        for (int p = 2; p <= n; p++)
            if (prime[p]) Console.Write(p + " ");
        Console.WriteLine();
    }

    // -------------------------------- Solve --------------------------------

    static void Solve()
    {
        // implement logic here
    }

    // -------------------------------- Main --------------------------------
    static void Main()
    {
        FastIO();
        int t = 1;
        if (int.TryParse(Console.ReadLine(), out int T)) t = T;
        while (t-- > 0)
        {
            Solve();
        }
    }
}
