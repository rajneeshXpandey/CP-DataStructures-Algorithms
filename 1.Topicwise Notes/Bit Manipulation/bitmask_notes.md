# Bitmask Tricks and Techniques

Helpful in taking union and intersection by representation in bitmask.

---

## 1. RESET the Right-most SET Bit

Remove the rightmost set bit in a number n:

```cpp
n = n & (n-1)
```

**Example**: `101100` → `101000`

---

## 2. Counting Number of Set Bits

**Brian Kernighan's Algorithm**

```python
cnt = 0
while(n):
    cnt += 1
    n &= (n-1)
```

---

## 3. Checking if Given 32-bit Integer is Power of 2

**Logic**:
- All the power of 2 have only single bit set (e.g., 16 = `00010000`)
- If we minus 1 from this, all the bits from LSB to set bit get toggled (e.g., 16-1 = 15 = `00001111`)
- Now if we AND x with (x-1) and the result is 0, then we can say that x is power of 2, otherwise not
- We have to take extra care when x = 0

```cpp
int isPowerof2(int x)
{
    return (x && !(x & x-1));
}
```

---

## 4. All Subsets Generation

Generate all non-empty subsequences:

```cpp
vector<string> seq;  /* stores all non empty subsequences */
string s;
cin >> s;
int n = s.length();

for(int i=1; i<(1<<n); i++) {  // 1 to 2^n-1
    string temp = "";
    for(int j=0; j<n; j++) {
        if(i & (1<<j)) {  // if jth bit in i is set
            temp += s[j];
        }
    }
    seq.push_back(temp);
}

for(int i=0; i<seq.size(); i++) {
    cout << seq[i] << " ";
}
```

**Note**: It generates every possible subset of a set.

**Example**: `1001` generates: `0000`, `0001`, `1001`, `1000`

---

## 5. Enumerating All Submasks of a Given Mask

Given a bitmask m, we want to efficiently iterate through all of its submasks, that is, masks s in which only bits that were included in mask m are set.

```cpp
for (int s=m; ; s=(s-1)&m) {
    /* ... you can use s ... */
    if (s==0)  break;
}
```

### Proof

Suppose we have a current bitmask s, and we want to move on to the next bitmask:

1. By subtracting from the mask s one unit, we will remove the rightmost set bit and all bits to the right of it will become 1
2. Then we remove all the "extra" one bits that are not included in the mask m and therefore can't be a part of a submask
3. We do this removal by using the bitwise operation `(s-1) & m`
4. As a result, we "cut" mask s−1 to determine the highest value that it can take, that is, the next submask after s in descending order

---

### Iterating Through All Masks With Their Submasks

**Complexity**: O(3^n)

In many problems, especially those that use bitmask dynamic programming, you want to iterate through all bitmasks and for each mask, iterate through all of its submasks:

```cpp
for (int m=0; m<(1<<n); ++m)
    for (int s=m; s; s=(s-1)&m)
        /* ... s and m ... */
```

---

## Additional Useful Operations

### Get the Lowest Set Bit

Two methods to get the lowest (rightmost) set bit:

**Method a)**
```cpp
i & -i
```

**Method b)**
```cpp
i & ~(i-1)
```

---

## Summary Table

| Operation | Formula | Example |
|-----------|---------|---------|
| Reset rightmost set bit | `n & (n-1)` | `101100` → `101000` |
| Count set bits | Loop with `n &= (n-1)` | Brian Kernighan's algorithm |
| Check power of 2 | `x && !(x & x-1)` | Returns true if power of 2 |
| Get lowest set bit | `i & -i` or `i & ~(i-1)` | Isolates rightmost 1 |
| Generate all subsets | Loop `1` to `(1<<n)-1` | Generates 2^n - 1 subsets |
| Enumerate submasks | `s = (s-1) & m` | Iterates through submasks |