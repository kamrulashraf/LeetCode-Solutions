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
    ListNode* sortList(ListNode* head) {
        
        if( head == NULL || head -> next == NULL)
            return head;
        ListNode *mid = findMid(head);
        
        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);
        
        ListNode *ret = merge(left, right);
        return ret;
    }
    
    ListNode* findMid(ListNode* head){
        ListNode *slow, *fast, *midPrev = NULL;
        slow = fast = head;
        
        while(fast != NULL && fast-> next !=NULL){
            midPrev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        if(midPrev != NULL)
            midPrev -> next = NULL;
        
        return slow;
    }
    
    ListNode* merge(ListNode *left, ListNode *right){
        ListNode* ret = new ListNode();
        ListNode *head = ret;
        
        while(left != NULL || right != NULL){
            if(left == NULL){
                ret -> val = right -> val;
                right = right -> next;
            }
            else if(right == NULL){
                ret -> val = left -> val;
                left = left -> next;
            }
            else{
                if(left -> val < right -> val){
                    ret -> val = left -> val;
                    left = left -> next;
                }
                else{
                    ret->val = right->val;
                    right= right->next;
                }
            }

            if(left != NULL || right != NULL){
                ret -> next = new ListNode();
                ret = ret -> next;
            }
        }
        
        return head;
    }
};  