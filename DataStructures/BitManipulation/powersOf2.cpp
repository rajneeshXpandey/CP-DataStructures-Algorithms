#include<bits/stdc++.h>
using namespace std;

#define fo(i, n) for (int i = 0; i < n; i++)

bool power2(int n)
{
    //base case n = 0;
   return (n && !(n & n-1));
    
}

int main(){

cout<<power2(0)<<endl;
cout<<power2(1)<<endl;
cout<<power2(4)<<endl;
cout<<power2(7)<<endl;
cout<<power2(15)<<endl;

return 0;
}



