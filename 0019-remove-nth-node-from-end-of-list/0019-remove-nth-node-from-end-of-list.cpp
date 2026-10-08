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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)return NULL;
          int len=0;
          ListNode* temp=head;
          while(temp!=NULL){
               len++;
               temp=temp->next;
          }

          int pos=len-n;
             // If removing the head
        if (pos == 0)
            return head->next;
            
          temp=head;
          int path=1;
          while(temp!=NULL && path!=pos){
                path++;
                temp=temp->next;
          }
          temp->next=temp->next->next;
    return head;

    }
};