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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head -> next){
            return head;
        }
        
        ListNode *fst, *snd;
        fst = head;
        snd = head -> next;
        
        ListNode *prev = NULL;
        head = head -> next;
        
        while(snd){
            ListNode *tempfst, *tempsnd;
            if(fst && fst -> next)
                tempfst = fst -> next -> next;
            else
                tempfst = NULL;
            
            if(snd && snd->next)
                tempsnd  = snd -> next -> next;
            else
                tempsnd = NULL;
            
            
            // fst -> next = tempfst;
            snd -> next = fst;
            fst -> next = tempfst;
            
            if(prev){
                prev -> next = snd;
            }
            
            prev = fst;
            
            fst = tempfst;
            snd = tempsnd;
        }
        
        return head;
    }
};