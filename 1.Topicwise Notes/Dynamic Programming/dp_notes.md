# Dynamic Programming

## Day 1

### 1) Array Size Limits
- Inside array max size => 2*10^6
- On global scope max size => 10^8

### 2) State Compression (Hashing Trick)

Let's say we have `dp[1000][100][10]` for c, b, a respectively

```cpp
int getValue(int a, int b, int c) {
    return x = (a*10^5 + b*10^3 + c);
    /* its like: (-)(--)(---) */
}

// To retrieve the value:
c = x%1000;
b = (x/1000)%100;
a = (x/100000);
```

So, `dp[1000][100][10]` => `dp[100000]`

### 3) When to Decide DP and Greedy?
- Always try DP first and then try greedy

### 4) Base Cases for DP

|        | Valid Base | Invalid State |
|--------|------------|---------------|
| min    | 0          | +inf          |
| max    | 0          | -inf          |
| count  | 1          | 0             |

---

## Day 2

### DP Framework

**Look for the form of the problem:**

#### Form 1: (subset, subsequences, like take/drop etc to build incremental solutions)

- **a) Level**: define and have answer to the problem
- **b) Choices**: possible choices at each level
- **c) Check**: check if the transition is valid or not
- **d) Moves**: go to next valid levels

`DP(level, taken/remaining) = answer to that level`

