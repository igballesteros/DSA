#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node* createNode() {
    Node* temp = new Node();

    std::cout << "Enter data (int): ";
    std::cin >> temp->data;
    temp->next = nullptr;

    return temp;
}

void addNode(Node** head, Node* temp) {
    Node* temp1 = *head;

    if (*head == nullptr) {
        *head = temp;
    }
    else {
        while (temp1->next != nullptr) {
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }
}

void displayQueue(Node** head) {
    Node* temp = *head;
    int position = 1;

    while (temp != nullptr) {
        std::cout << "Position: " << position << "   ||   Data: " << temp->data << "\n";
        position++;
        temp = temp->next;
    }
    std::cout << "\n";
}

void removeNode(Node** head) {
    Node* temp = *head;
    *head = temp->next;
    delete(temp);
}

bool isEmpty(Node** head) {
    if (*head == nullptr) {
        return true;
    }
    return false;
}

void topElement(Node** head) {
    Node* temp = *head;

    std::cout << "The top of the queue is: " << temp->data << "\n\n";
}

int main() {

    Node* head = nullptr;
    Node* temp = nullptr;
    int option = 0;

    std::cout << "Welcome to the queue program (linked lists) - choose an option:\n";

    while (option < 6) {
        std::cout << "Option 1 - Add a number to the queue\n";
        std::cout << "Option 2 - Display the queue (beginning to end)\n";
        std::cout << "Option 3 - Remove a number from the queue\n";
        std::cout << "Option 4 - Check if queue is empty\n";
        std::cout << "Option 5 - Check front element\n";
        std::cout << "Option 6+ - Exit\n";

        std::cin >> option;

        if (option == 1) {
            int num = 0;
            std::cout << "How many numbers do you want to add to the queue?\n";
            std::cin >> num;

            for (int i = 0; i < num; i++) {
                temp = createNode();
                addNode(&head, temp);
            }
            std::cout << "\n";
        }
        else if (option == 2) {
            displayQueue(&head);
        }
        else if (option == 3) {
            removeNode(&head);
        }
        else if (option == 4) {
            if (isEmpty(&head)) {
                std::cout << "Queue is empty\n\n";
            }
            else {
                std::cout << "Queue is not empty\n\n";
            }
        }
        else if (option == 5) {
            topElement(&head);
        }

    }
}