#include<bits/stdc++.h>
using namespace std;

#define fo(i, n) for (int i = 0; i < n; i++)

int getBit(int n,int pos)
{
    return ((n & (1<<pos)) != 0);
}
int setBit(int n,int pos)
{
    return (n | (1<<pos));
}

int uniqueThrice(int a[],int n)
{
  
   int result=0;
   for(int j=0;j<64;j++)
   {
       int sum = 0;
       for(int i =0;i<n;i++)
        {
          if(getBit(a[i],j))
            sum++;
         }
        if(sum%3!=0)
           result = setBit(result,j);
              
   }
return result;  

}

int main(){

int array[] = {1,2,3,4,1,2,3,1,2,3};

cout<<uniqueThrice(array,10);

return 0;
}



