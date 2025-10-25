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
    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next) cout << "->";
            temp = temp->next;
        }
        cout << "->NULL\n";
    }
};
int main() {
    LinkedList l;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> x; l.insertEnd(x); }
    l.reverse();
    l.display();
}
