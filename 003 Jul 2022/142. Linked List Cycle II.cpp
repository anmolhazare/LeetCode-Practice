class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*,int> seen;
        while(head!=NULL){
            if(seen.count(head)==1){
                return head;
            }
            seen[head]++;
            head=head->next;
        }
        return NULL;
    }
};
