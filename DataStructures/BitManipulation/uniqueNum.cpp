#include<bits/stdc++.h>
using namespace std;

#define fo(i, n) for (int i = 0; i < n; i++)

int uniqueOneOnce(int a[],int n)
{
    int xorsum = 0;
    for(int i=0;i<n;i++)
    {
         xorsum = xorsum^a[i];
    }
    return xorsum;

}

int setBit(int n,int pos)
{
    return (n & 1<<pos != 0);
}

void uniqueTwoOnce(int a[],int n)
{ 
     int xorsum = 0;
    for(int i=0;i<n;i++)
    {
         xorsum = xorsum^a[i];
    }
    int temp = xorsum;
    int pos = 0;

    // int setbit = 0;
    // while(setbit != 0)
    //  {
    //      setbit = setbit & 1;
    //      pos++;
    //      xorsum = xorsum>>1;
    //  }
     
    pos = log2(xorsum & -xorsum)+1;


     int uniqueNum =0;
      for(int i=0;i<n;i++)
    {
        if(setBit(a[i],pos-1) == 1)
            uniqueNum = uniqueNum^a[i];
    }
    cout<<uniqueNum<<endl;
    cout<<(uniqueNum^temp)<<endl; 

} 

int main(){
int array[7] = {3,6,5,8,8,5,6};

cout<<uniqueOneOnce(array,7)<<endl;
int arr[] = {3,6,5,8,8,5,6,4};
uniqueTwoOnce(arr,8);

return 0;
}
