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
    char peek() { if (top == -1) return '\0'; return arr[top]; }
    int isEmpty() { return top == -1; }
};
int main() {
    Stack s;
    char exp[100];
    cin >> exp;
    int i = 0, flag = 1;
    while (exp[i] != '\0') {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') s.push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (s.isEmpty()) { flag = 0; break; }
            char ch = s.pop();
            if ((exp[i] == ')' && ch != '(') || (exp[i] == '}' && ch != '{') || (exp[i] == ']' && ch != '[')) {
                flag = 0; break;
            }
        }
        i++;
    }
    if (!s.isEmpty()) flag = 0;
    if (flag) cout << "Balanced";
    else cout << "Not Balanced";
}
