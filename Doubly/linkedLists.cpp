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

    std::cout << "Enter data for node (int): ";
    std::cin >> temp->data;

    return temp;
}

void addNodeToList(Node** head, Node* temp) {
    Node* temp1 = *head;
}

int main() {

    createNode();

}