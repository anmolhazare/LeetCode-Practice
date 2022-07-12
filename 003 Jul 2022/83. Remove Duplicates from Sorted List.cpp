class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL){
            return head;
        }
        ListNode* temp = deleteDuplicates(head->next);
        if(temp!=NULL && head->val==temp->val){
            ListNode* amit = head;
            head=temp;
            delete(amit);
        }else{
            head->next=temp;
        }
        return head;
    }
};
