/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<ListNode*> st;
        ListNode* cur= head;
        while(cur){
            st.push(cur);
            cur = cur -> next;
        }
        
        cur = head;
        while(cur){
            if(cur -> val != st.top() -> val){
                return false;
            }
            
            st.pop();
            cur = cur -> next;
        }
        
        return true;
    }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        
        if(!head || !head-> next){
            return true;
        }
        ListNode* slow, *fast, *prev;
        
        slow = fast = head;
        
        while(fast && fast->next){
            prev = slow;
            slow = slow -> next;
            fast = fast->next -> next;
        }
        
        ListNode *cur;
        cur = slow;
        prev -> next = NULL;
        
        ListNode *next;
        
        prev = NULL;
        
        while(cur){
            next = cur-> next;
            
            cur -> next = prev;
            prev = cur;
            cur = next;
        }
        
        
        while(prev && head){
            if(prev -> val != head -> val){
                return false;
            }
            
            prev = prev-> next;
            head = head -> next;
        }
        
        return true;
        
        
    }
};