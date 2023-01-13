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
    bool hasCycle(ListNode *head) {
        unordered_map < ListNode*, bool > mark;
        
        ListNode* cur = head;
        bool ret = false;
        while(cur != NULL){
            if(mark[cur] == true){
                ret = true;
                break;
            }
            mark[cur] = true;
            cur = cur -> next;
        }
        
        return ret;
    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow , *fast;
        slow = head;
        fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next ->next;

            if(slow == fast){
                return true;
            }
        }

        return false;
    }
};