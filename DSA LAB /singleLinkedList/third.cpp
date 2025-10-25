#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) { data = val; next = NULL; }
};
class LinkedList {
    Node* head;
public:
    LinkedList() { head = NULL; }
    void insertEnd(int x) {
        Node* n = new Node(x);
        if (head == NULL) { head = n; return; }
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = n;
    }
    void findMiddle() {
        Node* slow = head;
        Node* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (slow != NULL) cout << slow->data;
    }
};
int main() {
    LinkedList l;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> x; l.insertEnd(x); }
    l.findMiddle();
}
