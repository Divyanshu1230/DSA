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
#define null NULL
#define Node ListNode
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == null || head->next == null || k==0){
            return head;
        }

        int L = 1; //for head
        Node* tail = head;
        while(tail->next != null){
            tail = tail->next;
            L++;
        }

        // Reduce unnecessary rotation
        k = k % L;
        if(k==0) return head;

        // make circular LL
        tail->next = head;

        int remain = L-k;
        Node* newTail = head;
        for(int c=1; c < remain; c++){
            newTail = newTail->next;
        }
        Node* newHead = newTail->next;
        newTail->next = null;

        return newHead;
    }
};