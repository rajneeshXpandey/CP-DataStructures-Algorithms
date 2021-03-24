#include <bits/stdc++.h>
using namespace std;

unordered_map<string,int> mp;

class Solution{
public:
    
int MCM(string s,int i,int j,bool isTrue)
    {  //base case
      if(i>j) return 0;
     if(i==j) // single value
	{
		if(isTrue==true)
		{
			if(s[i]=='T') return true;
			else
			return false;
		}
		else if(isTrue==false)
		{
			if(s[i]=='F') return true;
			else
			return false;
		}
	}
        
      string key = to_string(i)+"_"+to_string(j)+"_"+to_string(isTrue);
      
      if(mp.find(key) != mp.end())
          {
          return mp[key];
          }
          
        int ans = 0;
          
        for(int k=i+1;k<=j-1;k=k+2)
        {
            int lT = MCM(s,i,k-1,true);
            int lF = MCM(s,i,k-1,false);
            int rT = MCM(s,k+1,j,true);
            int rF = MCM(s,k+1,j,false);
            
            if(s[k]=='&')
              {
                  if(isTrue)
                     ans += lT*rT; 
                  else 
                     ans += lT*rF+rT*lF+rF*lF;
              }
            else if(s[k]=='|')
            {
                if(isTrue)
                      ans += lT*rF+rT*lF+rT*lT;
                  else 
                      ans += rF*lF; 
            } 
            else if(s[k]=='^')
            {
                 if(isTrue)
                      ans += lT*rF+rT*lF;
                  else 
                      ans += rF*lF+rT*lT;  
            }
            
            //cout<<ans<<endl;
            // return ans;
           
        }
        return mp[key] = ans%1003;
          
    }
    
    int countWays(int N, string S){
        // code here
        mp.clear();
        return ((MCM(S,0,N-1,true))%(1003));
    }
};



int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
} 