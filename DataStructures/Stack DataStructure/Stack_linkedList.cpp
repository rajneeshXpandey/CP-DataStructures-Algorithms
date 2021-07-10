// Stack implementation using Linked List

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;

//constructors
    Node(){}
    Node(int x){
        data = x;
        next = NULL;
    }    
};

class Stack{
    private:
       int size;
       Node *head;
    public:
        Stack(){
            size = 0;
            head = NULL;
        };
// Operations 
       bool isEmpty(){
           return (head == NULL);
       }

        void push(int x){
            Node *temp = new Node(x);
            temp->next = head;
            head = temp;
            size++;
        }  

        int pop(){
               //take care of return stmt
           if(head == NULL){
                   cout<<"Underflow!"<<endl;
               return INT32_MIN;
           }

               int pop_val = head->data;
               Node *temp = head;
                 head = head->next;
                 //important
                 delete(temp);
                 size--;
               return pop_val;
   
 
        }   

        int peek(){
            if(head == NULL){
                cout<<"Underflow!"<<endl;
               return INT32_MIN; 
            }
            return head->data;
        }

        int curr_size(){
           return size;
        }        
};

int main(){
     Stack st;

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

