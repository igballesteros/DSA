#pragma once

#include <iostream>
#include <new>

struct Node {
    int data;
    Node* next;
};

Node* createNode();

void addNodeToList(Node** head, Node* temp);

void printNodes(Node* head);

void addBeginning(Node** head, Node* temp);

void addPosition(Node** head, Node* temp);

void deleteNode(Node** head);

void reverseList(Node** head);

void reverseRecursion(Node** head, Node* ptr);