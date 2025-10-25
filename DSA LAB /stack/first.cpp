#include<iostream>
using namespace std;
#define SIZE 5
class Stack {
    int arr[SIZE];
    int top;
public:
    Stack() { top = -1; }
    void push(int x) {
        if (isFull()) cout << "Stack Full\n";
        else arr[++top] = x;
    }
    void pop() {
        if (isEmpty()) cout << "Stack Empty\n";
        else cout << "Popped: " << arr[top--] << "\n";
    }
    int isEmpty() { return top == -1; }
    int isFull() { return top == SIZE - 1; }
    void display() {
        if (isEmpty()) cout << "Stack Empty\n";
        else for (int i = top; i >= 0; i--) cout << arr[i] << " ";
        cout << "\n";
    }
    void peek() {
        if (isEmpty()) cout << "Stack Empty\n";
        else cout << "Top: " << arr[top] << "\n";
    }
};
int main() {
    Stack s;
    int ch, val;
    while (1) {
        cout << "1-Push 2-Pop 3-Display 4-Peek 5-Exit\n";
        cin >> ch;
        if (ch == 1) { cin >> val; s.push(val); }
        else if (ch == 2) s.pop();
        else if (ch == 3) s.display();
        else if (ch == 4) s.peek();
        else break;
    }
}
