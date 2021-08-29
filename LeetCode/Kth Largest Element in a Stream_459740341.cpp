class KthLargest {
public:
   int k;
   vector<int> nums;
  priority_queue<int,vector<int>, greater<int> > mnheap;
   
  KthLargest(int k, vector<int>& nums) {      
      this->k = k;
      this->nums = nums; 
      preKmax(); 
  }  
  void preKmax(){
     for(int i=0;i<nums.size();i++){
          mnheap.push(nums[i]);
         if(mnheap.size()>k)
           mnheap.pop();               }
   }   
    int add(int val) { 
     nums.push_back(val);
      mnheap.push(val);
     if(mnheap.size()>k)
       mnheap.pop();
      return mnheap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
