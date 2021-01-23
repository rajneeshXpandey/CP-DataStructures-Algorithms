#include<bits/stdc++.h>
using namespace std;


int numOf1(int n)
{
    int count = 0 ;
       while(n>0)
       {
           n = n & n-1;
           count++;
       } 
       return count;
}

    

int main(){

cout<<numOf1(0)<<endl;
cout<<numOf1(1)<<endl;
cout<<numOf1(10)<<endl;
cout<<numOf1(17)<<endl;



return 0;
}



