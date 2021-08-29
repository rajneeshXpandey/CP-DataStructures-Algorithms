/**
 Stack implementation using array
 we can make it dynamic using vector
*/
#include <bits/stdc++.h>
using namespace std;

class Stack{
    private:
        int top;
        int *array;
        int size;
    public:

    // Constructors
        Stack(){};
        Stack(int size){
            this->size = size;
            top = -1;
            array = new int[this->size];
             }  
    // Operations on stack

        bool isEmpty(){
            if(top == -1)
               return true;
            else 
                return false;   
        }

        bool isFull(){
            if(top == size-1)
            return true;
            else 
              return false;
        }


        void push(int x){
            if(!isFull()) 
            {
                 top++;
            array[top]=x;

            }
             else
           {
               cout<<"Overflow!"<<endl;
           }
           
        }  

        int pop(){
           if(!isEmpty()){
           int top_data = array[top];
            top--;
            return top_data;
           }
           else
           {
               //take care of return stmt
               cout<<"Underflow!"<<endl;
               return INT32_MIN;
           }
   
        }   

        int peek(){
            return array[top];
        }

        int curr_size(){
            return top+1;
        }


};

int main(){

    Stack st(5);

    cout<<st.pop()<<endl;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    st.push(6);

    cout<<st.pop()<<endl;
    cout<<st.peek()<<endl;
    cout<<st.curr_size()<<endl;

    while(!st.isEmpty()){
        cout<<st.peek()<<" ";
        st.pop();
    }

return 0;
}