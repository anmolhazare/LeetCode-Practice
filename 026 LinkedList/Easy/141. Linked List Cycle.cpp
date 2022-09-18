/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,int> map;
        while(head!=NULL){
            if(map[head]==1) return true;
            map[head]++;
            head=head->next;
        }
        return false;
    }
};
