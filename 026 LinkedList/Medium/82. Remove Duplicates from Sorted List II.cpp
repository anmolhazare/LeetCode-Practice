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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL){
            return head;
        }
        ListNode* temp = head;
        ListNode* start = NULL;
        ListNode* end = NULL;
        unordered_map<int,int> seen;
        while(temp!=NULL){
            seen[temp->val]++;
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL){
            if(seen[temp->val]==1){
                ListNode* amit = new ListNode(temp->val);
                if(start==NULL){
                    start=amit;
                    end=amit;
                }else{
                    end->next=amit;
                    end=end->next;
                }
            }
            temp=temp->next;
        }
        return start;
    }
};
