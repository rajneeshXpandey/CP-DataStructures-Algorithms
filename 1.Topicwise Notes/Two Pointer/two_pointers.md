# Two Pointers Patterns

## 1. Running from Both Ends of an Array

The first type of problems are having two pointers at left and right end of array, then moving them to the center while processing something with them.

```
[← left pointer               right pointer →]
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
   ←                       →
      ←                 →
         ←           →
            ←     →
```

### Common Problem Types

#### 2 Sum Problem
Problems involving finding pairs of elements that satisfy certain conditions. Typically works best with sorted arrays.

**Pattern**: 
- Start with pointers at both ends
- Move pointers based on comparison with target
- If sum too small, move left pointer right
- If sum too large, move right pointer left

#### Trapping Water
Problems involving calculating areas or volumes formed between elements.

**Pattern**:
- Use two pointers from both ends
- Track the maximum height seen so far
- Calculate trapped water based on minimum of two heights

#### Next Permutation
Problems involving finding the next lexicographically greater arrangement.

**Pattern**:
- Scan from right to find the first decreasing element
- Find the smallest element larger than it from the right
- Swap and reverse the suffix

#### Reversing / Swapping
Problems involving reversing or rearranging elements in-place.

**Pattern**:
- Start pointers at both ends
- Swap elements and move pointers toward center
- Continue until pointers meet

#### Others
Various problems that benefit from the two-ends approach including token games, string matching, and distance calculations.

---

## 2. Slow & Fast Pointers

Next type is using two pointers with different speed of movement. Typically they start from the left end, then the fast pointer advances and gives some feedback to the slow pointer to do some calculation.

```
[slow →    fast →→]
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
 ↑     ↑
    ↑        ↑
       ↑           ↑
```

### Common Problem Types

#### Linked List Operations
Problems involving linked list manipulation and detection.

**Pattern**:
- Slow pointer moves one step at a time
- Fast pointer moves two steps at a time
- Used for finding middle, detecting cycles, removing nth node

#### Cyclic Detection
Problems involving detecting cycles in sequences.

**Pattern** (Floyd's Cycle Detection):
- Fast pointer moves twice as fast as slow pointer
- If there's a cycle, they will eventually meet
- Can find cycle start by resetting one pointer

#### Sliding Window / Caterpillar Method
Problems involving finding subarrays that satisfy certain conditions.

```
[← slow/left     fast/right →]
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
 ↑_____↑
    ↑_____↑
       ↑________↑
```

**Pattern**:
- Expand window by moving fast pointer
- Contract window by moving slow pointer when condition violated
- Track the best window found

#### Rotation
Problems involving rotating arrays or matrices.

**Pattern**:
- Use slow pointer to mark the rotation point
- Fast pointer helps in element placement
- Often combined with reversal technique

#### String
Problems involving string compression or manipulation.

**Pattern**:
- Slow pointer marks write position
- Fast pointer reads and processes characters
- Useful for in-place modifications

#### Remove Duplicate
Problems involving removing duplicate elements in-place.

**Pattern**:
- Slow pointer marks position of last unique element
- Fast pointer scans through array
- Copy unique elements to slow pointer position

#### Others
Various problems including partitioning, finding longest subarrays, and statistical calculations.

---

## 3. Running from Beginning of 2 Arrays / Merging 2 Arrays

In this category, you will be given 2 arrays or lists, then have to process them with individual pointers.

```
Array 1: [1, 3, 5, 7, 9]
          ↑
Array 2: [2, 4, 6, 8, 10]
          ↑
```

### Common Problem Types

#### Sorted Arrays
Problems involving merging or comparing sorted arrays.

**Pattern**:
- Start pointer at beginning of each array
- Compare elements and advance appropriate pointer
- Handle remaining elements from either array

#### Intersections / LCA (Lowest Common Ancestor) Like
Problems involving finding common elements or intersection points.

**Pattern**:
- Maintain pointer for each list/array
- Compare current elements
- Advance pointer(s) based on comparison result

#### SubString
Problems involving matching or comparing strings/subsequences.

**Pattern**:
- One pointer for main string, one for pattern
- Match characters and advance accordingly
- Handle mismatches based on problem requirements

#### Median Finder
Problems involving finding median in streaming data or merged arrays.

**Pattern**:
- Use two pointers to traverse sorted arrays
- Find middle element(s) by counting positions
- Can use with heap-based approach for streaming

#### Meet-in-the-Middle / Binary Search
Problems involving searching in combined space of two arrays.

**Pattern**:
- Generate possibilities from each array
- Use two pointers to find optimal combination
- Often combined with sorting and binary search

#### Others
Various problems including finding unsorted subarrays, assignment problems, and string merging.

---

## 4. Split & Merge of an Array / Divide & Conquer

The last one is similar to previous category but there is one thing added. First, you need to split the given list into 2 separate lists and then use two pointers approach to merge or unify them.

```
Original: [3, 1, 4, 1, 5, 9, 2, 6]
           ↓
Split:    [3, 1, 4, 1] [5, 9, 2, 6]
           ↓               ↓
Sort:     [1, 1, 3, 4] [2, 5, 6, 9]
           ↑               ↑
           └───── Merge ────┘
                   ↓
Result:   [1, 1, 2, 3, 4, 5, 6, 9]
```

### Common Problem Types

#### Partition
Problems involving partitioning lists based on certain criteria.

**Pattern**:
- Split list into two parts (e.g., less than pivot, greater than pivot)
- Maintain separate pointers for each partition
- Merge back based on requirements

#### Sorting
Problems involving merge sort or similar divide-and-conquer sorting.

**Pattern**:
- Recursively split array into halves
- Sort each half independently
- Use two pointers to merge sorted halves

---

## General Two Pointers Guidelines

### When to Use Two Pointers?

1. **Array/String problems** with linear structure
2. **Sorted arrays** - leveraging the sorted property
3. **Pair/Triplet finding** problems
4. **In-place operations** to save space
5. **Cycle detection** in linked structures
6. **Merging/Comparing** multiple sequences

### Complexity Analysis

- **Time Complexity**: Usually O(N) as each element is visited at most once or twice
- **Space Complexity**: Usually O(1) as only pointer variables are used

### Tips

1. **Identify the pattern**: Determine which type of two-pointer approach fits
2. **Edge cases**: Handle empty arrays, single elements, equal elements
3. **Pointer movement**: Clearly define when and how to move each pointer
4. **Termination condition**: Ensure pointers eventually meet the stopping criteria
5. **Sorted vs Unsorted**: Many techniques work better with sorted input