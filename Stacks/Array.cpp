#include <iostream>

#define MAX_SIZE 50

void pop(int* top) {
    if (*top == -1) {
        std::cout << "Stack is empty\n";
        return;
    }
    *top -= 1;

}

void push(int* A, int* top) {
    if (*top >= MAX_SIZE - 1) {
        std::cout << "Stack is full\n";
        return;
    }

    int num = 0;

    std::cout << "Choose a number to go be pushed into the stack: ";
    std::cin >> num;

    *top += 1;
    A[*top] = num;
    std::cout << "\n";
}

bool isEmpty(int top) {
    if (top != -1) {
        return true;
    }
    return false;
}

int topElement(int* A, int top) {
    return A[top];
}

void printStack(int* A, int top) {
    std::cout << "Displaying the stack from top to bottom:\n";

    for (int i = top; i >= 0; i--) {
        std::cout << A[i] << "\n";
    }
    std::cout << "\n";
}

int main() {

    int A[MAX_SIZE];
    int top = -1;
    int option = 0;

    std::cout << "Welcome to the integer stack program - choose an option\n";

    while (option < 6) {
        std::cout << "Option 1 - Add a number to the stack\n";
        std::cout << "Option 2 - Display the stack (top to bottom)\n";
        std::cout << "Option 3 - Pop a number from the stack\n";
        std::cout << "Option 4 - Check if the stack is empty\n";
        std::cout << "Option 5 - Check top element\n";
        std::cout << "Exit > 5\n";

        std::cin >> option;

        if (option == 1) {
            int amount = 0;
            std::cout << "How many numbers do you want to add (max: 50): ";
            std::cin >> amount;

            for (int i = 0; i < amount; i++) {
                push(A, &top);
            }
        }

        else if (option == 2) {
            printStack(A, top);
        }

        else if (option == 3) {
            pop(&top);
        }

        else if (option == 4) {
            if (!isEmpty(top)) {
                std::cout << "Stack is empty\n\n";
            }
            else {
                std::cout << "Stack has elements\n\n";
            }
        }

        else if (option == 5) {
            int topNum = topElement(A, top);
            std::cout << "The top element is: " << topNum << "\n\n";
        }
    }

}