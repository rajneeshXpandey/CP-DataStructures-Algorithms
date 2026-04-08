# Rerooting DP

## Core Idea

Rerooting DP computes a subtree-based answer for **every node as root** in O(n), instead of re-running DFS n times (which would be O(n²)).

Two-pass strategy:

1. **Pass 1 (bottom-up)** — root the tree arbitrarily. Compute subtree info (size, sum, etc.) for every node.
2. **Pass 2 (top-down)** — propagate the root's answer down. Re-derive each child's answer from its parent's answer using the precomputed subtree info.

The key insight: when you move the root from a parent `p` to a child `c`, nodes inside the subtree of `c` get **1 closer** (−`subtree[c]` contribution) and nodes outside get **1 farther** (+`n − subtree[c]` contribution).

---

## Problem — Sum of Distances in Tree

Given a tree of `n` nodes, for every node compute the sum of distances to all other nodes.

**Example:**

```
Tree:      1
          / \
         2   3
            / \
           4   5

Distances from node 1: 1+1+2+2 = 6
Distances from node 3: 2+1+1+1 = 5
```

Output: `6 9 5 8 8`

---

## Pass 1 — `dfs`: Compute `subtree[v]` and `ans[root]`

For each node `v`, compute:

- `subtree[v]` = size of subtree rooted at `v`
- Return the **weighted sum** of depths within the subtree (used to compute `ans[0]`)

The `sum` variable tracks the current depth; as we enter a node `sum++`, as we leave `sum--`. Each node contributes its depth to the sum via `subsum += vals.second` (recursive accumulation).

```cpp
pair<int,int> dfs(vector<vector<int>>& adj, vector<int>& visi,
                  vector<int>& subtree, int root, int& sum) {
    int sz = 0;
    int subsum = sum;   // contribution of this node = current depth
    sum++;
    visi[root] = 1;
    for (auto child : adj[root]) {
        if (!visi[child]) {
            auto vals = dfs(adj, visi, subtree, child, sum);
            sz      += vals.first;   // accumulate subtree size
            subsum  += vals.second;  // accumulate weighted depth sum
        }
    }
    sum--;
    subtree[root] = 1 + sz;
    return {subtree[root], subsum};
}
```

After this pass, `ans[0] = rootans.second` holds the correct answer for node 0.

---

## Pass 2 — `SumDist`: Reroot top-down

When moving the root from `par` → `child`:

- `subtree[child]` nodes are 1 step closer → subtract `subtree[child]`
- `n − subtree[child]` nodes are 1 step farther → add `n − subtree[child]`

```
ans[child] = ans[par] - subtree[child] + (n - subtree[child])
```

```cpp
void SumDist(vector<vector<int>>& adj, vector<int>& visi, vector<int>& subtree,
             vector<int>& ans, int n, int root, int par) {
    if (root != 0)   // root=0 already has its answer from pass 1
        ans[root] = ans[par] - subtree[root] + (n - subtree[root]);
    visi[root] = 1;
    for (auto child : adj[root]) {
        if (!visi[child])
            SumDist(adj, visi, subtree, ans, n, child, root);
    }
}
```

---

## Driver

```cpp
vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    vector<int> ans(n,0), subtree(n,0), visi(n,0);
    vector<vector<int>> adj(n);
    for (auto& e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    int sum = 0;
    auto rootans = dfs(adj, visi, subtree, 0, sum);
    ans[0] = rootans.second;

    fill(visi.begin(), visi.end(), 0);
    SumDist(adj, visi, subtree, ans, n, 0, -1);
    return ans;
}
```

---

## Complexity

| | Time | Space |
|---|---|---|
| Pass 1 | O(n) | O(n) |
| Pass 2 | O(n) | O(n) |
| **Total** | **O(n)** | **O(n)** |

---

## Template — General Rerooting

```
1. Root at node 0, run bottom-up DFS → compute f(v) for subtree of v
2. ans[0] = aggregate result at root
3. Top-down DFS: ans[child] = g(ans[parent], subtree[child], n)
   where g encodes how the answer shifts when you "pull" child up to root
```

Common `g` formulas:

| Problem | Shift formula |
|---|---|
| Sum of distances | `ans[p] - sz[c] + (n - sz[c])` |
| Max depth | `max(ans[p]+1, depth_within_subtree[c])` |
| Weighted distance | similar, with edge weights |

---

## When to Use

- Any tree DP where the value at a node depends on **both its subtree and the rest of the tree**.
- The naive approach is O(n²) (re-root and re-run DFS for each node).
- Rerooting converts it to O(n) by reusing previously computed subtree info.
