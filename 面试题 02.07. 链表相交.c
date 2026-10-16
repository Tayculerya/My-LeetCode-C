//面试题 02.07. 链表相交
//思路：求出长度，双指针求相同节点。
//复杂度：O(len1+len2)/O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* la=headA;
    int len1=0;
    while(la!=NULL){
        len1++;
        la=la->next;
    }
    la=headA;
    struct ListNode* lb=headB;
    int len2=0;
    while(lb!=NULL){
        len2++;
        lb=lb->next;
    }
    lb=headB;
    int def=0;
    if(len1>len2){
    def=len1-len2;
    while(def>0) {
        la=la->next;
        def--;
    }
    }else{
        def=len2-len1;
        while(def>0) {
            lb=lb->next;
            def--;
        }
    }
    while(la!=NULL&&lb!=NULL){
        if(la==lb){
            return la;
        }
        la=la->next;
        lb=lb->next;
    }
    return NULL;
}