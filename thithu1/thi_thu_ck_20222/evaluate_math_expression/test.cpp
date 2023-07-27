#include <bits/stdc++.h>

using namespace std;

string addStrings(string num1, string num2) {
    int n = num1.size();
    int m = num2.size();

    // Đảm bảo num1 có độ dài lớn hơn hoặc bằng num2
    if (n < m) {
        swap(num1, num2);
        swap(n, m);
    }

    int carry = 0;
    string result = "";

    // Cộng từng chữ số từ phải sang trái
    for (int i = n - 1, j = m - 1; i >= 0; i--, j--) {
        int digit1 = num1[i] - '0';
        int digit2 = j >= 0 ? num2[j] - '0' : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        int digit = sum % 10;

        result.push_back(digit + '0');
    }

    // Nếu còn số dư carry, thêm vào kết quả
    if (carry > 0) {
        result.push_back(carry + '0');
    }

    // Đảo ngược chuỗi kết quả để có kết quả cuối cùng
    reverse(result.begin(), result.end());

    return result;
}

// Hàm tính tích của hai số nguyên lớn
string multiply(string num1, string num2) {
    long long n = num1.size();
    long long m = num2.size();
    vector<long long> result(n + m, 0);

    for (long long i = n - 1; i >= 0; i--) {
        for (long long j = m - 1; j >= 0; j--) {
            long long mul = (num1[i] - '0') * (num2[j] - '0');
            long long sum = result[i + j + 1] + mul;

            result[i + j] += sum / 10;
            result[i + j + 1] = sum % 10;
        }
    }

    string product = "";
    for (long long digit : result) {
        product += to_string(digit);
    }

    // Loại bỏ các số 0 không cần thiết ở đầu kết quả
    product =
        product.substr(min(product.find_first_not_of('0'), product.size() - 1));

    return product;
}

string calculate(string expression) {
    unordered_map<char, int> precedence;
    precedence['+'] = 1;
    precedence['*'] = 2;

    stack<char> operators;
    stack<string> operands;
    bool conti = false;
    for (char c : expression) {
        if (c >= '0' && c <= '9') {
            string tmp;
            if (conti) {
                tmp = operands.top();
                operands.pop();
            }
            tmp.push_back(c);
            operands.push(tmp);
            conti = true;
        } else if (c == '(') {
            conti = false;
            operators.push(c);
        } else if (c == ')') {
            conti = false;
            while (!operators.empty() && operators.top() != '(') {
                char op = operators.top();
                operators.pop();

                string operand2 = operands.top();
                operands.pop();
                string operand1 = operands.top();
                operands.pop();

                if (op == '+') {
                    operands.push(addStrings(operand1, operand2));
                } else if (op == '*') {
                    operands.push(multiply(operand1, operand2));
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

                string operand2 = operands.top();
                operands.pop();
                string operand1 = operands.top();
                operands.pop();

                if (op == '+') {
                    operands.push(addStrings(operand1, operand2));
                } else if (op == '*') {
                    operands.push(multiply(operand1, operand2));
                }
            }

            operators.push(c);
        }
    }

    while (!operators.empty()) {
        char op = operators.top();
        if (op == '(') {
            return "NOT_CORRECT";
        }
        operators.pop();

        string operand2 = operands.top();
        operands.pop();
        string operand1 = operands.top();
        operands.pop();

        if (op == '+') {
            operands.push(addStrings(operand1, operand2));
        } else if (op == '*') {
            operands.push(multiply(operand1, operand2));
        }
    }

    return operands.top();
}

string mod(string num) {
    long long divisor = 1000000007;
    long long result = 0;

    for (long long i = 0; i < num.size(); i++) {
        long long digit = num[i] - '0';
        result = (result * 10 + digit) % divisor;
    }

    return to_string(result);
}

int main() {
    freopen("test.inp", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string expression;
    getline(cin, expression);

    cout << mod(calculate(expression));

    return 0;
}