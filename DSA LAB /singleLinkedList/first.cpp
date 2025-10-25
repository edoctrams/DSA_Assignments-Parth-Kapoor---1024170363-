#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};
class LinkedList {
    Node* head;
public:
    LinkedList() { head = NULL; }

    void insertBeg(int x) {
        Node* n = new Node(x);
        n->next = head;
        head = n;
    }

    void insertEnd(int x) {
        Node* n = new Node(x);
        if (head == NULL) { head = n; return; }
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = n;
    }

    void insertBefore(int val, int x) {
        if (head == NULL) return;
        if (head->data == val) { insertBeg(x); return; }
        Node* temp = head;
        while (temp->next != NULL && temp->next->data != val) temp = temp->next;
        if (temp->next == NULL) return;
        Node* n = new Node(x);
        n->next = temp->next;
        temp->next = n;
    }

    void insertAfter(int val, int x) {
        Node* temp = head;
        while (temp != NULL && temp->data != val) temp = temp->next;
        if (temp == NULL) return;
        Node* n = new Node(x);
        n->next = temp->next;
        temp->next = n;
    }

    void delBeg() {
        if (head == NULL) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void delEnd() {
        if (head == NULL) return;
        if (head->next == NULL) { delete head; head = NULL; return; }
        Node* temp = head;
        while (temp->next->next != NULL) temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }

    void delNode(int val) {
        if (head == NULL) return;
        if (head->data == val) { delBeg(); return; }
        Node* temp = head;
        while (temp->next != NULL && temp->next->data != val) temp = temp->next;
        if (temp->next == NULL) return;
        Node* t = temp->next;
        temp->next = temp->next->next;
        delete t;
    }

    void search(int val) {
        Node* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (temp->data == val) { cout << "Found at position: " << pos << "\n"; return; }
            temp = temp->next;
            pos++;
        }
        cout << "Not Found\n";
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};
int main() {
    LinkedList l;
    int ch, x, y;
    while (1) {
        cout << "1-InsertBeg 2-InsertEnd 3-InsertBefore 4-InsertAfter 5-DelBeg 6-DelEnd 7-DelNode 8-Search 9-Display 10-Exit\n";
        cin >> ch;
        if (ch == 1) { cin >> x; l.insertBeg(x); }
        else if (ch == 2) { cin >> x; l.insertEnd(x); }
        else if (ch == 3) { cin >> y >> x; l.insertBefore(y, x); }
        else if (ch == 4) { cin >> y >> x; l.insertAfter(y, x); }
        else if (ch == 5) l.delBeg();
        else if (ch == 6) l.delEnd();
        else if (ch == 7) { cin >> x; l.delNode(x); }
        else if (ch == 8) { cin >> x; l.search(x); }
        else if (ch == 9) l.display();
        else break;
    }
}
