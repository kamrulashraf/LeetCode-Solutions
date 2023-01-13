/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(!head){
            return NULL;
        }
        
        Node* newhead = new Node(0);
        
        Node* cur = head;
        Node* newcur = newhead;
        map < Node*, int> real;
        map < int, Node*> copy;
        
        int idx = 0;
        while(cur){
            newcur-> val = cur -> val;
            if(cur-> next)
                newcur-> next = new Node(0);
            real[cur] = idx;
            copy[idx] = newcur;
            
            idx++;
            cur = cur-> next;
            newcur = newcur -> next;
        }
        
        cur = head;
        newcur = newhead;
        while(cur){
            if(cur-> random){
                idx = real[cur -> random];
                newcur-> random = copy[idx];
            }
            else{
                newcur-> random = NULL;
            }
            
            cur = cur-> next;
            newcur = newcur -> next;
        }
        
        return newhead;
    }
};


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* cur= head;
        Node *newHead = NULL;
        
        while(cur){
            Node *temp = new Node(cur->val);
            
            temp->next = cur->next;
            cur-> next = temp;
            cur = temp->next;
        }
        
        cur = head;
        
        while(cur){
            cur -> next -> random =  cur-> random ? cur-> random -> next: NULL;
            cur = cur -> next -> next;
        }
        
        cur = head;
        
        while(cur){
            if(newHead == NULL){
                newHead = cur->next;    
            }
            
            Node* nextNode = cur->next->next;
            cur -> next -> next = nextNode? nextNode->next : NULL;
            cur -> next = nextNode;
            cur = cur-> next;
        }
           
        return newHead;
    }
};