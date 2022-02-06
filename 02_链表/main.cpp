#include <cstdio>
#include <iostream>
using namespace std;

#include "146LRUCache.cpp"
int main() {
    LRUCache* lRUCache = new LRUCache(2);
    lRUCache->put(1, 1);  // 缓存是 {1=1}
    lRUCache->put(2, 2);  // 缓存是 {1=1, 2=2}
    cout << "1.get(1)=" << lRUCache->get(1) << endl;     // 返回 1
    lRUCache->put(3, 3);  // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    cout << "2.get(2)=" << lRUCache->get(2) << endl;  // 返回 -1 (未找到)
    lRUCache->put(4, 4);  // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    cout << "3.get(1)=" << lRUCache->get(1) << endl;  // 返回 -1 (未找到)
    cout << "4.get(3)=" << lRUCache->get(3) << endl;  // 返回 3
    cout << "5.get(4)=" << lRUCache->get(4) << endl;  // 返回 4
    return 0;
}

/*
#include "160getIntersectionNode.cpp"
int main() {
    ListNode* n11 = new ListNode(4);
    ListNode* n12 = new ListNode(1);
    ListNode* n21 = new ListNode(5);
    ListNode* n22 = new ListNode(6);
    ListNode* n23 = new ListNode(1);
    ListNode* nk1 = new ListNode(8);
    ListNode* nk2 = new ListNode(4);
    ListNode* nk3 = new ListNode(5);

    nk1->next = nk2;
    nk2->next = nk3;
    nk3->next = nullptr;
    n11->next = n12;
    n12->next = nk1;
    n21->next = n22;
    n22->next = n23;
    // n23->next = nk1;

    Solution solu;
    ListNode* ans = solu.getIntersectionNode(n11, n21);
    if (ans == nullptr)
        cout << "no intersection";
    else
        cout << "intersect at " << ans->val;
    return 0;
}
*/

/*
#include "142detectCycle.cpp"
int main() {
    ListNode* n1 = new ListNode(3);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(0);
    ListNode* n4 = new ListNode(-4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;

    Solution solu;
    ListNode* ans = solu.detectCycle(n1);
    cout << ans->val;
}
*/

/*
#include "141hasCycle.cpp"
int main() {
    ListNode* n1 = new ListNode(3);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(0);
    ListNode* n4 = new ListNode(-4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;

    Solution solu;
    bool ans = solu.hasCycle(n1);
    cout << ans;
}
*/

/*
#include "21mergeTwoLists.cpp"
int main() {
    ListNode* n13 = new ListNode(4, nullptr);
    ListNode* n12 = new ListNode(2, n13);
    ListNode* n11 = new ListNode(1, n12);

    ListNode* n23 = new ListNode(4, nullptr);
    ListNode* n22 = new ListNode(3, n23);
    ListNode* n21 = new ListNode(1, n22);

    ListNode* n1 = n11;
    ListNode* n2 = n21;
    Solution solu;
    ListNode* ans = solu.mergeTwoLists(n1, n2);
    while (ans != nullptr) {
        cout << ans->val << ",";
        ans = ans->next;
    }
    return 0;
}
*/

/*
#include "148sortList.cpp"
int main() {
    ListNode* node4 = new ListNode(3, nullptr);
    ListNode* node3 = new ListNode(1, node4);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* node1 = new ListNode(4, node2);

    ListNode* head = node1;
    while (head != nullptr) {
        cout << head->val << ",";
        head = head->next;
    }
    cout << " --> ";

    head = node1;
    Solution solu;
    ListNode* ans = solu.sortList(head);
    while (ans != nullptr) {
        cout << ans->val << ",";
        ans = ans->next;
    }
    return 0;
}
*/

/*
#include "24swapPairs.cpp"
int main() {
    ListNode* node4 = new ListNode(4, nullptr);
    ListNode* node3 = new ListNode(3, node4);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* node1 = new ListNode(1, node2);

    ListNode* head = node1;

    Solution solu;
    ListNode* ans = solu.swapPairs(head);
    while (ans != nullptr) {
        cout << ans->val << ",";
        ans = ans->next;
    }
    return 0;
}
*/

/*
#include "25reverseKGroup.cpp"
int main() {
    ListNode* node5 = new ListNode(5, nullptr);
    ListNode* node4 = new ListNode(4, node5);
    ListNode* node3 = new ListNode(3, node4);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* node1 = new ListNode(1, node2);

    ListNode* head = node1;
    int k = 3;

    Solution solu;
    ListNode* ans = solu.reverseKGroup(head, k);
    while (ans != nullptr) {
        cout << ans->val << ",";
        ans = ans->next;
    }
    return 0;
}
*/

/*
#include "206reverseList.cpp"
int main() {
    ListNode* node5 = new ListNode(5,nullptr);
    ListNode* node4 = new ListNode(4,node5);
    ListNode* node3 = new ListNode(3,node4);
    ListNode* node2 = new ListNode(2,node3);
    ListNode* node1 = new ListNode(1,node2);

    ListNode* head = node1;

    Solution solu;
    ListNode* ans = solu.reverseList(node1);
    while (ans != nullptr) {
        cout << ans->val << ",";
        ans = ans->next;
    }
    return 0;
}
*/
