#include<iostream>
using namespace std;
#define SIZE 100
class Queue {
    char arr[SIZE];
    int front, rear;
public:
    Queue() { front = -1; rear = -1; }
    void enqueue(char x) {
        if (rear == SIZE - 1) return;
        if (front == -1) front = 0;
        arr[++rear] = x;
    }
    void dequeue() {
        if (front == -1) return;
        front++;
        if (front > rear) front = rear = -1;
    }
    char frontChar() { return arr[front]; }
    int isEmpty() { return front == -1; }
};
int main() {
    Queue q;
    char s[100];
    int freq[256] = {0};
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        freq[s[i]]++;
        q.enqueue(s[i]);
        while (!q.isEmpty() && freq[q.frontChar()] > 1) q.dequeue();
        if (q.isEmpty()) cout << "-1 ";
        else cout << q.frontChar() << " ";
    }
}
