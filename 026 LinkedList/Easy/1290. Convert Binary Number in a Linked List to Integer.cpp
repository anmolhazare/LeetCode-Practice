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
    int length(ListNode* head){
        if(head==NULL) return 0;
        return length(head->next)+1;
    }
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        int power = length(temp)-1;
        int res=0;
        while(head!=NULL){
            res+=(head->val)*pow(2,power);
            power--;
            head=head->next;
        }
        return res;
    }
};
