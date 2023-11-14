#include <iostream>
#include <conio.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int value)
    {
        data=value;
        next=NULL;
    }
};
class LinkedList {
private:
    Node* head;
public:
    LinkedList()
    {
        head=NULL;
    }
    void insertAtStart(int data)
    {
        Node* newNode=new Node(data);
        newNode->next=head;
        head=newNode;
    }
    void insertAtPoint(int position, int data)
    {
        if (position==0)
		{
            insertAtStart(data);
            return;
        }
        Node* newNode=new Node(data);
        Node* current=head;
        for (int i=0;i<position-1;++i)
		{
            if (current==NULL)
			{
                cout<<"Position out of bounds."<<endl;
                return;
            }
            current=current->next;
        }
        newNode->next=current->next;
        current->next=newNode;
    }
    void deleteFromStart()
    {
        if (head==NULL)
		{
            cout<<"List is empty. Cannot delete from the beginning."<<endl;
            return;
        }
        Node* temp=head;
        head=head->next;
        delete temp;
    }
    void deleteFromEnd()
    {
        if (head==NULL)
        {
            cout<<"List is empty. Cannot delete from the end."<<endl;
            return;
        }
        if (head->next==NULL)
        {
            delete head;
            head=NULL;
            return;
        }
        Node* current=head;
        while (current->next->next!=NULL)
        {
            current=current->next;
        }
        delete current->next;
        current->next=NULL;
    }
    void deleteAtPoint(int position)
    {
        if (head==NULL)
        {
            cout<<"List is empty. Cannot delete from the position."<<endl;
            return;
        }
        if (position==0)
        {
            deleteFromStart();
            return;
        }
        Node* current=head;
        for (int i=0;i<position-1;++i)
        {
            if (current==NULL || current->next==NULL)
            {
                cout<<"Position out of bounds."<<endl;
                return;
            }
            current=current->next;
        }
        Node* temp=current->next;
        current->next=current->next->next;
        delete temp;
    }
    void search(int searchData)
    {
        Node* current=head;
        while (current!=NULL)
        {
            if (current->data==searchData)
            {
                cout<<"Data found: "<<current->data<<endl;
                return;
            }
            current=current->next;
        }
        cout<<"Data not found."<<endl;
    }
    void update(int searchData, int newData)
    {
        Node* current=head;
        while (current!=NULL)
        {
            if (current->data==searchData)
            {
                current->data=newData;
                cout<<"Data updated successfully."<<endl;
                return;
            }
            current=current->next;
        }
        cout<<"Data not found."<<endl;
    }
    void display()
    {
        Node* current=head;
        while (current!=NULL)
        {
            cout<<current->data<<" ";
            current=current->next;
        }
        cout<<endl;
    }
};
int main()
{
    int choice,position,data,searchData,newData;
	LinkedList List;
    List.insertAtStart(25);
    List.insertAtStart(20);
    List.insertAtStart(15);
    List.insertAtStart(10);
    List.insertAtStart(5);
    do {
    	system("CLS");
    	cout<<"Original List: ";
    	List.display();
        cout << "\nMenu:"<<endl;
        cout << "1. Insert at Start"<<endl;
        cout << "2. Insert at Position"<<endl;
        cout << "3. Delete from Start"<<endl;
        cout << "4. Delete from End"<<endl;
        cout << "5. Delete at Position"<<endl;
        cout << "6. Search"<<endl;
        cout << "7. Update"<<endl;
        cout << "8. Display"<<endl;
        cout << "9. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;
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
                getch();
                break;
            case 7:
                cout<<"Enter number to update: ";
                cin>>searchData;
                cout<<"Enter new data: ";
                cin>>newData;
                List.update(searchData, newData);
                break;
            case 8:
                cout << "Current List: ";
                List.display();
				getch();
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