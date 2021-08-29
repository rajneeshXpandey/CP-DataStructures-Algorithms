class Solution {
public:
    string multiply(string A, string B) {
    string multi = "";
    int sz = A.size()+B.size();
    vector<int> v(sz,0);
    if(A.size()<B.size()) swap(A,B);
     int carry = 0,ans= 0,prod=0;
     int idx = sz-1;
     int k = 0;
    for(int i=B.size()-1;i>=0;i--){
        k=0;
        carry=0;
        for(int j=A.size()-1;j>=0;j--){
            prod = ((A[j]-'0')*(B[i]-'0'))+carry+v[idx-k];
            v[idx-k] = prod%10;
            carry = prod/10;
            k++;
       }
      v[idx-k] += carry; 
      idx--;
    }
   int i=0;
   while(i<v.size() and v[i]==0)
      i++;
   for(int j=i;j<v.size();j++){
       multi += string(1,v[j]+'0');
   }
   return (multi=="")?"0":multi;
    }
};


