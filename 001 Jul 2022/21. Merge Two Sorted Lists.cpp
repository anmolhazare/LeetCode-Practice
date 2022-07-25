class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *ans = NULL;
        ListNode *_next = NULL;
        ListNode *temp1 = list1;
        ListNode *temp2 = list2;
        if(temp1==NULL){
            return temp2;
        }
        if(temp2==NULL){
            return temp1;
        }
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val > temp2->val){
                if(ans==NULL){
                    ans = temp2;
                    _next = temp2;
                }else{
                    _next->next = temp2;
                    _next = _next->next;
                }
                temp2=temp2->next;
            }else{
                if(ans==NULL){
                    ans = temp1;
                    _next = temp1;
                }else{
                    _next->next = temp1;
                    _next = _next->next;
                }
                temp1=temp1->next;
            }
        }
        
        while(temp1!=NULL){
            _next->next = temp1;
            _next = _next->next;
            temp1 = temp1->next;
            
        }
        while(temp2!=NULL){
            _next->next = temp2;
            _next = _next->next;
            temp2 = temp2->next;
            
        }
        return ans;
        
    }
};
