#include<iostream>
using namespace std;
#define SIZE 100
class Stack {
    char arr[SIZE];
    int top;
public:
    Stack() { top = -1; }
    void push(char x) { arr[++top] = x; }
    char pop() { return arr[top--]; }
    char peek() { return arr[top]; }
    int isEmpty() { return top == -1; }
};
int prec(char ch) {
    if (ch == '^') return 3;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '+' || ch == '-') return 1;
    return 0;
}
int main() {
    Stack s;
    char infix[100], postfix[100];
    cin >> infix;
    int i = 0, k = 0;
    while (infix[i] != '\0') {
        char ch = infix[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
            postfix[k++] = ch;
        else if (ch == '(') s.push(ch);
        else if (ch == ')') {
            while (!s.isEmpty() && s.peek() != '(') postfix[k++] = s.pop();
            s.pop();
        }
        else {
            while (!s.isEmpty() && prec(ch) <= prec(s.peek())) postfix[k++] = s.pop();
            s.push(ch);
        }
        i++;
    }
    while (!s.isEmpty()) postfix[k++] = s.pop();
    postfix[k] = '\0';
    cout << postfix;
}
