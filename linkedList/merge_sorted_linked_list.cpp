struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* start = new ListNode();               //false head
        ListNode* tmp = start;                          //working node 

        while (l1 && l2) {                                //if we have two lists
            if (l1->val < l2->val) { tmp->next = l1; l1 = l1->next; }
            else { tmp->next = l2; l2 = l2->next; }
            tmp = tmp->next;
        }
        if (l1) tmp->next = l1;                          //if we have only list1 or we have remain as list1
        if (l2) tmp->next = l2;                          //if we have only list2 or we have remain as list2
        return start->next;
    }
    ListNode* deleteDuplicates(ListNode* head) {
        // ListNode* head = new ListNode();
        ListNode* curr = head;
        if(!head) return head;
        while (!head->next)
        {
            if(head->val == head->next->val){
                head->next = head->next->next;
            }
            else {head = head->next; }
        }
        return curr;
    }
};