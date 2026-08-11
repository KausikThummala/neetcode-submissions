



class LRUCache {
private:
    struct Node{
        int key;
        int val;
        Node * next;
        Node * prev;
        Node(int key,int val){
            this->key=key;
            this->val=val;
            next=nullptr;
            prev=nullptr;
        }  
    };

    Node *head;
    Node *tail;
    unordered_map<int,Node*> cache;
    int capacity;
    //now build two functions the head points towards the MRU and the tail->prev points towards LRU
    void removeNode (Node * node){
        node->next->prev=node->prev;
        node->prev->next=node->next;
    }
    //add the MRU to the head
    void insertAthead(Node *node){
        Node * nextNode =head->next;
        head->next=node;
        node->prev=head;
        node->next=nextNode;
        nextNode->prev=node;
    }



public:
//here use a struct and use a hasmap to map elements to the nodes
    LRUCache(int capacity) {
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
        this->capacity=capacity;
    }
    
    int get(int key) {
        if(cache.find(key)==cache.end()){
            return -1;
        }
        Node * node =cache[key];
        removeNode(node);
        insertAthead(node);
        return node->val;
        
    }
    
    void put(int key, int value) {
        //here check if can find the key in our map
        if(cache.find(key)!=cache.end()){
            Node * oldNode=cache[key];
            removeNode(oldNode);
            cache.erase(key);
            delete oldNode;
        }
        //now if we didnt find the value then its easier
        Node * node =new Node(key,value);
        insertAthead(node);
        cache[key]=node;

        if(cache.size()>capacity){
            Node * lru=tail->prev;
            removeNode(lru);
            cache.erase(lru->key);
            delete(lru);
        }
    }

    ~LRUCache() {//destructor to clean up memory
        Node* curr = head;
        while (curr != nullptr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }

};
