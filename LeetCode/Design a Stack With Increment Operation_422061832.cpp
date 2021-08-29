class CustomStack {
public:
        int *arr ; 
        int top = -1;
        int size;
        
    CustomStack(int maxSize) {
        arr = new int[maxSize];
        size = maxSize; 
    }
    
    void push(int x) {
        if(top == size-1)
            cout<<"Stack is full"<<endl;
        else 
        {
            top++;
            arr[top]=x;
        }
            
    }
    
    int pop() {
        if(top ==-1)
            return -1;
        else
        {
           int x = arr[top];
            top--;
            return x;
          
        }
        
    }
    
    void increment(int k, int val) {
   
            for(int i=0;i<k && i<size ;i++)
                 arr[i] += val;
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
