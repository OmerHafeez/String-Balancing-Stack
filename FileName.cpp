#include <iostream>
#include <string>
using namespace std;
class MyStack
{
private:
    char* arr;
    int top;
    int capacity;

public:
    MyStack()
    {
        capacity = 2; // Initial capacity
        arr = new char[capacity];
        top = -1;
    }

    ~MyStack()
    {
        delete[] arr;
    }

    void push(char c)
    {
        if (top == capacity - 1)
        {
            // Resize the array if it's full
            char* newArr = new char[capacity * 2];
            for (int i = 0; i < capacity; i++)
            {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
            capacity *= 2;
        }
        arr[++top] = c;
    }

    char pop()
    {
        if (!isEmpty())
        {
            return arr[top--];
        }
        return '\0';
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isBalanced(const string& expression)
    {
        for (int i = 0; i < expression.length(); i++)
        {
            char ch = expression[i];
            if (ch == '(' || ch == '[' || ch == '{')
            {
                push(ch);
            }
            else if (ch == ')' || ch == ']' || ch == '}')
            {
                if (isEmpty())
                {
                    return false;  // There's no matching opening bracket.
                }
                char top = pop();
                if ((ch == ')' && top != '(') ||
                    (ch == ']' && top != '[') ||
                    (ch == '}' && top != '{'))
                {
                    return false;  // Mismatched brackets.
                }
            }
        }

        return isEmpty();  // The stack should be empty if the expression is balanced.
    }

};



int main()
{
    MyStack stack;
    string balancedExpression = "{ [ 3 + ( 5 * 4 ) / (2 * 3)] + [ (2 * 2) + (9 * 1) ] }";
    string unbalancedExpression = "{ 3 + ( 5 * 4 ) / (2 * 3)] + [ (2 * 2 + (9 * 1) ] }";

    bool isBalanced1 = stack.isBalanced(balancedExpression);
    bool isBalanced2 = stack.isBalanced(unbalancedExpression);
    if (isBalanced1)
        cout << "Expression 1 is balanced " << endl;
    else
        cout << "Expression 1 is not balanced " << endl;
    if (isBalanced2)
        cout << "Expression 2 is balanced " << endl;
    else
        cout << "Expression 2 is not balanced " << endl;
    return 0;
}