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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num1=0,num2=0;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* ans = NULL;
        ListNode* tail = NULL;
        if(temp1==NULL){
            return temp2;
        }
        if(temp2==NULL){
            return temp1;
        }
        int carray = 0;
        while(temp1!=NULL || temp2!=NULL){
            int c1,c2;
            if(temp1!=NULL){
                c1=temp1->val;
                temp1 = temp1->next;
            }else{
                c1=0;
            }
            if(temp2!=NULL){
                c2=temp2->val;
                temp2 = temp2->next;
            }else{
                c2=0;
            }
            int res = c1 + c2 + carray;
            if(res>9){
                carray = 1;
                res = res-10;
            }else{
                carray = 0;
            }
            ListNode* temp = new ListNode(res);
            if(ans==NULL){
                ans = temp;
                tail = temp;
            }else{
                tail->next = temp;
                tail = tail->next;
            }
        }
        if(carray==1){
            ListNode* temp = new ListNode(1);
            tail->next = temp;
            tail = tail->next;
        }
        
        
        return ans;
        
    }
};
