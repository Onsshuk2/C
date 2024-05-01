#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node* next;
    Node(int value, Node* next) : value{ value }, next{ next } {}
};

class List
{
    Node* head;

public:
    List() : head(nullptr) {}

   
    List(const List& other) : head(nullptr)
    {
        if (other.head == nullptr)
            return;

        
        Node* current = other.head;
        Node* newHead = new Node(current->value, nullptr);
        head = newHead;
        current = current->next;

        while (current != nullptr)
        {
            newHead->next = new Node(current->value, nullptr);
            newHead = newHead->next;
            current = current->next;
        }
    }

   
    List* Clone() const
    {
        return new List(*this); 
    }

    
    List* operator+(const List& other) const
    {
        List* result = new List(*this); 

        if (other.head == nullptr)
            return result;

        
        Node* current = other.head;
        Node* newHead = new Node(current->value, nullptr);
        result->head = newHead;
        current = current->next;

        while (current != nullptr)
        {
            newHead->next = new Node(current->value, nullptr);
            newHead = newHead->next;
            current = current->next;
        }

        return result;
    }

    
    List* operator*(const List& other) const
    {
        List* result = new List; 

        
        Node* current = head;
        while (current != nullptr)
        {
            
            if (other.Contains(current->value))
                result->AddToTail(current->value);

            current = current->next;
        }

        return result;
    }

    void AddToHead(int value)
    {
        Node* newNode = new Node(value, head);
        head = newNode;
    }

    void AddToTail(int value)
    {
        Node* newNode = new Node(value, nullptr);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node* current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void PrintList() const
    {
        Node* current = head;
        while (current != nullptr)
        {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    bool Contains(int value) const
    {
        Node* current = head;
        while (current != nullptr)
        {
            if (current->value == value)
                return true;
            current = current->next;
        }
        return false;
    }

    bool IsEmpty() const
    {
        return head == nullptr;
    }

    ~List()
    {
        while (head != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    srand(time(0));
    List list1, list2;
    for (int i = 0; i < 5; i++)
    {
        list1.AddToHead(rand() % 10);
        list2.AddToHead(rand() % 10);
    }

    cout << "List 1: ";
    list1.PrintList();

    cout << "List 2: ";
    list2.PrintList();

    List* cloneList1 = list1.Clone();
    cout << "Cloned List 1: ";
    cloneList1->PrintList();

    List* combinedList = (*cloneList1) + list2;
    cout << "Combined List: ";
    combinedList->PrintList();

    List* commonElementsList = (*cloneList1) * list2;
    cout << "Common Elements List: ";
    commonElementsList->PrintList();

    delete cloneList1;
    delete combinedList;
    delete commonElementsList;

}
