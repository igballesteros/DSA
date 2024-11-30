#include <iostream>
#include <vector>

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

void addNodeToStack(Node** head, Node* temp) {
    Node* temp1 = *head;

    if (temp1 = nullptr) {
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
        std::cout << "The stack is empty.\n\n";
        return;
    }

    del = temp;
    *head = temp->next;
    delete del;
}

void displayStack(Node* head) {
    Node* temp = head;
    std::vector<int> v;

    if (temp == nullptr) {
        std::cout << "The stack is empty.\n\n";
        return;
    }

    while (temp->next != nullptr) {
        v.insert(v.begin(), temp->data);
        temp = temp->next;
    }

    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << "\n";
    }
}

int main() {

    Node* head = nullptr;
    Node* temp = nullptr;
    int option = 0;

    while (option > 4) {
        std::cout << "";
    }

}