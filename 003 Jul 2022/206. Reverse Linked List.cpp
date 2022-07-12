class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* temp = head;
        while(temp!=NULL){
            ListNode* amit = new ListNode(temp->val);
            if(prev==NULL){
                prev=amit;
            }else{
                amit->next = prev;
                prev = amit;
            }
            temp=temp->next;
        }
        return prev;
    }
};
