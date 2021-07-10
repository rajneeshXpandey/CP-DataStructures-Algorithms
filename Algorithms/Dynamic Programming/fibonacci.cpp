#include <bits/stdc++.h>
using namespace std;

int fib1(int n)
{
    if(n==0 || n==1)
      return n;

    return fib1(n-1)+fib1(n-2);  
}

int fib2(int n,int v[])
{
    if (n == 0 || n == 1)
        return n;

    if(v[n]>0)
      return v[n];    

    int output = fib2(n - 1,v) + fib2(n - 2,v);
      v[n] = output;

    return output;
}

int fib3(int n)
{
    int *arr = new int[n+1];
    arr[0]=0;
    arr[1]=1;
    for (size_t i = 2; i < n+1; i++)
    {
        arr[i]=arr[i-1]+arr[i-2];
    }
    int output = arr[n];
    delete [] arr;

    return output;
    
}


int main()
{

    int n=10;
   
    int array[n+1];

    for (int i = 0; i <= n; i++)
        array[i]=-1;

   

    int t = 1;
    //cin>>t;
    while (t--)
    {
        cout<<fib1(10)<<endl;
        cout<<fib2(10,array)<<endl;
        cout<<fib3(10)<<endl;
        
    }

    return 0;
}