**Steps:**
1. Decide the states and meaning: `DP(__) = ___`
2. DP transitions
3. Check the time complexity (don't code until you have the time complexity)
   - Formula: `O(#States * (1 + Avg.Transitions cost))`
   - Or: `O(#States * (1 + Avg. #Transitions per state))`
4. Code!!
   - Pruning
   - Base Case
   - Cache check
   - Transitions
   - Save and return

### Query and Printing Solution in DP

#### Query
We need to cache things across queries, so instead of `DP(level, taken)` => `DP(level, remaining)`

**Proof**: In code of `DP(level, sum_taken)` depends on target sum T, but if we write code for `DP(level, remaining)` then it will be independent of T. Hence we don't need to clear our cache for every query.

Time complexity will be `O(#States * (1 + Avg. #Transitions per state) + Q)` instead of `O(#States * (1 + Avg. #Transitions per state) * Q)`

#### Printing Solution in DP
- Recheck
- Saving backpointers:
  - Check by making dp call
  - If not take gives true then don't take and move in the same
  - Else take (true) print the item and move to next level in the same

---

## Day 3

### Form 2: Path, Sequence, Subarray Dependencies

**If we see path, sequence, subarray dependencies**

**Stores the Best possible answer ending at this level**

#### Example: Longest Increasing Subsequence (LIS)

**Solving with Form 1:**

- State: `DP(level, last_element_taken)` = max length of subsequence ending at level
- Transitions: 
  ```
  DP(level, last_element_taken) = 
      max(DP(level+1, last_element_taken), 
          DP(level+1, arr[level])+1)  // if arr[level] > last_element_taken
  ```
- Time complexity: `O(N*max(arr))` → can't be feasible for large arr[i]
- So, just try to store index instead of element: time complexity `O(N*N)`

**Solving with Form 2:**

State: `DP(level)` = Best answer ending at level

```
_2_ _5_ _3_ _6_ _1_ _4_
< --------- >|-> level 
  prev_taken
```

Traverse from level-1 to 0 and take maximum of all the possible prev_taken

- State: `DP(level)` = max length of subsequence ending at level
- Transitions: 
  ```
  DP(level) = max(DP(level), DP(prev_taken)+1)  // if arr[level] > arr[prev_taken]
  prev_taken = 0 to level-1
  ```
- Time complexity: `O(N * N) = O(N^2)`

#### Example: Grid Path Sum

In N*M Grid find the max Path sum from (0,0) to (N-1,M-1) if →(side) and ↓(down) are allowed.

- State: `DP(row, col)` = max path sum ending at (row, col)
- Transitions: `DP(row, col) = max(DP(row-1, col), DP(row, col-1)) + arr[row][col]`
- Time complexity: `O(N*M)`

Can keep `done[][]` array to check whether its value is saved or not.

---

### Form 3: Multisequence DP

Given multiple sequences and we have to match them

```
seq1/arr1 [_ _ _ _ _] size = N  |-> ith

seq2/arr2 [_ _ _ _ _] size = M  |-> jth
```

`DP(i, j, ___)` = best answer when i - N and j - M are remaining or 0-i, 0-j explored

#### Example: Longest Common Subsequence (LCS)

- State: `DP(i, j)` = LCS from seq1[i, N-1] and seq2[j, M-1]
- Transitions:
  ```
  DP(i, j) = max(DP(i+1, j), DP(i, j+1))
  if(seq1[i] == seq2[j]) then DP(i, j) = max(DP(i, j), DP(i+1, j+1)+1)
  ```
  ```
  ith -> _ _ x _ _ _
  jth -> _ _ y _ _ _
  ```
- Time complexity: `O(N*M)`

**For multiple sequences:**

- State: `DP(i, j, k)` = LCS from seq1[i, N-1] and seq2[j, M-1] and seq3[k, L-1]
- Transitions:
  ```
  DP(i, j, k) = max(DP(i+1, j, k), DP(i, j+1, k), DP(i, j, k+1))
  if(seq1[i] == seq2[j] && seq2[j] == seq3[k]) 
      then DP(i, j, k) = max(DP(i, j, k), DP(i+1, j+1, k+1)+1)
  ```
- Time complexity: `O(N*M*L)`

---

### Form 4: L-R DP / Interval DP

**Mostly: how we can perform given operation on the first and the last element of the subarray in [L-R]**

#### Example: Rod Cutting Problem

```
      l           r
|-----|--|--------|---------| 
```

We have to cut rod in pieces such that we get min cost.
Cost: length of current rod.

```
      4     2     => cost = 6 and we have |------| and |----| left
|------|---| 
```

- State: `DP(l, r)` = min cost to cut rod from l to r
- Transitions: 
  ```
  DP(l, r) = min(DP(l, r), DP(l, i) + DP(i+1, r) + (r-l))
  for all i in [l+1, r-1]
  ```
- Time complexity: `O((N*N) * N) = O(N^3)`

**L-R DP ideation:** How we can perform given operation on the first and the last element of the subarray in [L-R].

**Can we do it in less than O(N^3) time complexity?**

---

### Form 5: Game DP (Combinatorially Impartial Game)

#### Example: Subtraction Game

[x chips] → player can remove y (2^m, m:{0,inf}) chips from x chips, and x-y will remain

Now if player can't take any chips then he will lose.

- State: `DP(x)` = true if player can win else false
- Transitions: 
  ```
  DP(x): DP(x-y), y = 2^m, m:{0, log2X} and x-y >= 0
  if any one of the transition is losing then DP(x) = win
  else if all are winning then DP(x) = lose
  ```
- Time complexity: `O(N*logN)`

**Observation:** After printing the patterns:
- if x%3 then `DP(x)` = win
- else `DP(x)` = lose

**Note:** When states are -ve nums then add the offset to make them positive and in the desired range.
`dp(idx, vals)` => idx ∈ [0, N-1] and vals ∈ [-x, +x] then add offset x to it

---

## Day 4

### Prefix Match, Building Automata, Using Mask

### LIS in O(NLogN)

**Improvements in LIS:**

1. **Incremental processing:**
   - Add / not add current element in the prev sequence
   ```
   1    2       5                   6 4 7 8 9
   {1} {2}     {5}
       {1,2}  {2,5}, {1,2,5} etc.
   ```

2. **Comparing partial solutions:**
   - (length, last_element) → if(length is same) compare last_element and take lesser one, else take greater length one

3. **Storing and maintaining partial solutions:**
   ```
   eg 1 5 6 9 4 2 3 5 8
   arr: [1, 5, 6, 9] → [1, 4, 6, 9] → [1, 2, 6, 9] → [1, 2, 3, 5] → [1, 2, 3, 5, 8]
   arr[i] → best last element of LIS ending at ith pos in LIS
   ```

4. **Printing Solution:**
   ```
   [1, 5, 7, 10, 9, 6, 8, 9, 2, 3]
   |->1, 5, 7, 10
        |->6, 8, 9
     |->2, 3
   ```
   See from left to bottom to right
   So, 1 2 3 8 9: LIS

#### Code for Getting LIS in O(NLogN)

```cpp
vector<int> lis;
for(int i=0; i<n; i++) {
    if(lis.empty() || lis.back() < arr[i]) {
        lis.push_back(arr[i]);
        inserted_at[i] = lis.size();
    } else {
        int idx = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin(); 
        lis[idx] = arr[i]; // replace the element with current element
        inserted_at[i] = idx+1;
    } 
} 
cout << lis.size() << endl;
```

#### Printing LIS

For above example: `inserted_at[] = {1_, 2_, 3, 4, 4, 3_, 4_, 5_, 2, 3}`

This is the size of current lis when the ith element is inserted.

`_`: these len of lis while insertion are important because they build the lis finally.

```cpp
int curlen = lis.size();
vector<int> final_lis;
for(int i=n-1; i>=0; i--) {
    if(inserted_at[i] == curlen) {
        final_lis.push_back(arr[i]);
        curlen--;
    }
} 
reverse(final_lis.begin(), final_lis.end());
for(auto &x: final_lis) { 
    cout << x << " ";
}
```

---

### Find the Number of Binary Strings

Find the number of Binary Strings of length N that doesn't contain "0100" as (N <= 10^5)

#### 1) Subsequence

```
          0 1 2 3 4 : idx
we have   0 1 0 0 
[_ _ _ _ _ _ _ _ _ _]
```

- State: `DP(level, index_of_given_str=x)` = number of valid binary strings of length if we fill i to n-1
- Transitions:
  ```
  DP(level, x) = 
      if(x == 4) DP(level+1, x); 
      else if(t[x] == s[level])
          DP(level+1, x+1)
      else
          DP(level+1, x)
  ```
- Time complexity: `O(N)`
- Pruning: if(x == 4) return 0;
- Base case: if(level == N) return 1;

So for all same length string t answer would be same, in fact it comes out to be a formula.

#### 2) Substring

Mask of 3 bits: prev 3 bits info

- State: `DP(level, mask)` = number of valid binary strings of length if we fill i to n-1
- Transitions:
  ```
  DP(level, mask) 
      if mask=(level>=3 and 010) → DP(level+1, 101); we can only place 1
      else if mask=(001) → DP(level+1, 010) + DP(level+1, 011)
  ```
- Time complexity: `O(N)`
- Base case: if(level == N) return 1;

#### Another Method: Creating Finite State Automata

```
string: 0 1 0 0   () -> accepted state 

_1_      _0_                        _0/1__
| |  0   | |   1       0         0   | |
start: ([0])--->([1])--->([2])--->([3]) ---> [4]
         |<_________________|<______|   
                0               1 
```

```cpp
int ans = 0; 
if(match == 0)      ans = dp(level+1, 0) + dp(level+1, 1);
else if(match == 1) ans = dp(level+1, 1) + dp(level+1, 2);
else if(match == 2) ans = dp(level+1, 3) + dp(level+1, 0);
else if(match == 3) ans = dp(level+1, 4) + dp(level+1, 2);
/* save and return */ 
return dp[level][match] = ans;
```

---

## Day 5

### Iterative DP

- Helps in space optimization
- Order of execution is important

#### Problem: Two Piles of Stones

```
   ____   
   |  |
   |  |   ____
   |  |   |  |
   |  |   |  |
  ------  ---- 
# of piles a    b
```

**Rules:**
1. Player can pick any number of stones from any one pile
2. Player can pick equal number of stones from both piles
3. Player who picks last stone wins

**Solution:**

- State: `DP(x, y)` → if player playing the move wins or not if there are x stones in pile 1 and y stones in pile 2
- Transition:
  ```
  DP(x, y) => DP(x-k, y)   k=1...x
           => DP(x, y-k)   k=1...y
           => DP(x-k, y-k) k=1...min(x,y)
  ```

**Logic:** Let's say current state. Now, if any of the transition results in losing state then current state will be winning, i.e., we can push opponent in the losing state.

- Time complexity: `O(A*B*(A+B))`

**Order of Computations:**

We have the answers in the DP matrix of size A*B:
```
[ # - - - # - ] ---------> first 1st   
[ - # - - # - ] ---------> then 2nd
[ - - # - # - ] ---------> then 3rd
[ # # # # * - ] ---------> then 4th
[ - - - - - - ] ---------> then 5th  
```

To calculate (*) → we need to calculate (#) first so the best way to iterate because values depend on x-k / y-k

---

#### Problem: Coin Change

Given coin denominations and amount, find if it's possible to make the amount using given coins.

- State: `DP(level, sum_left)` → if we can make amount sum_left using given coins [level-N]
- Transition:
  ```
  DP(level, sum_left) => DP(level+1, sum_left) // not using current coin
                      => DP(level, sum_left-coin[level]) // using current coin
  ```
- Time complexity: `O(N*SUM_MAX)`

**Order of Computations:**

```
[ - - - - - - ] ---------> then 5th   
[ - - - - - - ] ---------> then 4th
[ - - # - * - ] ---------> then 3rd
[ - - - - # - ] ---------> then 2nd
[ - - - - - - ] ---------> first 1st  
```

To calculate (*) → we need to calculate (#) first because the states depend on level+1 and (sum-x) vals.

**Note:** If base case has to be saved in memory then they should be assigned space.

```cpp
int dp[n+1][m+1]; 
for(int l=n; l>=0; l--) {
    for(int s=0; s<=m; s++) { 
        // compute for (l,s) 
        if(l == n) { 
            if(s == 0)
                dp[l][s] = 1; 
            else 
                dp[l][s] = 0;
        }
        // general 
        dp[l][s] = 0; 
        if(dp[l+1][s]) { 
            dp[l][s] = 1;
        } 
        if(s >= coin[l] && dp[l][s-coin[l]]) {
            dp[l][s] = 1;
        }
    }
}
```

---

#### Iterative Code for L-R DP

```
[ \ - - - - ]   
[ - \ - - - ]  
[ - - \ - - ] 
[ - - - \ - ] 
[ - - - - \ ]  
```

Iterate diagonally with increment of len = 1, 2, 3..... and if l = len then r = len-l+1

---

#### Polygon Triangulation

Given a convex polygon with n vertices, find the minimum cost to triangulate it.
Cost of triangulation is sum(length of diagonal added).

```
     x : vertex
        3(x)    4
        *-------*
       /| \      \
      / |  \      \
   2 *  |   \      * 5
      \ |    \    /
       \|     \  /
    !   *-------*   !  -> base of triangle
        1       6
```

Take 1-6 as a base of triangle and calculate the cost of triangulation of polygon formed by removing 1-x and x-6

- State: `DP(l, r)` → min cost of triangulation of polygon formed by polygon points[l-r]
- Transition: 
  ```
  DP(l, r) => DP(l, x) + DP(x, r) + cost(1, x) + cost(x, 6) 
  x => [l+1, r-1]  /* x is the vertex which is added to form a triangle */
  ```
- Time complexity: `O(N^3)`, N = number of vertices

**Order of Computations:** In L-R DP problems we need to solve the small length problems first (for 1 len, 2 len like this)

```cpp
vector<vector<ll>> dp;
vector<ll> a;

ll rec(int i, int j) {
    if (abs(j - i) == 1)
        return 0;
    auto &ans = dp[i][j];
    if (ans != -1)
        return ans;
    ans = 1e18;
    for (int k = i + 1; k <= j - 1; k++)
        ans = min(ans, a[i] * a[k] * a[j] + rec(i, k) + rec(k, j));
    return ans;
}

ll minTriangulation(vector<ll> &v) {
    n = v.size();
    a = v;
    dp.assign(n + 1, vector<ll>(n + 1, -1));
    return rec(0, n - 1);
}
```

---

#### Maximum Sum Subarray (Kadane's Algorithm)

Form 2:

```
         i-1 i
            |  |
            |  |      
          * | *|
arr [__  __  __  __  __  __  __]
```

- State: `DP(i)` → max sum of subarray ending at i
- Transition: `DP(i) => max(DP(i-1) + arr[i], arr[i])`

`dp[i-1]` => max sum of subarray ending at i-1, so if we add a[i] to it whether it will increase the sum or not.

At last we need to find the max of all the DP(i) values.

- Time complexity: `O(N)`

**Just replace DP[i-1] as the last_best then the code will be KADANE's algorithm**

---

## Day 6

### Optimizing DP Solutions

#### 1) State Space Optimization
If state has x, y, z parameters and z = f(x, y), then we can replace z with f(x, y) and save space.

#### 2) State Rotation
What we were returning will be put in state and what we were storing will be returned.

#### 3) Transition Optimization

#### 4) Space Optimization

#### 5) Advanced Optimizations:
- **Knuth optimization**: LR DP → Optimization of rod cutting problem from N^3 → N^2
- **Divide and Conquer Optimization**
- **Convex Hull Optimization** (**) → can be learned
- **Alien Trick**
- **Monotonicity Based Optimization** (**) → can be learned
- **1D 1D DP Optimization**
- **Sorting based optimization** (**) → can be learned

---

### 1) State Space Optimization

**Problem:** Given set of nums, divide them into two sets such that sumA % sumB = 0

`DP(level, sumA, sumB)` → `DP(level, sumA)` where sumB = prefixSum[level] - sumA

---

### 2) State Rotation

**AtCoder DP Contest Problem E** (details not provided in original)

---

### 3) Monotonicity Based Optimization

#### Problem

There are n cities and roads between them.

```
|____|_____|_____|_____|_____|_____|_____|_____|_____|_____|
B1   B2    B3    B4   B5    B6    B7    B8    B9   B10   B11
```

- Bi → cost of bus from city i to i+1
- There is flight service from city i to i+j with cost Fi + Fj, j → [1, k]

Find the min cost to travel from city 1 to city n

**Solution:**

- State: `Dp(level)` → min cost to travel from city 1 to city level
- Transition:
  ```
  Dp(level) => min{ 
      Dp(level-j) + Fi + Fj, j → [1, k],
      Dp(level-1) + Bi 
  }
  ```
- Time complexity: `O(N*K)`

**Optimize the transition:**

In `Dp(level-j) + Fi + F[level-j]`, j → [1, k], if we get min in O(1) approx then we can optimize the time complexity.

We only need array of `DP[k] + Fk` for k-len segment. We can use:
- Multiset to maintain the K-len segment and find min in O(1)
- OR Monotonic Queue: https://1e9.medium.com/monotonic-queue-notes-980a019d5793

```cpp
struct monotone_deque { 
    deque<int> dq;
    
    void insert(int x) {
        while(!dq.empty() && dq.back() > x)
            dq.pop_back();
        dq.push_back(x);
    }    

    void remove(int x) {
        if(!dq.empty()) { 
            if(dq.front() == x) 
                dq.pop_back(); 
        }
    }    

    int getmin() {
        if(!dq.empty()) { 
            return dq.front(); 
        }
        else return 0;
    }
}

// Using the monotone_deque        
dp[1] = 0;
monotone_deque dq;

for (int level=2; level<=n; level++) { 
    dp[level] = dp[level-1] + b[level-1];

    // maintaining dq
    dq.insert(dp[level-1] + a[level-1]); 
    if(level-k-1 >= 1) 
        dq.remove(dp[level-k-1] + a[level-k-1]);

    dp[level] = min(dp[level], dq.getmin() + a[level]);
}
cout << dp[n] << endl;
```

---

#### New Restriction: Number of Flights Taken = M

**Naive: O(N*K*M)**

DP:
- State: `dp[i][f]` → min cost to reach ith city from 1st city using f flights
- Transition:
  ```
  dp[i][f] = min(dp[i−1][f] + A[i−1], Z)
  where Z = min(dp[i−j][f−1] + B[i] + B[i−j])
  over all 1 ≤ i−k ≤ j < i
  ```
  O(k) in transition, O(N*k*M) overall complexity.

**Transition Optimizations:** (Only applicable to Bottom-up approach)
- O(logK) time transition and O(N*M*logK) overall using multiset to store min(dp[i−j][f−1] + B[i−j]) of previous k size window
- O(1) time transition, O(N*M) overall time and O(N*M) space using min deque to store min(dp[i−j][f−1] + B[i−j]) of previous k size window

**Further Memory Optimizations:** (O(N) Space Reduction)

Transitions of the current state only depend on the last state of flight count, so store only 2 rows of memory.

**Note:** Expected Complexity per test case for this problem:
- Time: O(N*M)
- Space: O(N)

```cpp
// j&1 is using the two rows (0, 1) interchangeably
for(int j=0; j<=m; j++) {
    cleardq();
    dp[0][j&1] = 0;
    for(int i=1; i<n; i++) {
        if(j == 0) {
            dp[i][j&1] = dp[i-1][j&1] + arr[i-1];
        } else {
            dp[i][j&1] = dp[i-1][j&1] + arr[i-1];
            dq.insert(dp[i-1][(j-1)&1] + brr[i-1]);
            if(i-k-1 >= 0)   
                dq.remove(dp[i-k-1][(j-1)&1] + brr[i-k-1]);
            dp[i][j&1] = min(dq.getMin() + brr[i], dp[i][j&1]);
        }
    }
}
cout << dp[n-1][m&1] << endl;
```