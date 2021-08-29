class Solution {
public:
    int evalRPN(vector<string>& tokens) {
       stack<int> st;
       for(auto c : tokens){
           int val1,val2;
           if(c=="+"){
              val2 = st.top();
              st.pop(); 
              val1 = st.top();
              st.pop(); 
              st.push(val1+val2);
           }
           else if(c=="*"){
              val2 = st.top();
              st.pop(); 
              val1 = st.top();
              st.pop(); 
              st.push(val1*val2);
           }
           else if(c=="-"){
               val2 = st.top();
              st.pop(); 
              val1 = st.top();
              st.pop(); 
              st.push(val1-val2);
           }
           else if(c=="/"){
              val2 = st.top();
              st.pop(); 
              val1 = st.top();
              st.pop(); 
              st.push(val1/val2);
           }
           else {
                    int num;
                   if(c.size()>1 and c[0]=='-')  
                    { num = stoi(c.substr(1));
                      num = (-1 * num);
                    }
                   else num = stoi(c);
                   if(num>=-200 and num<=200){
                       st.push(num);
                   }
               }
           }
       
        return st.top();
    }
};
