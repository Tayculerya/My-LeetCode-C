//234. 回文链表
//思路：快慢指针得到对称的一段链表，将其改变方向，然后对照两链表数据是否一致。
//复杂度：O(n)/O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 #include"stdbool.h"
 struct ListNode*reverseList(struct ListNode*head){
    struct ListNode*prer=NULL;
    struct ListNode*now=head;
    while(now!=NULL){
        struct ListNode*next=now->next;
        now->next=prer;
        prer=now;
        now=next;
    }
    return prer;
 }
bool isPalindrome(struct ListNode* head) {
    if(head==NULL||head->next==NULL)return true;
    struct ListNode*fast=head;
    struct ListNode*slow=head;
    while(fast->next!=NULL&&fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    struct ListNode*last=reverseList(slow->next);
    struct ListNode*p1=head;
    struct ListNode*p2=last;
    bool result=true;
    while(p2!=NULL){
        if(p1->val!=p2->val){
            result=false;
            break;
        }
        p1=p1->next;
        p2=p2->next;
    }
    return result;
}
