#include<iostream>
using namespace std;
#define SIZE 100
class Stack {
    char arr[SIZE];
    int top;
public:
    Stack() { top = -1; }
    void push(char x) { if (top < SIZE - 1) arr[++top] = x; }
    char pop() { if (top == -1) return '\0'; return arr[top--]; }
};
int main() {
    Stack s;
    char str[100];
    cin >> str;
    int i = 0;
    while (str[i] != '\0') { s.push(str[i]); i++; }
    while (i--) cout << s.pop();
}
