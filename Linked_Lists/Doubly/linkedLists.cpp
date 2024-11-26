#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;
};


Node* createNode() {
    Node* temp = new Node();
    temp->next = nullptr;
    temp->prev = nullptr;

    std::cout << "Enter data for node: ";
    std::cin >> temp->data;

    return temp;
}

void addNodeToList(Node** head, Node* temp) {
    Node* temp1 = *head;

    if (temp1 == nullptr) {
        *head = temp;
        return;
    }
    else {
        while (temp1->next != nullptr) {
            temp1 = temp1->next;
        }
        temp1->next = temp;
        temp->prev = temp1;
    }
}

void printNodes(Node** head) {
    Node* temp = *head;
    int position = 1;

    while (temp != nullptr) {
        std::cout << "Position: " << position << " data: " << temp->data << " ad: " << temp << " prev: " << temp->prev << " next: " << temp->next << "\n";
        temp = temp->next;
        position++;
    }
}

void addBeginning(Node** head, Node* temp) {
    Node* temp1 = *head;

    if (*head == nullptr) {
        *head = temp;
    }
    else {
        temp->next = temp1;
        temp1->prev = temp;
        *head = temp;
    }
}

void addPosition(Node** head, Node* temp) {
    Node* temp1 = *head;
    int position = 0;
    int count = 0;

    while (temp1 != nullptr) {
        temp1 = temp1->next;
        count++;
    }

    temp1 = *head;

    if (temp1 == nullptr) {
        *head = temp;
    }

    printNodes(head);

    std::cout << "Choose a position: ";
    std::cin >> position;

    if (position == 1) {
        temp->next = temp1;
        temp1->prev = temp;
        *head = temp;
    }
    else if (position > 1 && position <= count) {
        for (int i = 1; i < position - 1; i++) {
            temp1 = temp1->next;
        }
        temp->next = temp1->next->next;
        temp->prev = temp1;
        temp1->next = temp;
    }
    else {
        while (temp1->next != nullptr) {
            temp1 = temp1->next;
        }
        temp1->next = temp;
        temp->prev = temp1;
    }
    printNodes(head);
}

void deleteNode(Node** head) {
    Node* temp = *head;
    Node* del = nullptr;
    int position = 0;
    int count = 0;

    while (temp != nullptr) {
        temp = temp->next;
        count++;
    }

    temp = *head;

    printNodes(head);
    std::cout << "Choose node to delete: ";
    std::cin >> position;

    if (position == 1) {
        del = temp;
        *head = temp->next;
        temp->next->prev = nullptr;
    }
    else if (position < count) {
        for (int i = 1; i < position - 1; i++) {
            temp = temp->next;
        }
        del = temp->next;
        temp->next = temp->next->next;
        temp->next->prev = temp;
    }
    printNodes(head);
}

int main() {

    Node* head = nullptr;
    Node* temp = nullptr;
    int option = 0;

    while (option < 6) {
        std::cout << "Option 1 - Create Node\n";
        std::cout << "Option 2 - Display Nodes\n";
        std::cout << "Option 3 - Add Node at the beginning\n";
        std::cout << "Option 4 - Add Node at nth position\n";
        std::cout << "Option 5 - Delete Node\n";
        // std::cout << "Option 6 - Reverse List\n";
        std::cout << "Exit - option > 5\n";

        std::cin >> option;

        if (option == 1) {
            int num = 0;
            std::cout << "Enter how many nodes do you want to create: ";
            std::cin >> num;

            for (int i = 0; i < num; i++) {
                temp = createNode();
                addNodeToList(&head, temp);
            }
        }
        else if (option == 2) {
            printNodes(&head);
        }
        else if (option == 3) {
            temp = createNode();
            addBeginning(&head, temp);
        }
        else if (option == 4) {
            temp = createNode();
            addPosition(&head, temp);
        }
        else if (option == 5) {
            deleteNode(&head);
        }
    }

}