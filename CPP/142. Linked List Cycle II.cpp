/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast, *slow, *intersect = NULL;
        
        if(head == NULL || head -> next == NULL || head -> next -> next == NULL){
            return NULL;
        }
        
        slow = head;
        fast = head;
        
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast){
                intersect = slow;
                break;
            }
        }
        
        if(intersect == NULL){
            return NULL;
        }
        else{
            slow = head;
            
            while(slow != fast){
                slow = slow -> next;
                fast = fast -> next;
            }
        }
        
        
        return slow;
    
    }
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map < ListNode* , bool > mark;
        int pos = 1;
        ListNode* result = NULL;
        while(head != NULL){
            
            if(mark[head] == true){
                result = head;
                break;
            }
            mark[head] = true;
            head = head -> next;
        }
        
        return result;
    }
};