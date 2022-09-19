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
    ListNode* mergeNodes(ListNode* head) {
        if(head==NULL || head->next==NULL) return NULL;
        int sum=0;
        head=head->next;
        while(head->val!=0){
            sum+=head->val;
            head=head->next;
        }
        ListNode* temp = new ListNode(sum);
        ListNode* smallAns = mergeNodes(head);
        temp->next=smallAns;
        return temp;
    }
};
