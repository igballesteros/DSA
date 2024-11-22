#include "header.h"

Node* createNode() {
    Node* temp = new Node();
    int num = 0;

    std::cout << "Enter data for number (int): ";
    std::cin >> num;

    temp->data = num;
    temp->next = NULL;

    return temp;
}

void addNodeToList(Node** head, Node* temp) {

    Node* temp1 = *head;

    if (temp1 == NULL) {
        *head = temp;
        return;
    }
    else {
        while (temp1->next != NULL) {
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }
}

void printNodes(Node* head) {
    Node* temp = head;
    int position = 1;

    while (temp != NULL) {
        std::cout << "Postion: " << position << " - " << "Node data: " << temp->data << " Node address: " << temp << " Node pointer: " << temp->next << "\n";
        temp = temp->next;
        position++;
    }
    std::cout << "\n";
}

void addBeginning(Node** head, Node* temp) {
    Node* temp1 = *head;

    if (temp1 == NULL) {
        *head = temp;
    }
    else {
        temp->next = temp1;
        *head = temp;
    }
}

void addPosition(Node** head, Node* temp) {
    Node* temp1 = *head;
    int position;

    printNodes(*head);

    std::cout << "Choose a position: ";
    std::cin >> position;

    for (int i = 1; i < position - 1; i++) {
        temp1 = temp1->next;
    }

    temp->next = temp1->next;
    temp1->next = temp;

    printNodes(*head);
}

void deleteNode(Node** head) {
    Node* temp = *head;
    int position = 0;
    int num = 0;
    Node* del = NULL;

    while (temp != NULL) {
        temp = temp->next;
        num++;
    }

    temp = *head;

    std::cout << "Choose a node to be deleted: \n";
    printNodes(*head);
    std::cin >> position;

    if (position == 1) {
        del = temp;
        *head = temp->next;
        delete del;
    }
    else if (position > 1 && position < num) {
        for (int i = 1; i < position - 1; i++) {
            temp = temp->next;
        }

        del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }
    else {
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        del = temp->next;
        temp->next = NULL;
        delete del;
    }

    printNodes(*head);
}

void reverseList(Node** head) {
    Node* current = *head;
    Node* prev = nullptr;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void reverseRecursion(Node** head, Node* p) {
    if (p->next == NULL) {
        *head = p;
    }
    reverseRecursion(head, p->next);
    Node* q = p->next;
    q->next = p;
    p->next = nullptr;
}