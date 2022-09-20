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
    void reorderList(ListNode* head) {
        if(head==NULL){
            return;
        }
        queue<ListNode*> qu;
        stack<ListNode*> st;
        ListNode* temp = head;
        int count=0;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        temp=head;
        for(int i=0;i<(count+1)/2;i++){
            qu.push(temp);
            temp=temp->next;
        }
        while(temp!=NULL){
            st.push(temp);
            temp=temp->next;
        }
        head=NULL;
        TreeNode* tail = NULL;
        while(qu.size()!=0){
            if(head==NULL){
                head=qu.front();
                tail=qu.front();
                qu.pop();
                if(st.size()!=0){
                 tail->next=st.top();
                st.pop();
                tail=tail->next;   
                }
            }else{
               tail->next=qu.front();
                qu.pop();
                tail=tail->next;
                if(st.size()!=0){
                 tail->next=st.top();
                st.pop();
                tail=tail->next;   
                }
            }
        }
        tail->next=NULL;
        
    }
};
