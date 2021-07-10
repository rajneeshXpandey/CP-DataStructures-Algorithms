#include<bits/stdc++.h>
using namespace std;

//        && - logical and operator
//        & - bitwise and operator

int getBit(int n,int pos)
{
    return (n & (1<<pos));
}

int setBit(int n,int pos)
{
    return (n | (1<<pos));
}

int clearBit(int n,int pos)
{
    int mask = ~(1<<pos);
    return (mask & n);
}

int updateBit(int n,int pos,int val)
{
    int mask = ~(1<<pos);
    n =  n & mask;
   return (n | (val<<pos));
    
}

int main(){

cout<<setBit(5,2)<<endl;
cout<<getBit(5,2)<<endl;
cout<<clearBit(5,2)<<endl;
cout<<updateBit(5,1,1)<<endl;

return 0;
}



