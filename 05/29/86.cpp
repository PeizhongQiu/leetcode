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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* newHead = new ListNode(0, head);
        ListNode* cur = head;
        ListNode* prev = newHead;
        ListNode* end = cur;
        int num = 1;

        while(end->next != NULL) {
            ++num;
            end = end->next;
        }
        for(int i = 0; i < num; ++i) {
            if(cur->val >= x) {
                if(cur->next != NULL)
                    prev->next = cur->next;
                end->next = cur;
                cur->next = NULL;
                end = cur;
                cur = prev->next;
                
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        return newHead->next;
    }
};