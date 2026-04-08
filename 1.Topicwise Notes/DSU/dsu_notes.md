# DSU and Union Find

## Functionality

1. **Union(a, b)**: Union of two sets where a and b are elements of the set
2. **Find(a)**: Find the set to which a belongs
3. **Connected(a, b)**: Check if a and b belong to the same set

---

## Ideas

### 1. Graph Approach
Make graph of all the elements and then find the connected components etc.
- **Not best time complexity**

### 2. Maintain Set/Data Structure
- **Not best time complexity**

---

### Small to Large Trick

For Union → Always add small set to the large set.
- **Time Complexity**: O((logN)²)

#### Proof:
Let's say we have a set A of size 1. Now to merge it to a set B where size(B) ≥ 1, then resultant set will be of size 1 + size(B) which is at least double of size(A).

Hence every time size will double and hence logN times.

So total movements will be logN and each movement will take logN time. Hence (logN)².

---

## 3. Union Find

### Representation

Let A:{1, 3, 5} and B:{2, 6}

Representation of A and B will be:

Leader: L
```
    L                L
A: (1)<-3<-5     B: (2)<-6
```

### Union(5, 6):
```
    L
    (1)<-3<-5
     ^
     |
     2<-6
```

So, union is now O(1) → max(O(1), T(Find(a), Find(b))) → O(logN)

But Find(a) → still O(N), hence merging small to large will help in reducing the time complexity of find.

---

## Optimizations

### Union Optimizations

#### 1. Rank Compression
Rank is the height of the tree. So, merge the smaller tree to the larger tree, i.e., point the parent of smaller tree to the larger tree.
- **Time Complexity**: O(logN)

#### 2. Size Compression (Preferred)
Same as rank compression but instead of height we use size of the tree.

---

### Find Optimizations

#### 1. Path Compression
- **Time Complexity**: O(logN)

While finding the parent of a node, make the parent of the node as the parent of the parent of the node.

```
     O                         O
    / \                       /\ \
   o   o  => converted to     o o o
  / \                        /
 o   o<- find               o
```

---

## Combined Optimization

If we use **either** Path Compression **or** Size Compression:
- Find: O(logN)
- Union: O(logN)

But if we use **both** Path Compression **and** Size Compression:
- **Time Complexity**: Ackermann function O(log*N)

### Ackermann Function
log*N = {1 + log*(logN)} steps to reach 1

Example: log*(64000) ≈ 5 or 6

---

## Implementation

```cpp
class dsu {
public:
    vector<int> parent;
    vector<int> size;
    vector<int> rank;

    explicit dsu(int a)
    {
        parent.resize(a);
        size.resize(a);
        rank.resize(a);
        for (int i = 0; i < a; i++)
        {
            parent[i] = i;
            size[i] = 1;
            rank[i] = 0;
        }
    }

    int find(int i)
    {
        if (i == parent[i])
            return i;
        return parent[i] = find(parent[i]);
    }

    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
        {
            if (rank[a] > rank[b])
                swap(a, b);
            parent[a] = b;
            size[b] += size[a];
            size[a] = 0;
            if (rank[a] == rank[b])
                rank[b]++;
            return true;
        }
        return false;
    }
};
```