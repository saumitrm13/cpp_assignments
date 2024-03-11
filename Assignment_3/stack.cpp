#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int top;  
    int size; 

public:
    Stack(int stackSize = 5) {
        size = stackSize;
        arr = new int[size];
        top = -1; 
    }

    ~Stack() {
        delete[] arr;
    }

   
    void push(int value) {
        if (isFull()) {
            cout << "Stack overflow. Cannot push element.\n";
            return;
        }
        arr[++top] = value;
        cout << "Added " << value << " onto the stack.\n";
    }

    
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow. Cannot pop element.\n";
            return -1;
        }
        return arr[top--];
    }

    
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot peek.\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }

    void print() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    
    Stack myStack;

    
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    myStack.push(50);

    
    myStack.print();

    
    cout << "Top element: " << myStack.peek() << endl;

    
    cout << "Popped element: " << myStack.pop() << endl;
    cout << "Popped element: " << myStack.pop() << endl;

    
    myStack.print();

    return 0;
}