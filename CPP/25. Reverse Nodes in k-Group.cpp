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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *cur = head, *res = NULL, *resHead = NULL;
        
        while(cur){
            pair<ListNode*, ListNode*> ret = reverseNode(cur,k);
            cur =  ret.second;
            if(res == NULL){
                res = ret.first;
                resHead = res;
            }
            else{
                while(res -> next){
                    res = res->next;
                }
                res -> next = ret.first;
            }
        }
        
        return resHead;
        // return reverseNode(head,k).first;
    }
    
    
    pair< ListNode*, ListNode*> reverseNode(ListNode* head, int k){
        ListNode *cur = head;
        ListNode* prev = NULL;
        int temp = k;
        while(temp--){
            if(cur == NULL){
                return make_pair(head, cur);
            }
            cur = cur-> next;
            
        }
        
        cur = head;
        
        while(k-- && cur){
            ListNode *next = cur->next;
            ListNode *process = cur;
            cur -> next = prev;
            cur = next;
            prev = process;
        }
        
        
        return make_pair(prev,cur);
    }
};