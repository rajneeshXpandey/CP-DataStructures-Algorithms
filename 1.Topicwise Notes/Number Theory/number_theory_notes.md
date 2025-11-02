# Number Theory Techniques

## 1. Find All Divisors of a Number

**Time Complexity**: O(√N)

```cpp
for(int i=1; i*i<=N; i++) {
    if(N%i == 0) {
        // i and N/i are divisors
    }
}
```

---

## 2. Check Prime

**Time Complexity**: O(√N)

---

## 3. Number of Divisors

Prime factorization of n is `p1^e1 * p2^e2 * ... * pk^ek`, where `pi` are distinct prime numbers.

Then the number of divisors is:

**d(n) = (e1+1) × (e2+1) × ... × (ek+1)**

### Divisors Generation Example

For `p1^e1 * p2^e2`:

|        | 1 | p2 | p2² | ... | p2^e2 |
|--------|---|----|----|-----|-------|
| 1      | • | •  | •  | •   | •     |
| p1     | • | •  | •  | •   | •     |
| p1²    | • | •  | •  | •   | •     |
| ...    | • | •  | •  | •   | •     |
| p1^e1  | • | •  | •  | •   | •     |

---

## 4. Sum of Divisors

If `n = p1^e1 * p2^e2 * ... * pk^ek`, then:

**σ(n) = [(p1^(e1+1) - 1) / (p1 - 1)] × [(p2^(e2+1) - 1) / (p2 - 1)] × ... × [(pk^(ek+1) - 1) / (pk - 1)]**

Sum for every possible factor.

---

## 5. Smallest Prime Factor (SPF)

`spf[i]` → smallest prime number that divides i.

**Examples**: 
- (3, 6, 8, 10) ⇒ 3, 2, 2, 2
- If z is a prime number, `spf[z] = z`

**Problem**: Given 1 ≤ q ≤ 10⁶ queries, 1 ≤ x ≤ 10⁶, find `spf[x]` for each query.

**Solution**: Same as sieve but with numbers.

---

## 6. Problems on Prime Divisors

### Q.1) Sum of Prime Divisors

**Problem**: Given a number N, find the sum of all its prime divisors (N ≤ 10⁶)

**Example**: 12 → divisors: 1, 2, 3, 4, 6, 12  
Sum of all prime divisors = 2 + 3 = 5

**Approach**: Find all divisors and check how many are prime.

**Time Complexity**: O(N log(log(N))) + O(N) = O(N log(log(N)))

---

### Q.2) Sum of Prime Divisors for Multiple Queries

**Problem**: Solve Q.1 for q queries (q ≤ 10⁶)

**Naive Time Complexity**: O(q × N log(log(N)))

**Optimized Solution**:

```cpp
const int MAX = 1000000;
bool is_prime[MAX+1];
int Sum[MAX+1];
memset(is_prime, true, sizeof(is_prime));
is_prime[0] = is_prime[1] = false;

// Sum[i] -> sum of all its prime divisors
for(int i=2; i<=MAX; i++) {
    if(is_prime[i] == true) {
        for(int j=i; j<=MAX; j+=i) {
            if(j > i) is_prime[j] = false;
            sum[j] += i;
        }
    }
}
```

**Time Complexity**: O(N log N)

**Logic**:
- i=2 (Prime): mark 2, 4, 6, 8, 10... as non-prime and add i to Sum[j]
- Overall: O(N log N)

---

### Q.3) Count Number of Divisors

**Problem**: Given a number N, find the number of its divisors (N ≤ 10⁶)

```cpp
int count = 0;
for(int i=1; i*i<=N; i++) {
    if(N%i == 0) {
        int first_divisor = i;
        int second_divisor = (N/i);
        if(first_divisor != second_divisor) 
            count += 2;
        else 
            count++;
    }
}
cout << count << endl;
```

**Time Complexity**: O(√N)

---

### Q.4) Count Divisors for Multiple Queries

**Problem**: Solve Q.3 for q queries (q ≤ 10⁶)

**Brute Force Time Complexity**: O(q × √N) ≈ 10⁹

**Key Points**:
- N → z1^k1 × z2^k2 × z3^k3 × ...
- zi → prime number
- Number of divisors = (k1+1) × (k2+1) × (k3+1) × ...

**Optimized Solution**:

```cpp
int ans = 1;
while(n > 1) {
    int k = 0;
    int spf = SPF[n];  // smallest prime factor
    while(n % spf == 0) {
        n /= spf;
        k++;
    }
    ans = ans * (k+1); 
}
cout << ans << endl;
```

**Time Complexity**: O(q log n)

