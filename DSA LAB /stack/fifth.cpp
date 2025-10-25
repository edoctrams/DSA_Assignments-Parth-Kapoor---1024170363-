#include<iostream>
#include<cmath>
using namespace std;
#define SIZE 100
class Stack {
    int arr[SIZE];
    int top;
public:
    Stack() { top = -1; }
    void push(int x) { arr[++top] = x; }
    int pop() { return arr[top--]; }
};
int main() {
    Stack s;
    char exp[100];
    cin >> exp;
    int i = 0;
    while (exp[i] != '\0') {
        char ch = exp[i];
        if (ch >= '0' && ch <= '9') s.push(ch - '0');
        else {
            int b = s.pop();
            int a = s.pop();
            int r;
            if (ch == '+') r = a + b;
            else if (ch == '-') r = a - b;
            else if (ch == '*') r = a * b;
            else if (ch == '/') r = a / b;
            else if (ch == '^') r = pow(a, b);
            s.push(r);
        }
        i++;
    }
    cout << s.pop();
}
