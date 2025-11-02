# Prefix Sum Techniques

## Resources

For more information: [USACO Guide - Prefix Sums](https://usaco.guide/silver/prefix-sums?lang=cpp)

---

## 1. Prefix Sum of Alternating Sum

For arrays where elements alternate between addition and subtraction:

```cpp
for (int i = 1; i <= n; ++i)
{
    /* current_value; */
    prex[i] = prex[i - 1];
    if (i % 2 == 0)
        prex[i] += current_value;
    else
        prex[i] -= current_value;
}
```

**Pattern**: 
- Odd indices (1, 3, 5, ...): subtract value
- Even indices (2, 4, 6, ...): add value

---

## 2. 2D Prefix Sum

### Declaration

```cpp
int prex2D[MAX_SIDE + 1][MAX_SIDE + 1];
int arr[MAX_SIDE + 1][MAX_SIDE + 1];
```

### Building the 2D Prefix Sum Array

```cpp
for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
        prex2D[i][j] = arr[i][j] + prex2D[i - 1][j] +
                       prex2D[i][j - 1] - prex2D[i - 1][j - 1];
    }
}
```

**Formula**:
```
prex2D[i][j] = arr[i][j] + prex2D[i-1][j] + prex2D[i][j-1] - prex2D[i-1][j-1]
```

**Visualization**:
```
prex2D[i-1][j-1]   prex2D[i-1][j]
        +---------------+
        |               |
        |               |
        +---------------+
prex2D[i][j-1]     prex2D[i][j]
```

We subtract `prex2D[i-1][j-1]` because it's counted twice (once in `prex2D[i-1][j]` and once in `prex2D[i][j-1]`).

---

### Querying Rectangle Sum

```cpp
for (int q = 0; q < Q; q++) {
    int from_row, to_row, from_col, to_col;
    cin >> from_row >> from_col >> to_row >> to_col;
    
    cout << prex2D[to_row][to_col] 
         - prex2D[from_row - 1][to_col] 
         - prex2D[to_row][from_col - 1] 
         + prex2D[from_row - 1][from_col - 1]
         << '\n';
}
```

**Formula**:
```
sum = prex2D[to_row][to_col] 
    - prex2D[from_row-1][to_col] 
    - prex2D[to_row][from_col-1] 
    + prex2D[from_row-1][from_col-1]
```

**Visualization**:
```
                from_col          to_col
                    |                |
        +-----------+----------------+
        |     A     |       B        |
from_row+-----------+----------------+
        |     C     |   QUERY AREA   |
        |           |   (what we     |
to_row  +-----------+    want)       |
        |           |                |
        +-----------+----------------+
```

**Logic**:
- Start with: `prex2D[to_row][to_col]` (entire rectangle from (0,0) to (to_row, to_col))
- Subtract: `prex2D[from_row-1][to_col]` (remove area A + B)
- Subtract: `prex2D[to_row][from_col-1]` (remove area A + C)
- Add back: `prex2D[from_row-1][from_col-1]` (area A was subtracted twice, so add it back once)

---

## Complexity Analysis

### 1D Prefix Sum
- **Build**: O(N)
- **Query**: O(1)

### 2D Prefix Sum
- **Build**: O(N × M)
- **Query**: O(1)

---

## Common Use Cases

1. **Range sum queries**: Get sum of any subarray/rectangle in O(1)
2. **Counting**: Count elements satisfying a condition in a range
3. **Difference arrays**: For range update operations
4. **2D problems**: Matrix sum queries, image processing, grid problems
5. **Alternating sums**: Handling sequences with alternating signs