// 1. Brute Force O(n^2)
  
// 2. Two pointers technique O(n) 
 // sort first then apply two pointer

#include <bits/stdc++.h>
using namespace std;

void twoPionter(int a[],int n,int key)
{
   int low = 0;
   int high = n-1;

   int st = -1;
   int en = -1;
  
   
    while(low<high)
    {
        if(a[low]+a[high] == key)
        {
            st = low;
            en = high;

             break;
        }
        else if (a[low] + a[high] > key)
          high--;
        else if (a[low] + a[high] < key)
            low++;
    }

    cout<<st<<" "<<en<<endl;
}

int main()
{

    int n;
    cin >> n;
    int array[n];

    for (int i = 0; i < n; i++)
        cin >> array[i];

    int t = 1;
    //cin>>t;
    while (t--)
    { int key;
      cin>>key;
        twoPionter(array,n,key);
    }

    return 0;
}
