#include<iostream>
using namespace std;
#define SIZE 5
class Queue {
    int arr[SIZE];
    int front, rear;
public:
    Queue() { front = -1; rear = -1; }
    void enqueue(int x) {
        if (isFull()) cout << "Queue Full\n";
        else {
            if (front == -1) front = 0;
            rear++;
            arr[rear] = x;
        }
    }
    void dequeue() {
        if (isEmpty()) cout << "Queue Empty\n";
        else {
            cout << "Deleted: " << arr[front] << "\n";
            front++;
            if (front > rear) front = rear = -1;
        }
    }
    int isEmpty() { return front == -1; }
    int isFull() { return rear == SIZE - 1; }
    void display() {
        if (isEmpty()) cout << "Queue Empty\n";
        else for (int i = front; i <= rear; i++) cout << arr[i] << " ";
        cout << "\n";
    }
    void peek() {
        if (isEmpty()) cout << "Queue Empty\n";
        else cout << "Front: " << arr[front] << "\n";
    }
};
int main() {
    Queue q;
    int ch, val;
    while (1) {
        cout << "1-Enqueue 2-Dequeue 3-Display 4-Peek 5-Exit\n";
        cin >> ch;
        if (ch == 1) { cin >> val; q.enqueue(val); }
        else if (ch == 2) q.dequeue();
        else if (ch == 3) q.display();
        else if (ch == 4) q.peek();
        else break;
    }
}
