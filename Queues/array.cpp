#include <iostream>

#define MAX_SIZE 50

void enqueue(int* A, int* front, int* rear) {

    if (*rear == MAX_SIZE - 1) {
        std::cout << "Queue is full\n";
        return;
    }

    int insert = 0;

    std::cout << "\nHow many numbers do you want to add: ";
    std::cin >> insert;



    int nums = 0;

    if (*front == *rear) {
        *rear = 0;
        *front = 0;
        A[*rear] = nums;
    }

    for (int i = 0; i < insert; i++) {
        std::cout << "Enter the number you want to add: ";
        std::cin >> nums;
        A[*rear] = nums;
        *rear = *rear + 1;
    }
    std::cout << "\n";
}

void display(int* A, int front, int rear) {
    if (rear == -1) {
        std::cout << "Queue is empty\n\n";
        return;
    }

    std::cout << "\nDisplaying queue from beginning to end:\n";

    for (int i = front; i < rear; i++) {
        std::cout << A[i] << "\n";
    }
    std::cout << "\n";
}

void dequeue(int* A, int* front) {
    if (*front == -1) {
        std::cout << "Queue is empty\n\n";
    }

    *front = *front + 1;
    std::cout << "Number removed\n\n";
}

bool isEmpty(int* rear) {
    if (*rear == -1) {
        return true;
    }
    return false;
}

void topElement(int* A, int* front) {
    if (*front == -1) {
        std::cout << "The queue is empty\n\n";
    }
    else {
        std::cout << "The top of the queue is: " << A[*front] << "\n\n";
    }

}

int main() {

    int option = 0;
    int front = -1;
    int rear = -1;
    int A[MAX_SIZE] = {};

    std::cout << "Welcome to the queue program (array) - choose an option:\n";

    while (option < 6) {
        std::cout << "Option 1 - Add a number to the queue\n";
        std::cout << "Option 2 - Display the queue (beginning to end)\n";
        std::cout << "Option 3 - Remove a number from the queue\n";
        std::cout << "Option 4 - Check if queue is empty\n";
        std::cout << "Option 5 - Check front element\n";
        std::cout << "Option 6+ - Exit\n";

        std::cin >> option;

        if (option == 1) {
            enqueue(A, &front, &rear);
        }
        else if (option == 2) {
            display(A, front, rear);
        }
        else if (option == 3) {
            dequeue(A, &front);
        }
        else if (option == 4) {
            if (isEmpty(&rear)) {
                std::cout << "Queue is empty\n\n";
            }
            else {
                std::cout << "Queue has " << rear + 1 << " elements\n\n";
            }
        }
        else if (option == 5) {
            topElement(A, &front);
        }

    }
}