#include<iostream>
using namespace std;
#define SIZE 100
class Queue {
    int arr[SIZE];
    int front, rear;
public:
    Queue() { front = -1; rear = -1; }
    void enqueue(int x) {
        if (rear == SIZE - 1) return;
        if (front == -1) front = 0;
        arr[++rear] = x;
    }
    int dequeue() {
        if (front == -1) return -1;
        int x = arr[front++];
        if (front > rear) front = rear = -1;
        return x;
    }
    int size() { if (front == -1) return 0; return rear - front + 1; }
    int isEmpty() { return front == -1; }
};
class Stack {
    Queue q;
public:
    void push(int x) {
        int s = q.size();
        q.enqueue(x);
        for (int i = 0; i < s; i++) q.enqueue(q.dequeue());
    }
    void pop() {
        if (q.isEmpty()) cout << "Empty\n";
        else cout << "Popped: " << q.dequeue() << "\n";
    }
};
int main() {
    Stack s;
    int ch, val;
    while (1) {
        cout << "1-Push 2-Pop 3-Exit\n";
        cin >> ch;
        if (ch == 1) { cin >> val; s.push(val); }
        else if (ch == 2) s.pop();
        else break;
    }
}
