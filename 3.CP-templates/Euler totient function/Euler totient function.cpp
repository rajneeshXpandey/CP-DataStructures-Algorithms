/* Here is an implementation using factorization in O(√n) :*/

int phi(int n){
    int result = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

/* Euler totient function from 1 to n in O(nloglogn) */

void phi_1_to_n(int n)
{
    vector<int> phi(n + 1);
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= n; j += i)
                phi[j] = phi[j] - phi[j] / i; // phi[j](1 - 1/i);
        }
    }
}

/*
    Divisor sum property
    This interesting property was established by Gauss:

                ∑   ϕ(d)=n
               d|n

    Here the sum is over all positive divisors d of n.

    For instance the divisors of 10 are 1, 2, 5 and 10. 
    Hence ϕ(1)+ϕ(2)+ϕ(5)+ϕ(10)=1+1+4+4=10.

    Finding the totient from 1 to n using the divisor sum property

    The divisor sum property also allows 
    us to compute the totient of all numbers between 1 and n. This implementation is a little simpler than the previous implementation based on the Sieve of Eratosthenes, however also has a slightly worse complexity: O(nlogn)

*/

void phi_1_to_n(int n)
{
    vector<int> phi(n + 1);
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i - 1;

    for (int i = 2; i <= n; i++)
        for (int j = 2 * i; j <= n; j += i)
            phi[j] -= phi[i];
}