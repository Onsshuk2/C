#include <iostream>
#include <fstream>
using namespace std;

class Directory
{
    string companyName;
    string owner;
    int telephone;
    string address;
    string activity;
public:
    Directory():companyName("no name"), owner("no owner"), telephone(0), address("no address"), activity("no activity") {}
    Directory(string cName, string own, int tel, string addr, string act)
        : companyName(cName), owner(own), telephone(tel), address(addr), activity(act) {}
    
    string getCompanyName() const 
    {
        return companyName;
    }

    string getOwner() const
    {
        return owner;
    }

    int getTelephone() const
    {
        return telephone;
    }

    string getActivity() const
    {
        return activity;
    }

    void searchByCompanyName(const Directory directories[], int size, const string& name) {
        for (int i = 0; i < size; ++i) {
            if (directories[i].getCompanyName() == name) {
                cout << "Directory:" << endl;
                directories[i].Show();
                directories[i].saveToFile();
                return;
            }
        }
        cout << "No company name in dictionary: " << name << endl;
    }

    void searchByOwner(const Directory directories[], int size, const string& owner) {
        for (int i = 0; i < size; ++i) {
            if (directories[i].getOwner() == owner) {
                cout << "Directory:" << endl;
                directories[i].Show();
                directories[i].saveToFile();
                return;
            }
        }
        cout << "No owner in dictionary: " << owner << endl;
    }

    void searchByTelephone(const Directory directories[], int size, const int& telephone) {
        for (int i = 0; i < size; ++i) {
            if (directories[i].getTelephone() == telephone) {
                cout << "Directory:" << endl;
                directories[i].Show();
                directories[i].saveToFile();
                return;
            }
        }
        cout << "No telephone in dictionary: " << telephone << endl;
    }

    void searchByActivity(const Directory directories[], int size, const string& activity) {
        for (int i = 0; i < size; ++i) {
            if (directories[i].getActivity() == owner) {
                cout << "Directory:" << endl;
                directories[i].Show();
                directories[i].saveToFile();
                return;
            }
        }
        cout << "No activity in dictionary: " << owner << endl;
    }


   void Show() const {
        cout << "Company Name: " << companyName << endl;
        cout << "Owner: " << owner << endl;
        cout << "Telephone: " << telephone << endl;
        cout << "Address: " << address << endl;
        cout << "Activity: " << activity << endl;
    }

   void saveToFile()const
   {
       ofstream outF("dictionary.txt", ios_base::out);

       if (outF.is_open()) {
           outF << "Company Name: " << companyName << endl;
           outF << "Owner: " << owner << endl;
           outF << "Telephone: " << telephone << endl;
           outF << "Address: " << address << endl;
           outF << "Activity: " << activity << endl;
           outF.close();
       }
       else {
           cout << "Error" << endl;
       }
   }
};

int main()
{
    const int SIZE = 3;
    Directory directories[SIZE] = {
        Directory("SDF", "Ira", 680522042, "Zavodska Street 6/20", "Software Development"),
        Directory("Heppy Mall", "Misha", 689087650, "Shewchenko Street 4/9", "Teacher"),
        Directory("Hello Word", "Olga", 68067098, "Hrushevskogo Street", "Bakery")
    };

    
    string searchName;
    cout << "Enter the company name to search for: ";
    cin >> searchName;
    Directory d;
    d.searchByCompanyName(directories, SIZE, searchName);
   

    string searchOwner;
    cout << "Enter the owner to search for: ";
    cin >> searchOwner;
    Directory d1;
    d1.searchByOwner(directories, SIZE, searchOwner);
   

    int searchTelephone;
    cout << "Enter the telephone to search for: ";
    cin >> searchTelephone;
    Directory d2;
    d2.searchByTelephone(directories, SIZE, searchTelephone);
    

    string searchActivity;
    cout << "Enter the owner to search for: ";
    cin >> searchActivity;
    Directory d3;
    d3.searchByOwner(directories, SIZE, searchActivity);
    
    

}


