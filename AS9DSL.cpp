#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

const int max_size = 50;

class STACK 
{
private:
    char a[max_size];
    int top;

public:
    STACK() : top(-1) {}

    void push(char);
    void reverse();
    void convert(char[]);
    void palindrome();
};

void STACK::push(char c) 
{
    if (top < max_size - 1) 
    {
        top++;
        a[top] = c;

        cout << "\n" << c << " is pushed on the stack...";
    } 
    else 
    {
        cout << "\nStack Overflow: Cannot push " << c << ". Stack is full." << endl;
    }
}

void STACK::reverse() 
{
    cout << "\n\nReversed string is: ";

    for (int i = top; i >= 0; i--) 
    {
        cout << a[i];
    }

    cout << endl;
}

void STACK::convert(char str[]) 
{
    int len = strlen(str);
    int k = 0;

    for (int j = 0; j < len; j++) 
    {
        if (isalpha(str[j])) {
            str[k] = tolower(str[j]);
            k++;
        }
    }

    cout << "\nConverted String: ";
    for (int i = 0; i < k; i++) 
    {
        cout << str[i];
    }
    cout << "\n";
}

void STACK::palindrome() 
{
    cout << "\n\n";

    for (int i = top, j = 0; i >= 0; i--, j++) 
    {
        if (a[i] != a[j]) 
        {
            cout << "String is not a palindrome...";
            return;
        }
    }
    cout << "String is a palindrome...";
}

int main() 
{
    STACK stack;
    char str[max_size];

    cout << "\nEnter a string to be reversed and checked if it's a palindrome or not:\n\n";
    cin.getline(str, max_size);

    stack.convert(str);

    for (int i = 0; i < max_size && str[i] != '\0'; i++) 
    {
        stack.push(str[i]);
    }

    stack.palindrome();
    stack.reverse();

    return 0;
}
