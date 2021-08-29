class Solution {
public:
  bool KMP(string s,string p){ 
  string str = p + "#" + "#" + s;
  vector<int> pi(str.size());
  pi[0] = 0;
  for(int i=1;i<str.size();i++){
      int l = pi[i-1];
      while(l>0 and str[i]!=str[l]){
          l = pi[l-1];
      }
      if (str[i] == str[l])
        l++;
      pi[i] = l;  
  }
  for(auto len : pi){
      if(len==p.size()){
         return true;
      }
  }
  return false;
}
    int repeatedStringMatch(string a, string b) {
        
        int rem = b.size()-a.size();
        if(rem<0){
            if(KMP(a,b))
                return 1;
            a += a;
            if(KMP(a,b))
                return 2;
            return -1;  
        }
        int sz =0;
        string str = "";
        while(str.size()<b.size())
           {
             str += a;
             sz++;
            }
        if(KMP(str,b))
                return sz;
        str += a;
        sz++;
        if(KMP(str,b))
                return sz;
        return -1;
        
    }
};
