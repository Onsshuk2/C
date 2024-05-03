#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node* prev;
    Node(int value, Node* next, Node* prev) : value{ value }, next{ next }, prev{ prev } {}
};

class List
{
    Node* head;
    Node* tail;
public:
    List() : head(nullptr), tail(nullptr) {}
    List(const initializer_list<int>& values) : head(nullptr), tail(nullptr)
    {
        for (int val : values)
        {
            AddToTail(val);
        }
    }

    void PrintAll() const
    {
        Node* current = head;
        while (current != nullptr)
        {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    void AddToHead(int value)
    {
        Node* newNode = new Node(value, head, nullptr);
        if (IsEmpty())
        {
            head = tail = newNode;
        }
        else
        {
            head->prev = newNode;
            head = newNode;
        }
    }

    void AddToTail(int value)
    {
        Node* newNode = new Node(value, nullptr, tail);
        if (IsEmpty())
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void DeleteByValue(int value)
    {
        Node* current = head;
        while (current != nullptr)
        {
            if (current->value == value)
            {
                if (current == head)
                {
                    head = current->next;
                    if (head != nullptr)
                        head->prev = nullptr;
                    delete current;
                    return;
                }
                else if (current == tail)
                {
                    tail = current->prev;
                    tail->next = nullptr;
                    delete current;
                    return;
                }
                else
                {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    delete current;
                    return;
                }
            }
            current = current->next;
        }
        cout << "Value not found!" << endl;
    }

    void RemoveDuplicates()
    {
        Node* current = head;
        while (current != nullptr)
        {
            Node* runner = current->next;
            while (runner != nullptr)
            {
                if (runner->value == current->value)
                {
                    
                    Node* temp = runner;
                    runner->prev->next = runner->next;
                    if (runner->next != nullptr)
                        runner->next->prev = runner->prev;
                    runner = runner->next;
                    delete temp;
                }
                else
                {
                    runner = runner->next;
                }
            }
            current = current->next;
        }
    }

    int FindMax() const {
        
        int maxVal = head->value;
        Node* current = head->next;
        while (current != nullptr) {
            if (current->value > maxVal) {
                maxVal = current->value;
            }
            current = current->next;
        }
        return maxVal;
    }

   
    int FindMin() const {
        
        int minVal = head->value;
        Node* current = head->next;
        while (current != nullptr) {
            if (current->value < minVal) {
                minVal = current->value;
            }
            current = current->next;
        }
        return minVal;
    }

    /*void ReversePrintAll() const
    {
        Node* current = tail;
        while (current != nullptr)
        {
            if (current->next != nullptr)
            {
                cout << current->value << " ";
            }
            current = current->prev;
        }
        cout << endl;
    }*/

    int operator[](int index) const
    {
        if (index < 0)
        {
            cout << "Index must be non-negative!" << endl;
            return -1;
        }

        Node* current = head;
        int count = 0;
        while (current != nullptr)
        {
            if (count == index)
            {
                return current->value;
            }
            current = current->next;
            count++;
        }

        cout << "Index out of range!" << endl;
        return -1;
    }


    bool IsEmpty() const
    {
        return head == nullptr;
    }

    ~List()
    {
        Node* current = head;
        while (current != nullptr)
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main()
{
    List list1;
    
    list1.AddToHead(104);
    list1.AddToHead(123);
    list1.AddToHead(231);
    list1.AddToHead(11);

    list1.AddToTail(111);
    list1.AddToTail(112);
    list1.AddToTail(113);
    list1.AddToTail(114);
    list1.AddToTail(112);
    list1.PrintAll();

    list1.DeleteByValue(111);
    list1.PrintAll();
    list1.DeleteByValue(1);
    list1.PrintAll();

    list1.RemoveDuplicates(); 
    list1.PrintAll();

    cout << list1.FindMax() << endl;
    cout << list1.FindMin() << endl;

    /*cout << "Reverse print: ";*/
  /*list1.ReversePrintAll();*/

  list1[2];
  list1.PrintAll();
    
}

