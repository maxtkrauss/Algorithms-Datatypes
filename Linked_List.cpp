// Linked List

#include <iostream>
using namespace std;

// Making a Node STRUCT containing a data int and a pointer

struct Node {
    int data; // You can also templatize this
    Node* next;
};

class LinkedList
{
    Node* head; // Head pointer


public:
    LinkedList() // Initializing head pointer
    {
        head = NULL;
    }

    void insert(int val) // inserting elements (At start of the list)
    {
        Node* new_node = new Node; // make a new node
        new_node->data = val;
        new_node->next = NULL;

        if (head == NULL) // If list is empty, make the new node, the head
            head = new_node;

        else
        {
            new_node->next = head; // else, make the new_node the head and its next, the previous head
            head = new_node;
        }
    }

    bool search(int val) // loop over the list. return true if element found

    {
        Node* temp = head;
        while (temp != NULL)
        {
            if (temp->data == val)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void remove(int val)
    {
        if (head->data == val) // If the head is to be deleted
        {
            delete head;
            head = head->next;
            return;
        }

        if (head->next == NULL) // If there is only one element in the list
        {
            if (head->data == val) // If the head is to be deleted. Assign null to the head
            {
                delete head;
                head = NULL;
                return;
            }
            cout << "Value not found!" << endl; // else print, value not found
            return;
        }

        Node* temp = head; // Else loop over the list and search for the node to delete

        while (temp->next != NULL)
        {
            if (temp->next->data == val) // When node is found, delete the node and modify the pointers
            {
                Node* temp_ptr = temp->next->next;
                delete temp->next;
                temp->next = temp_ptr;
                return;
            }
            temp = temp->next;
        }
        cout << "Value not found" << endl; // Else, the value was never in the list
    }

    void display()
    {
        Node* temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {

    LinkedList L; // Making a list of Lucas Sequence
    L.insert(2);
    L.insert(1);
    L.insert(3);
    L.insert(4);
    L.insert(7);

    cout << "Current Linked List: ";
    L.display();

    cout << "Deleting 1: ";
    L.remove(1);
    L.display();

    cout << "Deleting 13: ";
    L.remove(13);

    cout << "Searching for 7: ";
    cout << L.search(7) << endl;

    cout << "Searching for 13: ";
    cout << L.search(13) << endl;
}