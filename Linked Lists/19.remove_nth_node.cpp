//url: https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
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
#include<deque>
#include<iostream>
#include<vector>

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        deque<ListNode*> pointers;
        ListNode *ptr = head;

        while (ptr){
            pointers.push_back(ptr);s
            if (pointers.size() > n+1){
                pointers.pop_front();
            }
            ptr = ptr->next;
        }
        if (n>=pointers.size()){
            head = head->next;
        }
        else{
            pointers[0]->next = pointers[1]->next;
            pointers[1]->next = nullptr;
        }
        return head;
    }
};