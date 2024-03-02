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
#include<utility>
class Solution {
public:
    pair<ListNode*, ListNode*> reverseFull(ListNode* head){
        if(head == nullptr || head->next == nullptr){
            return make_pair(head,head);
        }
        pair<ListNode*,ListNode*> out;
        ListNode *prev, *curr, *front;

        prev = head;
        curr = prev->next;

        while (curr){
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        
        return make_pair(prev, head);
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr){
            return nullptr;
        }
        ListNode* currStart = head;
        ListNode* currEnd = currStart;
        ListNode* nextBatchHead = nullptr;
        int currSize = 1;
        while (currSize <k){
            currEnd = currEnd->next;
            if (currEnd != nullptr){
                currSize += 1;
            }else{
                return head;
            }
        }
        nextBatchHead = currEnd->next;
        currEnd->next = nullptr;

        pair<ListNode *,ListNode*> reversedBatch = reverseFull(head);
        if (reversedBatch.second!=nullptr){
            reversedBatch.second->next = reverseKGroup(nextBatchHead, k);
        }
        return reversedBatch.first;

    }
};