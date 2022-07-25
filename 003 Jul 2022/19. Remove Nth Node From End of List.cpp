class Solution {
public:
    ListNode* helper(ListNode* head,int k){
        if(head==NULL){
            return head;
        }
        ListNode* temp = helper(head->next,k-1);
        if(k==0){
            return temp;
        }
        head->next=temp;
        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || n==0  || head->next==NULL){
            return NULL;
        }
        int len=0;
        ListNode* temp = head;
        while(temp!=0){
            temp=temp->next;
            len++;
        }
        return helper(head,len-n);
    }
};
