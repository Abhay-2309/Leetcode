class Solution {
private:
    ListNode* head;

public:
    Solution(ListNode* head) {
        this->head = head;
    }
    int getRandom() {
        int chosen_value = 0;
        ListNode* curr = head;
        int i = 1;
        while (curr != nullptr) {
            if (rand() % i == 0)chosen_value = curr->val;
            curr = curr->next;
            i++;
        }
        
        return chosen_value;
    }
};