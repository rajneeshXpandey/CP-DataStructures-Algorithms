#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll ModPower(ll x,ll y)
{
    int m = 5;
    if(x==0)
    return 0;
    if(y==0)
      return 1;
    else if(y%2==0){
        return ModPower((x*x)%m,y/2);
    }  
    else{
            return ((x%m)*ModPower((x*x)%m,y/2))%m;       
    }

}

int main(){


cout<<ModPower(2,4)<<endl;

return 0;
}



