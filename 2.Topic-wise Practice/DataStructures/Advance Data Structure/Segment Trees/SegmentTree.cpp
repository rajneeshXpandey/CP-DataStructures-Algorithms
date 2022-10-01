#include<bits/stdc++.h>
using namespace std;

#define int long long

#define N  6
int st[4*N];

void buildST(int s,int e,int idx,int arr[],int n){
     if(s==e)
      {   st[idx]=arr[s];
           return ;
          }
      int mid = (s+e)/2;
      buildST(s,mid,2*idx+1,arr,n);
      buildST(mid+1,e,2*idx+2,arr,n);

      st[idx]=st[2*idx+1]+st[2*idx+2];    
}

int sumRangeQuery(int L,int R,int s,int e,int idx)
{
    //complete overlap
    if(L<=s and R>=e)
      return st[idx];
    //no overlap
    else if(L>e or R<s)
       return 0;
    //partial overlap
    int mid = (s+e)/2;
    int left = sumRangeQuery(L,R,s,mid,2*idx+1);
    int right = sumRangeQuery(L,R,mid+1,e,2*idx+2);
    return left+right;

}

void updateQuery(int i,int val,int s,int e,int idx,int arr[])
{
    if(s==e)
     {  // check if needed for the updation in arr also
         //arr[i]=val;
        st[idx]=val;
        return;
        }
    
    int mid = (s+e)/2; 
    if(i <= mid)
        updateQuery(i, val, s, mid, 2 * idx + 1,arr);
    else if(i > mid)
        updateQuery(i, val, mid + 1, e, 2 * idx + 2,arr);

    st[idx] = st[2 * idx + 1] + st[2 * idx + 2];

}

signed main()
{
    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        int arr[N];

        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
       }
      buildST(0,N-1,0, arr,N);
      for (int i = 0; i < 4*N; i++)
      {
          cout<<st[i]<<" ";
      }
      cout<<endl;
      
      int sum=sumRangeQuery(2,4,0,N-1,0);
      cout<<sum<<endl;
      updateQuery(3,50,0,N-1,0,arr);
      for (int i = 0; i < 4 * N; i++)
      {
          cout << st[i] << " ";
      }
      cout << endl;
      int sum2 = sumRangeQuery(2, 4, 0, N-1, 0);
      cout << sum2 << endl;
    }
    return 0;
}