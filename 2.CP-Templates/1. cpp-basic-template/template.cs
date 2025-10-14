using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;

class Program
{
    static void FastIO() => System.Console.OutputEncoding = System.Text.Encoding.UTF8;

    // Utility functions
    static long Gcd(long a, long b) => b == 0 ? a : Gcd(b, a % b);

    static long Power(long a, long n, long mod)
    {
        a %= mod;
        long res = 1;
        while (n > 0)
        {
            if ((n & 1) == 1) res = (res * a) % mod;
            a = (a * a) % mod;
            n >>= 1;
        }
        return res;
    }

    static long Cdiv(long a, long b) => a / b + (((a ^ b) > 0 && a % b != 0) ? 1 : 0);
    static long Fdiv(long a, long b) => a / b - (((a ^ b) < 0 && a % b != 0) ? 1 : 0);

    static void Binary(long n) => Console.WriteLine(Convert.ToString(n, 2).PadLeft(64, '0'));

    static void Assign1ToN(List<long> v)
    {
        for (int i = 0; i < v.Count; i++) v[i] = i + 1;
    }

    // Debugging
    static void Deb<T>(string name, T value) => Console.WriteLine($"{name} = {value}");
    static void PrintDS<T>(IEnumerable<T> ds) => Console.WriteLine(string.Join(" ", ds));
    static void Print<T>(T value) => Console.WriteLine(value);

    // Constants
    const long INF = 2000000000000000000;
    const double PI = 3.141592653589793238;
    const double EPS = 1e-12;

    // ********************************* start ********************************** //
    static void Solve()
    {
        int n = int.Parse(Console.ReadLine()!);
        var arr = Console.ReadLine()!.Split().Select(long.Parse).ToList();
        // TODO: your logic here
    }

    static void Main()
    {
        FastIO();
        int totalTestcases = 1;
        if (int.TryParse(Console.ReadLine(), out int t)) totalTestcases = t;
        for (int test_case = 1; test_case <= totalTestcases; test_case++)
        {
            Solve();
        }
    }
}
