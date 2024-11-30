#include <iostream>
#include <vector>

struct Node {
    int data;
    Node* next;
};

void displayStack(Node* head) {
    Node* temp = head;
    int position = 1;

    while (temp != NULL) {
        std::cout << temp->data << "\n";
        temp = temp->next;
        position++;
    }
    std::cout << "\n";
}

Node* createNode() {
    Node* temp = new Node();

    std::cout << "Enter data (int): ";
    std::cin >> temp->data;

    temp->next = nullptr;

    return temp;
}

void addNodeToStack(Node** head, Node* temp) {
    Node* temp1 = *head;

    if (temp1 == nullptr) {
        *head = temp;
    }
    else {
        temp->next = temp1;
        *head = temp;
    }
}

void removeFromStack(Node** head) {
    Node* temp = *head;
    Node* del = nullptr;

    if (temp == nullptr) {
        std::cout << "The stack is empty.\n";
        return;
    }

    del = temp;
    *head = temp->next;
    delete del;
}

bool isEmpty(Node** head) {
    Node* temp = *head;

    if (temp == nullptr) {
        return true;
    }
    return false;
}

void Top(Node** head) {
    Node* temp = *head;

    if (temp == nullptr) {
        std::cout << "Stack is empty.\n";
    }
    else {
        std::cout << "The top element is: " << temp->data << "\n";
    }
}

int main() {

    Node* head = nullptr;
    Node* temp = nullptr;
    int option = 0;

    std::cout << "Welcome to the integer stack (linked list)!\n";
    std::cout << "Choose an option to continue:\n";

    while (option < 6) {
        std::cout << "Option 1 - Add a number to the stack\n";
        std::cout << "Option 2 - Display the stack (top to bottom)\n";
        std::cout << "Option 3 - Pop a number from the stack\n";
        std::cout << "Option 4 - Check if the stack is empty\n";
        std::cout << "Option 5 - Check top element\n";
        std::cout << "Exit > 5\n";

        std::cout << "Choose an option: ";
        std::cin >> option;

        if (option == 1) {
            int num = 0;
            std::cout << "How many numbers do you want to add: \n";
            std::cin >> num;

            for (int i = 0; i < num; i++) {
                temp = createNode();
                addNodeToStack(&head, temp);
            }
            std::cout << "\n";
        }
        else if (option == 2) {
            displayStack(head);
        }
        else if (option == 3) {
            removeFromStack(&head);
            displayStack(head);
        }
        else if (option == 4) {
            if (isEmpty(&head)) {
                std::cout << "Stack is empty.\n";
            }
            else {
                std::cout << "Stack is not empty.\n";
            }
        }
        else if (option == 5) {

        }
    }

}