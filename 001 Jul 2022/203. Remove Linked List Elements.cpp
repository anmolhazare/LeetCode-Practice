class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL){
            return head;
        }
        ListNode *temp = removeElements(head->next,val);
        if(head->val==val){
            head=temp;
        }else{
            head->next = temp;
        }
        return head;
    }
};
