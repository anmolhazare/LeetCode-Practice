class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*,int> seen;
        while(head!=NULL){
            if(seen.count(head)){
                return true;
            }
            seen[head]++;
            head=head->next;
        }
        return false;
    }
};
