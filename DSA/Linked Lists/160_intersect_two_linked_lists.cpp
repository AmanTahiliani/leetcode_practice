//url: https://leetcode.com/problems/intersection-of-two-linked-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<map>
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *intersection = nullptr;
        ListNode *ptr1 = headA;
        ListNode *ptr2 = headB;

        unordered_set <ListNode*> visited;
        while (ptr1 || ptr2){
            if (ptr1){
                if (visited.find(ptr1) != visited.end()){
                    return ptr1;
                }else{
                    visited.insert(ptr1);
                    ptr1 = ptr1->next;
                }
            }
            if (ptr2){
                if (visited.find(ptr2) != visited.end()){
                    return ptr2;
                }else{
                    visited.insert(ptr2);
                    ptr2 = ptr2->next;
                }
            }

        }
        return nullptr;
    }
};