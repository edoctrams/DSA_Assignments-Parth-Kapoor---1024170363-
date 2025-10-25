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
    int size() {
        if (front == -1) return 0;
        return rear - front + 1;
    }
    void display() {
        for (int i = front; i <= rear; i++) cout << arr[i] << " ";
        cout << "\n";
    }
};
int main() {
    Queue q1, q2, q3;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        q1.enqueue(x);
    }
    int half = n / 2;
    for (int i = 0; i < half; i++) q2.enqueue(q1.dequeue());
    while (q2.size() && q1.size()) {
        q3.enqueue(q2.dequeue());
        q3.enqueue(q1.dequeue());
    }
    q3.display();
}
