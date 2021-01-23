#include<bits/stdc++.h>
using namespace std;

#define fo(i, n) for (long long i = 0; i < n; i++)


//Need to prlong long ANS%(10^9+7)

long long NumberBalancedBinaryTree(long long h){

   if(h==0 || h==1)
        return 1;

   long long x = NumberBalancedBinaryTree(h-1);
   long long y = NumberBalancedBinaryTree(h-2);

   long long m = pow(10,9)+7;

   long long ans1 = (long long)(x*x);
   long long ans2 = (long long)(x*y*2);

   long long a1 = (long long)(ans1%m);
   long long a2 = (long long)(ans2%m);

   long long ans = (a1+a2)%m;

   return ans;


}

int main(){
//Reading and writing input.txt and output.txt   
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
//start code here
long long height;
cin>>height;

cout<<NumberBalancedBinaryTree(height);

return 0;
}



