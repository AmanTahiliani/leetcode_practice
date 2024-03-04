//url: https://leetcode.com/problems/linked-list-cycle-ii/

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
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr){
            return nullptr;
        }
        ListNode *slow, *fast;
        slow = head;
        fast = head;

        ListNode *cycleHead;

        while (slow !=nullptr && fast !=nullptr){
            slow = slow->next;
            fast = fast->next;
            if (fast != nullptr){
                fast = fast->next;
            }
            if (fast == nullptr){
                return nullptr;
            }

            if (slow == fast){
                cycleHead = fast;
                break;
            }
        }
        cout<<cycleHead->val;

        ListNode *ptr1 = head;
        ListNode *ptr2 = cycleHead;

        bool one_complete = false;
        bool two_complete = false;

        while (true){
            if ((ptr1 == ptr2) && two_complete){
                return ptr1;
            }
            if (ptr2->next == cycleHead && two_complete==false){
                ptr2 = head;
                two_complete = true;
            }else{
                ptr2 = ptr2->next;
            }
            ptr1 = ptr1->next;
        }

        
    }
};