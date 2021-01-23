#include<bits/stdc++.h>
using namespace std;

#define fo(i, n) for (int i = 0; i < n; i++)
//Extended Euclid Algorithm
class Triplet{
public:
// ax+by = gcd
   int gcd;
   int x;
   int y;

};

Triplet ExtendedEuclid(int a, int b){
    Triplet answer;
     if(b==0){
        
        answer.gcd = a;
        answer.x = 1;
        answer.y=0; 

        return answer;       
     }

     Triplet subAnswer = ExtendedEuclid(b,a%b);
     answer.gcd =  subAnswer.gcd;
     answer.x = subAnswer.y;
     answer.y = subAnswer.x-(a/b)*subAnswer.y;

     return answer;

}

int GCD(int a,int b){
    if(a<b){
        //base case
        if(a==0){
            return b;
        }
        return GCD(a,b%a);
    }
    else{
        //base case
       if(b==0){
           return a;
       }
      return GCD(b,a%b);

    }
}

// APPLICATION OF EXTENDED EUCLID
// (A*B) mod m = 1
int modInverse(int A, int m){
    Triplet answer = ExtendedEuclid(A,m);
    int B;
    B = answer.x;
    return B;
}

int main(){
//Reading and writing input.txt and output.txt   
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
//start code here
int a,b;
cin>>a>>b;

//Basic Euclid Algorithm 
cout<<GCD(a,b)<<endl;

// assume a>b
//Extended Euclid Algorithm
Triplet ans;
ans = ExtendedEuclid(a,b);
cout<<ans.gcd<<" ";
cout<<ans.x<<" ";
cout<<ans.y<<endl;

// APPLICATION OF EXTENDED EUCLID

int x = 5;
int y = 12;

cout<<modInverse(x,y)<<endl;


return 0;
}



