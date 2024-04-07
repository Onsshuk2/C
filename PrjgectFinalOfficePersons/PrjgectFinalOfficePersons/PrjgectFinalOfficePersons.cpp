#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define SIZE 5

struct contact
{
    int id;
    char firstName[50];
    char lastName[50];
    char phoneNumber[20];
    char email[50];
};

void Show(const contact& con)
{
    cout << "First Name: " << con.firstName << endl;
    cout << "Last Name: " << con.lastName << endl;
    cout << "Phone Number: " << con.phoneNumber << endl;
    cout << "Email: " << con.email << endl;
}

void SerchByName(const contact contacts[], int size, const char* name)
{
    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(contacts[i].firstName, name) == 0)
        {
            Show(contacts[i]);
            found = true;
        }
    }
    if (!found)
    {
        cout << "Contact not found" << endl;
    }
}

void ChangeData(contact contacts[], int size, int id)
{
    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (contacts[i].id == id)
        {
            Show(contacts[i]);
            cout << "Enter First Name: ";
            cin.getline(contacts[i].firstName, 50);
            cout << "Enter Last Name: ";
            cin.getline(contacts[i].lastName, 50);
            cout << "Enter Phone Number: ";
            cin.getline(contacts[i].phoneNumber, 20);
            cout << "Enter Email: ";
            cin.getline(contacts[i].email, 50);
            found = true;
            Show(contacts[i]);
        }
    }
    if (!found)
    {
        cout << "Contact not found" << endl;
    }
}

void SaveToFile(const contact contacts[], int size, const char* filename)
{
    ofstream file(filename);
    if (file.is_open())
    {
        for (int i = 0; i < size; i++)
        {
            file << contacts[i].id << endl;
            file << contacts[i].firstName << endl;
            file << contacts[i].lastName << endl;
            file << contacts[i].phoneNumber << endl;
            file << contacts[i].email << endl;
        }
    }
    else
    {
        cerr << "Error opening file " << endl;
        return;
    }
    file.close();
}

void LoadFromFile(contact contacts[], int& size, const char* filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error opening file " << endl;
        return;
    }
    else
    {
        size = 0;
        while (!file.eof())
        {
            file >> contacts[size].id;
            file.ignore();
            file.getline(contacts[size].firstName, 50);
            file.getline(contacts[size].lastName, 50);
            file.getline(contacts[size].phoneNumber, 20);
            file.getline(contacts[size].email, 50);
            size++;
        }
        file.close();
    }
}

int main()
{
    contact contacts[SIZE] = {
        {1, "John", "Doe", "123-456-7890", "john.doe@example.com"},
        {2, "Jane", "Smith", "987-654-3210", "jane.smith@example.com"},
        {3, "Alice", "Johnson", "555-555-5555", "alice.johnson@example.com"},
        {4, "Bob", "Brown", "111-222-3333", "bob.brown@example.com"},
        {5, "Emily", "Davis", "444-333-2222", "emily.davis@example.com"}
    };

    do
    {
        int choice;
        cout << "----------MENU----------" << endl;
        cout << "[1] -- Search by First Name" << endl;
        cout << "[2] -- Change Contact Data" << endl;
        cout << "[3] -- Save to File" << endl;
        cout << "[4] -- Load from File" << endl;
        cout << "[0] -- Exit" << endl;
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            char name[50];
            cout << "Enter First Name of Contact: ";
            cin.getline(name, 50);
            SerchByName(contacts, SIZE, name);
            break;
        }
        case 2:
        {
            int id;
            cout << "Enter Contact ID to Change Data: ";
            cin >> id;
            cin.ignore();
            ChangeData(contacts, SIZE, id);
            break;
        }
        case 3:
        {
            char filename[50];
            cout << "Enter Name for Your File: ";
            cin.getline(filename, 50);
            SaveToFile(contacts, SIZE, filename);
            break;
        }
        case 4:
        {
            char filename[50];
            int size;
            cout << "Enter Name of Your File: ";
            cin.getline(filename, 50);
            LoadFromFile(contacts, size, filename);
            break;
        }
        case 0:
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (true);
}
