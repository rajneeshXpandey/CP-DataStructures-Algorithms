#include <bits/stdc++.h>

/**
    pbds oset;

    comparator :
        -> less<int> increasing order 
        -> greater<int> decending order
        -> ** less_equal<int> => act as multiset

    function : O(logN)
        -> find_by_order (*oset.find_by_order(k)) => finding kth element
        -> order_of_key (oset.order_of_key(x))  => finding number of elements smaller than X
        -> lower_bound (*oset.lower_bound(x)) :  Lower Bound of X = first element >= X in the set 
        -> upper_bound (*oset.upper_bound(x)) : Upper Bound of X = first element > X in the set
        -> Remove elements :  oset.erase(x);
**/

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// find_by_order, order_of_key
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

typedef tree<int, null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;


void Insert(ordered_set &s, int x)
{ //this function inserts one more occurrence of (x) into the set.

    s.insert(x);
}

bool Exist(ordered_set &s, int x)
{ //this function checks weather the value (x) exists in the set or not.

    if ((s.upper_bound(x)) == s.end())
    {
        return 0;
    }
    return ((*s.upper_bound(x)) == x);
}

void Erase(ordered_set &s, int x)
{ //this function erases one occurrence of the value (x).

    if (Exist(s, x))
    {
        s.erase(s.upper_bound(x));
    }
}

int FirstIdx(ordered_set &s, int x)
{ //this function returns the first index of the value (x)..(0 indexing).

    if (!Exist(s, x))
    {
        return -1;
    }
    return (s.order_of_key(x));
}

int Value(ordered_set &s, int idx)
{ //this function returns the value at the index (idx)..(0 indexing).

    return (*s.find_by_order(idx));
}

int LastIdx(ordered_set &s, int x)
{ //this function returns the last index of the value (x)..(0 indexing).

    if (!Exist(s, x))
    {
        return -1;
    }
    if (Value(s, (int)s.size() - 1) == x)
    {
        return (int)(s.size()) - 1;
    }
    return FirstIdx(s, *s.lower_bound(x)) - 1;
}

int Count(ordered_set &s, int x)
{ //this function returns the number of occurrences of the value (x).

    if (!Exist(s, x))
    {
        return 0;
    }
    return LastIdx(s, x) - FirstIdx(s, x) + 1;
}

void Clear(ordered_set &s)
{ //this function clears all the elements from the set.

    s.clear();
}

int Size(ordered_set &s)
{ //this function returns the size of the set.

    return (int)(s.size());
}

int main()
{
    pbds A; // declaration

    // Inserting elements - 1st query
    A.insert(1);
    A.insert(10);
    A.insert(2);
    A.insert(7);
    A.insert(2); // ordered set only contains unique values

    // A contains
    cout << "A = ";
    for (auto i : A)
        cout << i << " ";
    cout << endl;
    cout << endl;

    // finding kth element - 4th query
    cout << "0th element: " << *A.find_by_order(0) << endl;
    cout << "1st element: " << *A.find_by_order(1) << endl;
    cout << "2nd element: " << *A.find_by_order(2) << endl;
    cout << "3rd element: " << *A.find_by_order(3) << endl;
    cout << endl;

    // finding number of elements smaller than X - 3rd query
    cout << "No. of elems smaller than 6: " << A.order_of_key(6) << endl;   // 2
    cout << "No. of elems smaller than 11: " << A.order_of_key(11) << endl; // 4
    cout << "No. of elems smaller than 1: " << A.order_of_key(1) << endl;   // 0
    cout << endl;

    // lower bound -> Lower Bound of X = first element >= X in the set
    cout << "Lower Bound of 6: " << *A.lower_bound(6) << endl;
    cout << "Lower Bound of 2: " << *A.lower_bound(2) << endl;
    cout << endl;

    // Upper bound -> Upper Bound of X = first element > X in the set
    cout << "Upper Bound of 6: " << *A.upper_bound(6) << endl;
    cout << "Upper Bound of 1: " << *A.upper_bound(1) << endl;
    cout << endl;

    // Remove elements - 2nd query
    A.erase(1);
    A.erase(11); // element that is not present is not affected

    // A contains
    cout << "A = ";
    for (auto i : A)
        cout << i << " ";
    cout << endl;
}