#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

bool isOperand(char ch) 
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

bool isOperator(char ch) 
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int getPrecedence(char op) 
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    return 0;
}

string infixToPostfix(const char* infix) 
{
    string postfix = "";
    stack<char> s;

    for (int i = 0; i < strlen(infix); ++i) 
    {
        if (isOperand(infix[i])) 
        {
            postfix += infix[i];
        } else if (infix[i] == '(') 
        {
            s.push('(');
        } 
        else if (infix[i] == ')') 
        {
            while (!s.empty() && s.top() != '(') 
            {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        } 
        else if (isOperator(infix[i])) 
        {
            while (!s.empty() && getPrecedence(infix[i]) <= getPrecedence(s.top())) 
            {
                postfix += s.top();
                s.pop();
            }
            s.push(infix[i]);
        }
    }

    while (!s.empty()) 
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int evaluatePostfix(const string& postfix) 
{
    stack<int> s;

    for (char ch : postfix) 
    {
        if (isOperand(ch)) 
        {
            s.push(ch - '0');
        } 
        else if (isOperator(ch)) 
        {
            int operand2 = s.top();
            s.pop();
            int operand1 = s.top();
            s.pop();

            switch (ch) 
            {
                case '+':
                    s.push(operand1 + operand2);
                    break;
                case '-':
                    s.push(operand1 - operand2);
                    break;
                case '*':
                    s.push(operand1 * operand2);
                    break;
                case '/':
                    s.push(operand1 / operand2);
                    break;
            }
        }
    }

    return s.top();
}

int main() 
{
    cout << "Enter an infix expression: ";
    string infixExpression;
    getline(cin, infixExpression);

    string postfixExpression = infixToPostfix(infixExpression.c_str());
    cout << "Postfix Expression: " << postfixExpression << endl;

    int result = evaluatePostfix(postfixExpression);
    cout << "Result of Evaluation: " << result << endl;

    return 0;
}
