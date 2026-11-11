#include <queue>
#include <vector>

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        auto compare = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(compare)> nodes(compare);

        for (ListNode* node : lists) {
            if (node != nullptr) {
                nodes.push(node);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!nodes.empty()) {
            ListNode* current = nodes.top();
            nodes.pop();

            tail->next = current;
            tail = current;

            if (current->next != nullptr) {
                nodes.push(current->next);
            }
        }

        tail->next = nullptr;
        return dummy.next;
    }
};
