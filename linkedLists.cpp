#include <iostream>
#include <new>

struct Node {
    int data;
    Node* next;
};

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

int main() {

    Node* head = NULL;
    Node* temp = NULL;

    int option = 0;

    while (option < 6) {
        std::cout << "Option 1 - Create Node\n";
        std::cout << "Option 2 - Display Nodes\n";
        std::cout << "Option 3 - Add Node at the beginning\n";
        std::cout << "Option 4 - Add Node at nth position\n";
        std::cout << "Option 5 - Delete Node\n";
        std::cout << "Exit - option > 5\n";

        std::cin >> option;

        if (option == 1) {
            int num = 0;
            std::cout << "How many nodes do you want to add? ";
            std::cin >> num;

            for (int i = 0; i < num; i++) {
                temp = createNode();
                addNodeToList(&head, temp);
                std::cout << "Node added to list\n";
            }
            std::cout << "\n";
        }
        else if (option == 2) {
            printNodes(head);
        }
        else if (option == 3) {
            int num = 0;
            std::cout << "How many nodes do you want to add? ";
            std::cin >> num;

            for (int i = 0; i < num; i++) {
                temp = createNode();
                addBeginning(&head, temp);
                std::cout << "Node added to list\n";
            }
            std::cout << "\n";

        }
        else if (option == 4) {
            temp = createNode();
            addPosition(&head, temp);
        }
        else if (option == 5) {
            deleteNode(&head);
        }
    }

    std::cout << "End of program\n";

    return 0;

}