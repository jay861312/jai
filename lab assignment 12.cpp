#include <iostream>
#include <stdexcept>
#include <cctype> 
using namespace std;

class Stack {
    static const int max_size = 100;
    char items[max_size];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool is_empty() const {
        return top == -1;
    }

    bool is_full() const {
        return top == max_size - 1;
    }

    void push(char item) {
        if (is_full()) {
            throw overflow_error("Stack overflow: no element can be pushed");
        }
        items[++top] = item;
    }

    char pop() {
        if (is_empty()) {
            throw underflow_error("Stack underflow: stack is empty");
        }
        return items[top--];
    }

    char peek() const {
        if (is_empty()) {
            throw underflow_error("Stack underflow: stack is empty");
        }
        return items[top];
    }
};

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

bool is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void infix_to_postfix(const char* infix, char* postfix) {
    Stack operators;
    int j = 0; 

    for (int i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];

        if (isspace(token)) {
            continue; 
        } else if (isdigit(token)) {
            while (isdigit(infix[i])) {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' '; 
            i--; 
        } else if (is_operator(token)) {
            while (!operators.is_empty() && precedence(operators.peek()) >= precedence(token)) {
                postfix[j++] = operators.pop();
                postfix[j++] = ' ';
            }
            operators.push(token);
        } else if (token == '(') {
            operators.push('(');
        } else if (token == ')') {
            while (!operators.is_empty() && operators.peek() != '(') {
                postfix[j++] = operators.pop();
                postfix[j++] = ' ';
            }
            if (!operators.is_empty()) {
                operators.pop(); 
            }
        }
    }

    while (!operators.is_empty()) {
        postfix[j++] = operators.pop();
        postfix[j++] = ' ';
    }

    postfix[j] = '\0'; 
}

int main() {
    const int max_size = 100;
    char infix[max_size];
    char postfix[max_size];

    cout << "Enter infix expression (use spaces between numbers and operators): ";
    cin.getline(infix, max_size);

    infix_to_postfix(infix, postfix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
