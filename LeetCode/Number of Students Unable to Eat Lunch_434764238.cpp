class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches
        ) {
      
      stack<int> st;
      
      for(int i=sandwiches.size()-1;i>=0;i--)
      {
        st.push(sandwiches[i]);
      }
      
      queue<int> q;
      
      for(int i=0;i<students.size();i++)
        q.push(students[i]);
      
     int count = 0; 
      while(!st.empty())
      {
        if(q.front()==st.top())
           {
           st.pop() ;
           q.pop();
           }
        else
        {
          int temp = q.front();
          q.pop();
          q.push(temp);
          count++;
        }
        if(count>students.size()*students.size())
           break;
        
      }      
      
      return q.size();
    }

