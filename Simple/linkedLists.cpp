#include "header.h"

// using namespace std: <- helps with printing

int main() {

    Node* head = NULL;
    Node* temp = NULL;

    int option = 0;

    while (option < 7) {
        std::cout << "Option 1 - Create Node\n";
        std::cout << "Option 2 - Display Nodes\n";
        std::cout << "Option 3 - Add Node at the beginning\n";
        std::cout << "Option 4 - Add Node at nth position\n";
        std::cout << "Option 5 - Delete Node\n";
        std::cout << "Option 6 - Reverse List\n";
        std::cout << "Exit - option > 6\n";

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
        else if (option == 6) {
            reverseList(&head);
        }
    }

    std::cout << "End of program\n";

    return 0;

}