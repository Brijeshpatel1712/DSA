#include <iostream>
using namespace std;

class Stack {
private:
    int top;
    int size;
    int *arr;

public:
    // Constructor
    Stack(int s) {
        size = s;
        top = -1;
        arr = new int[size];
    }

    // Push operation
    void push(int value) {
        if (top == size - 1) {
            cout << "Stack Overflow! Cannot push element." << endl;
        } else {
            top++;
            arr[top] = value;
            cout << value << " pushed into stack." << endl;
        }
    }

    // Pop operation
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow! Stack is empty." << endl;
        } else {
            cout << arr[top] << " popped from stack." << endl;
            top--;
        }
    }

    // Display top element
    void peek() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Top element is: " << arr[top] << endl;
        }
    }

    // Check if stack is empty
    void isEmpty() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack is not empty." << endl;
        }
    }

    // Display all elements
    void display() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int size, choice, value;

    cout << "Enter stack size: ";
    cin >> size;

    Stack s(size);

    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Check Empty\n5. Display\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                s.isEmpty();
                break;
            case 5:
                s.display();
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 6);

    return 0;
}