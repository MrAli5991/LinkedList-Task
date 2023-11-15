#include <iostream>
#include <conio.h>
using namespace std;
class Node {
public:
    int data; // Data stored in the node
    Node* next; // Pointer to the next node in the list
    Node(int value)
	{
        data = value;
        next = NULL;
    }
};
// LinkedList class represents a linked list
class LinkedList{
private:
    Node* head; // Pointer to the first node in the list
public:
    // Constructor to initialize an empty linked list
    LinkedList()
	{
        head = NULL;
    }
    // Function to insert a new node at the beginning of the list
    void insertAtStart(int data)
	{
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
    // Function to insert a new node at a specific position in the list
    void insertAtPoint(int position, int data)
	{
        if (position == 0)
		{
            // If the position is 0, insert at the beginning
            insertAtStart(data);
            return;
        }
        Node* newNode = new Node(data);
        Node* current = head;
        for (int i = 0; i < position - 1; ++i)
		{
            if (current == NULL)
			{
                cout << "Position out of bounds." << endl;
                return;
            }
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    // Function to delete the first node in the list
    void deleteFromStart()
	{
        if (head == NULL)
		{
            cout << "List is empty. Cannot delete from the beginning." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    // Function to delete the last node in the list
    void deleteFromEnd()
	{
        if (head == NULL)
		{
            cout << "List is empty. Cannot delete from the end." << endl;
            return;
        }
        if (head->next == NULL)
		{
            delete head;
            head = NULL;
            return;
        }
        Node* current = head;
        while (current->next->next != NULL)
		{
            current = current->next;
        }
        delete current->next;
        current->next = NULL;
    }
    // Function to delete a node at a specific position in the list
    void deleteAtPoint(int position)
	{
        if (head == NULL)
		{
            cout << "List is empty. Cannot delete from the position." << endl;
            return;
        }
        if (position == 0)
		{
            // If the position is 0, delete from the beginning
            deleteFromStart();
            return;
        }
        Node* current = head;
        for (int i = 0; i < position - 1; ++i)
		{
            if (current == NULL || current->next == NULL)
			{
                cout << "Position out of bounds." << endl;
                return;
            }
            current = current->next;
        }
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
    // Function to search for a specific data in the list
    void search(int searchData)
	{
        Node* current = head;
        while (current != NULL)
		{
            if (current->data == searchData)
			{
                cout << "Data found: " << current->data << endl;
                return;
            }
            current = current->next;
        }
        cout << "Data not found." << endl;
    }
    // Function to update the data of a node with a new value
    void update(int searchData, int newData)
	{
        Node* current = head;
        while (current != NULL)
		{
            if (current->data == searchData)
			{
                current->data = newData;
                cout << "Data updated successfully." << endl;
                return;
            }
            current = current->next;
        }
        cout << "Data not found." << endl;
    }
    // Function to display the elements in the list
    void display()
	{
        Node* current = head;
        while (current != NULL)
		{
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
int main()
{
    int choice, position, data, searchData, newData;
    LinkedList List;
    // Initial data insertion into the list
    List.insertAtStart(25);
    List.insertAtStart(20);
    List.insertAtStart(15);
    List.insertAtStart(10);
    List.insertAtStart(5);
    do {
        system("CLS"); // Clear the console screen
        cout << "Original List: ";
        List.display();
        cout << "\nMenu:" << endl;
        cout << "1. Insert at Start" << endl;
        cout << "2. Insert at Position" << endl;
        cout << "3. Delete from Start" << endl;
        cout << "4. Delete from End" << endl;
        cout << "5. Delete at Position" << endl;
        cout << "6. Search" << endl;
        cout << "7. Update" << endl;
        cout << "8. Display" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        // Switch case for different menu options
        switch (choice) {
            case 1:
                cout << "Enter data to insert at the start: ";
                cin >> data;
                List.insertAtStart(data);
                break;
            case 2:
                cout << "Enter position to insert data: ";
                cin >> position;
                cout << "Enter data to insert at position " << position << ": ";
                cin >> data;
                List.insertAtPoint(position, data);
                break;
            case 3:
                List.deleteFromStart();
                break;
            case 4:
                List.deleteFromEnd();
                break;
            case 5:
                cout << "Enter position to delete data: ";
                cin >> position;
                List.deleteAtPoint(position);
                break;
            case 6:
                cout << "Enter number to search: ";
                cin >> searchData;
                List.search(searchData);
                getch(); // Wait for a key press
                break;
            case 7:
                cout << "Enter number to update: ";
                cin >> searchData;
                cout << "Enter new data: ";
                cin >> newData;
                List.update(searchData, newData);
                break;
            case 8:
                cout << "Current List: ";
                List.display();
                getch(); // Wait for a key press
                break;
            case 9:
                cout << "Exiting the program. :)";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 9);
    return 0;
}