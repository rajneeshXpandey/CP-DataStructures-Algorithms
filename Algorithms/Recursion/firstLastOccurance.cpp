#include<bits/stdc++.h>
using namespace std;

#define fo(i, n) for (int i = 0; i < n; i++)

int first(int a[],int n,int k,int i)
{
    if(i==n)
      return -1;

    if(a[i]==k)
      return i;   
    
    int subArr = first(a,n,k,i+1);   
    return subArr; 

}

int last(int a[],int n,int k,int i)
{
    if(i==n)
      return -1;   
    
    int subArr = last(a,n,k,i+1); 

    //if found so this is the answer to return finally 
     if(subArr != -1)
         return subArr; 
    //grab the index where we found key from last
    if(a[i]==k)
      return i; 
    //if we don't found it
     else 
     return -1;  

}


// int last(int a[],int n,int k,int i)
// {
//     if(i<0)
//       return -1;

//     if(a[i]==k)
//       return i;   
    
//     int subArr = last(a,n,k,i-1);   
//     return subArr; 

// }






int main(){

int n;
cin>>n;
int array[] = {5,3,2,6,4,2,7};

cout<<first(array,7,2,0)<<" ";
cout<<last(array,7,2,0);
    
return 0;
}



