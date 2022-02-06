#include <algorithm>
#include <vector>
using namespace std;

/*
148. 排序链表
https://leetcode-cn.com/problems/sort-list/
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct Rule {
    bool operator()(ListNode* node1, ListNode* node2) const {
        return (node1->val) < (node2->val);
    }
};

class Solution {
   public:
    vector<ListNode*> vec;
    ListNode* sortList(ListNode* head) {
        ListNode* t = head;
        while (t != nullptr) {
            vec.push_back(t);
            t = t->next;
        }
        if (vec.size() == 0) {
            return head;
        }
        sort(vec.begin(), vec.end(), Rule());

        ListNode* headNew = vec[0];
        head = headNew;
        for (int i = 1; i < vec.size(); ++i) {
            head->next = vec[i];
            head = head->next;
        }
        head->next = nullptr;
        return headNew;
    }
};