//url: https://leetcode.com/problems/add-two-numbers/description/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ptr1 = l1;
        ListNode *ptr2 = l2;
        ListNode *dummyHead = new ListNode();
        ListNode *ptr3 = dummyHead; 
        int carry = 0;

        while (ptr1 != nullptr || ptr2 != nullptr || carry != 0) {
            int sum = carry;
            if (ptr1 != nullptr) {
                sum += ptr1->val;
                ptr1 = ptr1->next;
            }
            if (ptr2 != nullptr) {
                sum += ptr2->val;
                ptr2 = ptr2->next;
            }
            carry = sum / 10;
            sum %= 10;
            ptr3->next = new ListNode(sum);
            ptr3 = ptr3->next;
        }

        ListNode *result = dummyHead->next;
        delete dummyHead; 
        return result;
    }
};