class LRUCache {
public:
    
    // Custom Doubly Linked List
    class node{
      public :
         int key;
         int value;
        node* next;
        node* prev;
        
      node(int key,int value)
      {
          this->key = key;
          this->value = value;
          next = NULL;
          prev = NULL;
      }
    };
    
    // unordered map / hash map
    
    unordered_map<int,node*> mp;
    
    int size;
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
     
    LRUCache(int capacity) {
        
        head->next = tail;
        tail->prev = head;
        size = capacity;
    }
    
    void addNode(int key,int value)
    {
        node* toinsert = new node(key,value);
        toinsert->next = head->next;
        head->next->prev= toinsert;
        toinsert->prev = head;
        head->next = toinsert;
        
    }

    
    int get(int key) {
        if(mp.find(key)!=mp.end())
        { 
            node* searched = mp[key];
            int res = searched->value;
            
            searched->prev->next = searched->next;  
            searched->next->prev = searched->prev;
            
            searched->next = head->next;
            searched->prev = head;
            
            head->next->prev = searched;
            head->next  = searched;
            
            mp.erase(key);
            
            mp[key] = head->next;

            return res;
        }
        else 
            return -1;
    }
    
    void put(int key, int value) {
        
        if(mp.find(key)!=mp.end()){
            node* already = mp[key]; 
            mp.erase(key); 
            already->prev->next = already->next;
            already->next->prev = already->prev; 
            addNode(key,value); 
            mp[key] = head->next; 
            return; 
        }
        
        
        if(mp.size()==size)
        {
          // if(mp.find(key)!=mp.end())
          //     mp.erase(key);
          
          addNode(key,value);
          mp[key] = head->next; 
          mp.erase(tail->prev->key);
          node* lru = tail->prev;
          tail->prev->prev->next = tail;
          tail->prev = tail->prev->prev;   
           
        }
        else{
        // if(mp.find(key)!=mp.end())
        //       mp.erase(key);
        addNode(key,value);
        mp[key] = head->next;
            
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
