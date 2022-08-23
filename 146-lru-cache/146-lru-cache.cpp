class LRUCache {
public:
    
    class Node{
        public:
        int key, val;
        Node* prev;
        Node* next;
        
        Node(int key, int val) {
            this->key = key;
            this->val = val;
            // prev = NULL, next = NULL;
        }
        
    };
    
    Node* tail = new Node(-1,-1);
    Node* head = new Node(-1,-1);
    unordered_map<int, Node*> m;
    int cap;
    
    LRUCache(int capacity) {
        head->next = tail;
        tail->prev = head;
        cap = capacity;
    }
    
    int get(int key) {
        if(m.find(key) != m.end()) {
            Node* res = m[key];
            int ans = res->val;
            m.erase(key);
            deleteNode(res);
            addNode(res);
            m[key] = head->next;
            return ans;
            // int ans = m[key]->val;
            // deleteNode(m[key]);
            // addNode(m[key]);
            // m.erase(key);
            // m[key] = head->next;
            // return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()) {
            Node* del = m[key];
            m.erase(key);
            deleteNode(del);
        }
        if(m.size() == cap) {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        m[key] = head->next;
    }
    
    void addNode(Node* node) {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        // Node* left = head;
        // Node* right = head->next;
        // node->next = right;
        // node->prev = left;
        // left->next = node;
        // right->prev = node;
    }
    
    void deleteNode(Node* node) {
        Node* delprev = node->prev;
        Node* delnext = node->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        // Node* left = tail->prev;
        // Node* right = tail;
        // node->next = right;
        // node->prev = left;
        // left->next = node;
        // right->prev = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */