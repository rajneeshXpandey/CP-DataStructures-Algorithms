# Sliding Window Templates

## Template 1: Sliding Window (Shrinkable)

This template keeps the window valid at the end of each outer loop iteration.

### Template Structure

```cpp
int i = 0, j = 0, ans = 0;
for (; j < N; ++j) {
    // CODE: use A[j] to update state which might make the window invalid
    for (; invalid(); ++i) { // when invalid, keep shrinking the left edge until it's valid again
        // CODE: update state using A[i]
    }
    ans = max(ans, j - i + 1); // the window [i, j] is the maximum window we've found thus far
}
return ans;
```

**Key Points**:
- We want to keep the window valid at the end of each outer `for` loop
- When window becomes invalid, shrink from the left until it's valid again
- Track the maximum valid window size

---

### Example Problem: Frequency of the Most Frequent Element

**Problem**: [LeetCode - Frequency of the Most Frequent Element](https://leetcode.com/problems/frequency-of-the-most-frequent-element/)

#### Solution Approach

1. **What should we use as the `state`?**  
   The sum of numbers in the window

2. **How to determine `invalid`?**  
   The window is invalid if `(j - i + 1) * A[j] - sum > k`

#### Implementation

```cpp
// OJ: https://leetcode.com/problems/frequency-of-the-most-frequent-element/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int maxFrequency(vector<int>& A, int k) {
        sort(begin(A), end(A));
        long i = 0, N = A.size(), ans = 1, sum = 0;
        for (int j = 0; j < N; ++j) {
            sum += A[j];
            while ((j - i + 1) * A[j] - sum > k) sum -= A[i++];
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
```

---

### FAQ for Template 1

#### Q: Why is the time complexity `O(NlogN)`?

**A**: The sorting takes `O(NlogN)`. The two pointer part only takes `O(N)` because both the pointers `i` and `j` traverse the array ONLY ONCE.

#### Q: Why is `(j - i + 1) * A[j] - sum <= k` valid?

**A**: 
- `(j - i + 1)` is the length of the window `[i, j]`
- We want to increase all the numbers in the window to equal `A[j]`
- The number of operations needed is `(j - i + 1) * A[j] - sum`, which should be `<= k`

**Example**: Assume the window is `[1, 2, 3]`
- Increasing all numbers to `3` will take `3 * 3 - (1 + 2 + 3) = 9 - 6 = 3` operations

---

## Template 2: Sliding Window (Non-shrinkable)

This template grows the window when valid and shifts when invalid.

### Template Structure

```cpp
int i = 0, j = 0;
for (; j < N; ++j) {
    // CODE: use A[j] to update state which might make the window invalid
    if (invalid()) { // Increment the left edge ONLY when the window is invalid
        // In this way, the window GROWS when it's valid, and SHIFTS when it's invalid
        // CODE: update state using A[i]
        ++i;
    }
    // after `++j` in the for loop, this window [i, j) of length `j - i` MIGHT be valid
}
return j - i; // There must be a maximum window of size `j - i`
```

**Key Points**:
- We GROW the window when it's valid
- We SHIFT the window when it's invalid
- Only a SINGLE `for` loop needed!
- Window size is monotonically non-decreasing

---

### Example Problem: Frequency of the Most Frequent Element

Same problem as Template 1, but with non-shrinkable approach.

#### Implementation

```cpp
// OJ: https://leetcode.com/problems/frequency-of-the-most-frequent-element/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int maxFrequency(vector<int>& A, int k) {
        sort(begin(A), end(A));
        long i = 0, j = 0, N = A.size(), sum = 0;
        for (; j < N; ++j) {
            sum += A[j];
            if ((j - i + 1) * A[j] - sum > k) sum -= A[i++];
        }
        return j - i;
    }
};
```

---

## Comparison: Shrinkable vs Non-shrinkable

| Aspect | Shrinkable | Non-shrinkable |
|--------|------------|----------------|
| **Window behavior** | Shrinks to smallest valid | Grows or shifts |
| **Loop structure** | Nested loops (while inside for) | Single for loop |
| **Window size** | Can decrease | Monotonically non-decreasing |
| **Result tracking** | Track max during iteration | Return final window size |
| **Use when** | Need to find ALL valid windows | Only need MAXIMUM valid window |

---

## When to Use Each Template?

### Use Template 1 (Shrinkable) when:
- You need to track the maximum/minimum valid window
- You want to process all valid windows
- The problem asks for the "largest/smallest subarray that satisfies..."

### Use Template 2 (Non-shrinkable) when:
- You only care about the maximum window size at the end
- You want simpler code with single loop
- The window size should never decrease

---

## General Sliding Window Pattern

1. **Initialize**: Set up pointers `i` (left) and `j` (right), and state variables
2. **Expand**: Move `j` to the right and update state
3. **Contract** (if needed): Move `i` to the right when window becomes invalid
4. **Update answer**: Track the result based on current window
5. **Repeat**: Continue until `j` reaches the end

**Time Complexity**: Usually O(N) for the sliding window part (each element visited at most twice)

**Space Complexity**: Usually O(1) or O(k) where k is the size of auxiliary data structures