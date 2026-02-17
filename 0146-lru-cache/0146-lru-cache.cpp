class LRUCache {
public:
    class Node {
        public:
            int key, val;
            Node* prev;
            Node* next;
            Node(int k ,int v){
                key = k;
                val = v;
                prev = next = NULL;
            }
    };
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    unordered_map<int,Node*>m;
    int limit;

    void addNode(Node* newNode){
        Node* oldNext = head->next;
        head->next = newNode;
        oldNext->prev = newNode;
        newNode->next = oldNext;
        newNode->prev = head;
    }

    void delNode(Node* oldNode){
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;
        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()){ // means val is not present in map
            return -1;
        }
        // make new node to swap lru for mru
        Node* ansNode = m[key];
        int ans = ansNode->val; // to print val 
        m.erase(key);
        delNode(ansNode);
        addNode(ansNode);
        m[key] = ansNode;
        return ans;
    }
    
    void put(int key, int val) {
        if(m.find(key)!=m.end()){ // means if same key value is present
            Node* oldNode = m[key];
            delNode(oldNode);
            m.erase(key);
        }
        // if limit exceeds 
        if(m.size()==limit){
            m.erase(tail->prev->key);
            delNode(tail->prev);
        }
        // add newnode to store key & & also store in map
        Node* newNode = new Node(key, val);
        addNode(newNode);
        m[key]=newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */