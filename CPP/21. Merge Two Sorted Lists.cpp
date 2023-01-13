class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1 == NULL && list2 == NULL){
            return NULL;
        }
        
        ListNode* ret = new ListNode() ;
        ListNode *retHead = ret;
        while(list1 != NULL || list2 != NULL){
            if(list1 == NULL){
                ret -> val = list2 -> val;
                list2 = list2 -> next;
               
            }
            else if(list2 == NULL){
                ret -> val = list1 -> val;
                list1 = list1 -> next;
            }
            else{
                if(list1-> val < list2 -> val){
                    ret -> val = list1->val;
                    list1 = list1-> next;
                }
                else{
                    ret -> val = list2->val;
                    list2 = list2 -> next;
                }
            }
            
            if(list1 != NULL || list2 != NULL){
                ret -> next = new ListNode();
                ret = ret -> next;
            }
            
        }
        
        
        return retHead;
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(!list1 && !list2){
            return NULL;
        }
        ListNode* res, *save;
        save = res = new ListNode();

        while(list1 && list2){
            if(list1-> val < list2-> val){
                res -> val = list1->val;
                list1 = list1->next;
            }
            else{
                res -> val = list2->val;
                list2 = list2->next;
            }

            if(list1 || list2){
                res -> next = new ListNode();
                res = res -> next;
            }
        }

        if(list1){
            while(list1){
                res -> val = list1->val;
                list1 = list1->next;
                if(list1){
                    res -> next = new ListNode();
                    res = res -> next;
                }
            }
        }

        if(list2){
            while(list2){
                res -> val = list2->val;
                list2 = list2->next;
                if(list2){
                    res -> next = new ListNode();
                    res = res -> next;
                }
            }
        }

        return save;
    }
};


// this solution not excepted

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head, *prev = NULL;

        while(list1 && list2){

            while(list1 && list1-> val < list2 -> val){
                if(!head)
                    head = list1;

                prev = list1;
                list1 = list1-> next;
            }

            if(!head)
                    head = list2;

            ListNode* save = list2 -> next;
            insertPrev(prev, list2 , list1);
            prev = list2;
            list2 = save;
        }        

        if(list2){
            if(head == NULL){
                head = list2;
            }
            else
                prev-> next = list2;
        }

        return head1;
    }

    void insertNext(ListNode* cur, ListNode* insert){
        ListNode* save = cur-> next;
        cur -> next = insert;
        insert -> next = save;
    }

    void insertPrev(ListNode *prev, ListNode* insert, ListNode *next){
        if(prev)
            prev -> next  = insert;
        insert -> next = next;
    }

};