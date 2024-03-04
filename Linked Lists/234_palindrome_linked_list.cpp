//url

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
    ListNode* reverseLinkedList(ListNode* head){
        if (head->next == nullptr){
            return head;
        }

        ListNode *prev, *curr, *front;
        prev = nullptr;
        curr = head;
        while (curr){
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode *ptr = head;
        int numNodes = 0;
        
        if (head->next == nullptr){
            return true;
        }

        while(ptr){
            numNodes += 1;
            ptr = ptr->next;
        }

        ListNode *ptr1, *ptr2;
        ListNode *prev, *curr, *front; 
        int revNode, frontNode;
        
        if (numNodes %2 == 1){
            int middle = (numNodes + 1)/2;
            revNode = middle - 1;
            frontNode = middle + 1;
        }else{
            revNode = numNodes / 2;
            frontNode = revNode + 1;
        }

        ptr = head;
        numNodes = 0;
        while (ptr){
            numNodes += 1;
            if (numNodes == revNode){
                ptr1 = ptr;
            }else if (numNodes == frontNode){
                ptr2 = ptr;
                break;
            }
            ptr = ptr->next;
        }
        ptr1->next = nullptr;
        ptr1 = reverseLinkedList(head);
        while(ptr1 != nullptr && ptr2 != nullptr){
            if (ptr1->val != ptr2->val){
                return false;
            }else{
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
        }
        return true;
    }
};