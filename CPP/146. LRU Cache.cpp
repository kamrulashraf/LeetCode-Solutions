class LRUCache {
public:
    int capacityLRU;
    int curElement;
    struct doubleLinkedList{
        int val;
        int key;
        doubleLinkedList *prev;
        doubleLinkedList *next;
        doubleLinkedList(int _key, int _val){
            val = _val;
            key = _key;
            prev = NULL;
            next = NULL;
        }
        
    };
    doubleLinkedList *head = NULL;
    doubleLinkedList *rear = head;
    unordered_map < int, doubleLinkedList*> hash;
    
    LRUCache(int capacity) {
        capacityLRU  = capacity;
        curElement = 0;
    }
    
    int get(int key) {
        if(hash[key] == 0){
            return -1;
        }
        else{
            removeElement(hash[key]);
            addToRear(hash[key]);
            return hash[key]->val;
        }
    }
    
    void put(int key, int value) {
        if(hash[key] == 0){
            doubleLinkedList *temp = new doubleLinkedList(key, value);

            hash[key] = temp;    
            if(curElement == capacityLRU){
                hash.erase(head->key);
                removeFornt();
                addToRear(temp);
            }
            else{
                curElement++;
                addToRear(temp);
            }
        } else{
            doubleLinkedList *temp = hash[key];
            removeElement(temp);
            doubleLinkedList *newEl = new doubleLinkedList(key, value);
            hash[key] = newEl;
            addToRear(newEl);
        }
    }
    
    void removeFornt(){
        if(head != NULL){
            head =  head -> next;
        }
    }
    
    void removeElement(doubleLinkedList *node){
        if(curElement == 1){
            head = NULL;
            rear = NULL;
            return;
        }
        int val1 = node -> val;
        doubleLinkedList *test = head;
        if(node == head){
            removeFornt();
            return;
        }
        else if(node == rear){
            rear = rear -> prev;
        }
        else{
            node -> prev -> next = node -> next;
            node -> next -> prev = node -> prev;
        }
    }
    
    void addToRear(doubleLinkedList *node){
        if(head == NULL){
            head = node;
            rear = node;
            return;
        }
        node -> prev = rear;
        rear -> next = node;
        rear = node;
        
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */