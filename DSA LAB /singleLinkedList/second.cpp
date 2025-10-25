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
    int countAndDelete(int key) {
        int c = 0;
        while (head != NULL && head->data == key) {
            Node* t = head;
            head = head->next;
            delete t;
            c++;
        }
        Node* temp = head;
        while (temp != NULL && temp->next != NULL) {
            if (temp->next->data == key) {
                Node* t = temp->next;
                temp->next = t->next;
                delete t;
                c++;
            } else temp = temp->next;
        }
        return c;
    }
    void display() {
        Node* temp = head;
        while (temp != NULL) { cout << temp->data; if (temp->next) cout << "->"; temp = temp->next; }
        cout << "\n";
    }
};
int main() {
    LinkedList l;
    int n, x, key;
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> x; l.insertEnd(x); }
    cin >> key;
    int c = l.countAndDelete(key);
    cout << "Count: " << c << "\nUpdated Linked List: ";
    l.display();
}
