/* Enumerating all submasks of a given mask :

    Given a bitmask m,
    we want to efficiently iterate through all of its submasks,
    that is,
    masks s in which only bits that were included in mask m are set.
*/ 


/*code visits all submasks of m, without repetition, and in descending order*/

    for(int s = m;; s = (s - 1) & m)
    {
        /* ...you can use s... */
        if (s == 0) break;
    }

Iterating through all masks with their submasks. Complexity O(3^n)
In many problems, especially those that use bitmask dynamic programming, you want to iterate through all bitmasks and for each mask, iterate through all of its submasks:

for (int m=0; m<(1<<n); ++m)
    for (int s=m; s; s=(s-1)&m)
        /* ... s and m ... */
