class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* temp = head;

        int i = 0;
        vector<int> critical;

        while (temp != NULL && temp->next != NULL) {

            // First node cannot be a critical point
            if (prev != NULL) {

                // Local maximum
                if (prev->val < temp->val &&
                    temp->val > temp->next->val) {

                    critical.push_back(i);
                }

                // Local minimum
                else if (prev->val > temp->val &&
                         temp->val < temp->next->val) {

                    critical.push_back(i);
                }
            }

            prev = temp;
            temp = temp->next;
            i++;
        }

        // Less than 2 critical points
        if (critical.size() < 2) {
            return {-1, -1};
        }

        int mini = INT_MAX;

        for (int j = 1; j < critical.size(); j++) {
            mini = min(mini, critical[j] - critical[j - 1]);
        }

        int maxi = critical[critical.size() - 1] - critical[0];

        return {mini, maxi};
    }
};