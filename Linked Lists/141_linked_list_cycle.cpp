//url = https://leetcode.com/problems/linked-list-cycle/
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
        ListNode *ptr1,*ptr2;
        
        ptr1 = ptr2 = head;
        while (ptr1 && ptr2){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            
            if (ptr2){
                ptr2 = ptr2->next;
            }else{
                return false;
            }

            if (ptr1 == ptr2){
                return true;
            }
        }
        return false;
    }
};