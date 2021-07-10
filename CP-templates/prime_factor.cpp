
map<int,int> mp;

int prime_fact(int n)
 {
     for(int i=2;i*i<=n;i++)
      {
          if(n%i==0) 
            {
                while(n%i==0)
                  mp[i]++,n/=i;
            }
      }
      if(n>1) mp[n]++;
 }