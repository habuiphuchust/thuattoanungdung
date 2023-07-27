#include <bits/stdc++.h>

using namespace std;

long long calculate(string expression) {
    unordered_map<char, long long> precedence;
    precedence['+'] = 1;
    precedence['*'] = 2;

    stack<char> operators;
    stack<long long> operands;
    bool conti = false;
    for (char c : expression) {
        if (c >= '0' && c <= '9') {
            if (conti) {
                long long tmp = operands.top();
                operands.pop();
                operands.push(tmp * 10 + (c - '0'));
            } else
                operands.push(c - '0');
            conti = true;
        } else if (c == '(') {
            conti = false;
            operators.push(c);
        } else if (c == ')') {
            conti = false;
            while (!operators.empty() && operators.top() != '(') {
                char op = operators.top();
                operators.pop();

                long long operand2 = operands.top();
                operands.pop();
                long long operand1 = operands.top();
                operands.pop();

                if (op == '+') {
                    operands.push(operand1 + operand2);
                } else if (op == '*') {
                    operands.push(operand1 * operand2);
                }
            }

            // Loại bỏ dấu ngoặc mở
            operators.pop();
        } else if (c == '+' || c == '*') {
            conti = false;
            while (!operators.empty() && operators.top() != '(' &&
                   precedence[operators.top()] >= precedence[c]) {
                char op = operators.top();
                operators.pop();

                long long operand2 = operands.top();
                operands.pop();
                long long operand1 = operands.top();
                operands.pop();

                if (op == '+') {
                    operands.push(operand1 + operand2);
                } else if (op == '*') {
                    operands.push(operand1 * operand2);
                }
            }

            operators.push(c);
        }
    }

    while (!operators.empty()) {
        char op = operators.top();
        if (op == '(') {
            return -1;
        }
        operators.pop();

        long long operand2 = operands.top();
        operands.pop();
        long long operand1 = operands.top();
        operands.pop();

        if (op == '+') {
            operands.push(operand1 + operand2);
        } else if (op == '*') {
            operands.push(operand1 * operand2);
        }
    }

    return operands.top();
}

int main() {
    freopen("test.inp", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string expression;
    getline(cin, expression);

    long long result = calculate(expression);
    if (result == -1)
        cout << "NOT_CORRECT";
    else
        cout << result << endl;

    return 0;
}