**Example Analysis**:
- N = 2²⁰: SPF[N] = 2, loop runs 20 times = log₂(N)
- N = 2¹⁰ × 3¹⁰: Similar analysis

---

## 7. Euler's Totient Function

Euler's totient function, also known as phi-function **ϕ(n)**, counts the number of integers between 1 and n inclusive, which are coprime to n.

Two numbers are coprime if their gcd equals 1 (1 is considered to be coprime to any number).

### Properties

**1) If p is a prime number:**
```
ϕ(p) = p - 1
```
Because gcd(p, q) = 1 for all 1 ≤ q < p

**2) If p is a prime number and k ≥ 1:**
```
ϕ(p^k) = p^k - p^(k-1)
```

**Proof**:
- 9 → 3² → divisible by 3: {3, 6, 9} = 9/3 = p²/p
- phi(p^k) → p^k → {p, 2p, 3p, 4p, ..., p^k} = p^(k-1) numbers contain p, so subtract
- p^k = p + (n-1)×p
- p^(k-1) = 1 + n - 1
- N = p^(k-1)

**3) If a and b are relatively prime:**
```
ϕ(ab) = ϕ(a) × ϕ(b)
```

**4) General Formula:**

If `n = p1^a1 × p2^a2 × ... × pk^ak`, where pi are prime factors of n:

```
ϕ(n) = ϕ(p1^a1) × ϕ(p2^a2) × ... × ϕ(pk^ak)
     = (p1^a1 - p1^(a1-1)) × (p2^a2 - p2^(a2-1)) × ... × (pk^ak - pk^(ak-1))
```

### Main Formula

**ϕ(n) = n × (1 - 1/p1) × (1 - 1/p2) × ... × (1 - 1/pk)**

---

## 8. Modular Multiplicative Inverse

A modular multiplicative inverse of an integer a is an integer x such that a⋅x is congruent to 1 modular some modulus m.

**Formal Definition**:
```
a × x ≡ 1 (mod m)
(a × x) % m = 1
```

**Notation**: x is denoted as a⁻¹

**Range**: 1 ≤ x ≤ m-1

**Existence Condition**: Modular inverse exists if and only if a and m are relatively prime (i.e., gcd(a, m) = 1)

---

### Methods to Calculate Modular Inverse

#### a) Brute Force
Run loop from 1 to m-1 and check `(a×x) % m == 1`

#### b) Extended Euclidean Algorithm
```
a×x + m×y = 1  (∵ gcd(a,m) = 1)
```

```cpp
int x, y;
int g = extended_euclidean(a, m, x, y);
if (g != 1) 
    cout << "No solution!";
else {
    x = (x % m + m) % m;
    cout << x << endl;
}
```

#### c) Fermat's Little Theorem

**For any coprime a and m**:
```
a^ϕ(m) ≡ 1 (mod m)
```

Where ϕ is Euler's Totient function.

**If m is prime** (Fermat's little theorem):
```
a^(m-1) ≡ 1 (mod m)
```

Multiply both sides by a⁻¹:

**For arbitrary (coprime) modulus m**:
```
a^(ϕ(m)-1) ≡ a⁻¹ (mod m)
```

**For prime modulus m**:
```
a^(m-2) ≡ a⁻¹ (mod m)
```

Just calculate a^(m-2) by binary exponentiation.

**Time Complexity**: O(log m)

#### d) Finding Modular Inverse for All Numbers (1 to m-1)

**Using above methods**: O(M log M)

**Optimized Method**: O(M)

We denote by `inv[i]` the modular inverse of i. For i > 1:

**inv[i] = -⌊m/i⌋ × inv[m mod i] mod m**

(⌊.⌋ is floor value)

**Implementation**:

```cpp
inv[1] = 1;
for(int i = 2; i < m; ++i)
    inv[i] = m - (m/i) * inv[m%i] % m;
```

**Proof**:

We have:
```
m mod i = m - ⌊m/i⌋ × i
```

Taking both sides modulo m and multiplying by i⁻¹ × (m mod i)⁻¹ yields:
```
i⁻¹ ≡ -⌊m/i⌋ × (m mod i)⁻¹ mod m
```

---

## Property No. 1: Modular Arithmetic

**If (a - b) % k = (x - y)**

**Then:**
```
(a - x) % k = (b - y) % k
```

### Proof

**LHS**: 
```
(a - b) = (a - b) × k + (x - y)  (given)
```

Now:
```
(a - x) = (a - b) × k + (b - y)  // After reordering
```

Take modulo with k on both sides:
```
(a - x) % k = 0 + (b - y) % k
(a - x) % k = (b - y) % k  ⇒ RHS
```