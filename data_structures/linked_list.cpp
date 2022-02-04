#include <iostream>

struct Node {
    Node(int value) 
    :   val{value}
    {

    }

    int val = -1;
    Node* next = nullptr;
};

void appendList(Node* head, int val)
{
    while(head->next) { /// not while(head)
        head = head->next;
    }

    Node* new_node = new Node(val);
    head->next = new_node;
}

void insertList(Node* head, int val, int insert_index)
{
    while(--insert_index) {
        if(head->next) {
            head = head->next;
        }
    }

    auto temp_node = head->next;

    Node* new_node = new Node(val);
    head->next = new_node;

    new_node->next = temp_node;
}

void printList(Node* head)
{
    while(head) {
        std::cout << head->val << ' ';
        head = head->next;
    }

    std::cout << std::endl;
}

int main()
{
    // Node* head = new Node(0, nullptr); /// why does not this work?
    Node* head = new Node(0);
    appendList(head, 1);
    appendList(head, 2);
    appendList(head, 3);
    appendList(head, 4);
    appendList(head, 5);
    appendList(head, 6);
    insertList(head, 111, 3);
    appendList(head, 7);
    appendList(head, 8);

    printList(head);
}