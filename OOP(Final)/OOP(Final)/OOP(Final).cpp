#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>  
using namespace std;

struct nameUser
{
    string name;
    string serName;
    int phoneNumber;
    nameUser() : name("no name"), serName("no surname"), phoneNumber(0) {}
    nameUser(string n, string s, int p) : name(n), serName(s), phoneNumber(p) {}
    void setInfo()
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter surname: ";
        cin >> serName;
        cout << "Enter phone number: ";
        cin >> phoneNumber;
    }

    string getInfoString() const
    {
        return name + " " + serName + " " + to_string(phoneNumber);
    }
};

class NewPost
{
    int number;
    string address;
    nameUser peopleInfo;
public:
    NewPost() : number(0), address("no address"), peopleInfo() {}
    NewPost(int num, string addr, nameUser pI) : number(num), address(addr), peopleInfo(pI) {}

    void setNumber(int num)
    {
        number = num;
    }

    void setAddress(string addr)
    {
        address = addr;
    }

    void setInfo(nameUser pI)
    {
        peopleInfo = pI;
    }

    int getNumber() const
    {
        return number;
    }

    string getAddress() const
    {
        return address;
    }

    nameUser getInfo() const
    {
        return peopleInfo;
    }

    virtual void writeToFile(ofstream& file) const
    {
        file << number << endl << address << endl << peopleInfo.name << endl << peopleInfo.serName << endl << peopleInfo.phoneNumber << endl;
    }

    virtual void display() const
    {
        cout << "Number: " << number << endl;
        cout << "Address: " << address << endl;
        cout << "User Info: " << peopleInfo.getInfoString() << endl;
    }
};

class TrackedPost : public NewPost
{
    string trackingNumber;
    string status;
public:
    TrackedPost() : NewPost(), trackingNumber("no tracking number"), status("no status") {}
    TrackedPost(int num, string addr, nameUser pI, string trackNum, string stat)
        : NewPost(num, addr, pI), trackingNumber(trackNum), status(stat) {}

    void setTrackingNumber(string trackNum)
    {
        trackingNumber = trackNum;
    }

    void setStatus(string stat)
    {
        status = stat;
    }

    string getTrackingNumber() const
    {
        return trackingNumber;
    }

    string getStatus() const
    {
        return status;
    }

    void writeToFile(ofstream& file) const override
    {
        NewPost::writeToFile(file);
        file << trackingNumber << endl << status << endl;
    }

    void display() const override
    {
        NewPost::display();
        cout << "Tracking Number: " << trackingNumber << endl;
        cout << "Status: " << status << endl;
    }
};

void loadPostsFromFile(vector<NewPost*>& posts, const string& filename) {
    ifstream file(filename);
    if (file) {
        int number;
        string address;
        string name, serName, trackingNumber, status;
        int phoneNumber;
        while (file >> number) {
            file.ignore();
            getline(file, address);
            getline(file, name);
            getline(file, serName);
            file >> phoneNumber;
            file.ignore();

            // Check if there is tracking information
            if (getline(file, trackingNumber) && getline(file, status)) {
                nameUser userInfo(name, serName, phoneNumber);
                posts.push_back(new TrackedPost(number, address, userInfo, trackingNumber, status));
            }
            else {
                // If no tracking information, push back a regular NewPost
                file.clear();  // Clear the error flag set by getline
                nameUser userInfo(name, serName, phoneNumber);
                posts.push_back(new NewPost(number, address, userInfo));
            }
        }
        file.close();
    }
    else {
        cerr << "Failed to open the file." << endl;
    }
}

void savePostsToFile(const vector<NewPost*>& posts, const string& filename)
{
    ofstream file(filename);
    if (file) {
        for (const auto& post : posts) {
            post->writeToFile(file);
        }
        file.close();
    }
    else
    {
        cerr << "Failed to open the file." << endl;
    }
}

void printFileToConsole(const string& filename)
{
    ifstream file(filename);
    if (file) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
    else {
        cerr << "Failed to open the file." << endl;
    }
}

void searchByName(const string& filename, const string& name)
{
    vector<NewPost*> posts;
    loadPostsFromFile(posts, filename);

    bool found = false;
    for (const auto& post : posts)
    {
        if (post->getInfo().name == name)
        {
            post->display();
            found = true;
        }
    }
    if (!found)
    {
        cout << "No parcels found for user with name " << endl;
        cout << "No parcels found for user with name " << name << "." << endl;
    }

    for (auto& post : posts) {
        delete post;
    }
}

void deletePostByNumber(vector<NewPost*>& posts, const string& filename, int number)
{
    bool found = false;
    for (auto it = posts.begin(); it != posts.end(); ++it)
    {
        if ((*it)->getNumber() == number)
        {
            delete* it;
            posts.erase(it);
            found = true;
            break;
        }
    }
    if (found)
    {
        savePostsToFile(posts, filename);
        cout << "Parcel with number " << number << " has been deleted." << endl;
    }
    else
    {
        cout << "Parcel with number " << number << " not found." << endl;
    }
}

void editPostByNumber(vector<NewPost*>& posts, const string& filename, int number)
{
    bool found = false;
    for (auto& post : posts)
    {
        if (post->getNumber() == number)
        {
            cout << "Editing parcel with number " << number << ":" << endl;

            cout << "Enter new address: ";
            string address;
            cin.ignore();
            getline(cin, address);
            post->setAddress(address);

            nameUser userInfo;
            userInfo.setInfo();
            post->setInfo(userInfo);

            if (TrackedPost* trackedPost = dynamic_cast<TrackedPost*>(post)) {
                cout << "Enter new tracking number: ";
                string trackingNumber;
                getline(cin, trackingNumber);
                trackedPost->setTrackingNumber(trackingNumber);

                cout << "Enter new status: ";
                string status;
                getline(cin, status);
                trackedPost->setStatus(status);
            }

            found = true;
            break;
        }
    }
    if (found)
    {
        savePostsToFile(posts, filename);
        cout << "Parcel with number " << number << " has been edited." << endl;
    }
    else
    {
        cout << "Parcel with number " << number << " not found." << endl;
    }
}

void sortPostsByNumber(vector<NewPost*>& posts)
{
    sort(posts.begin(), posts.end(), [](const NewPost* a, const NewPost* b) {
        return a->getNumber() < b->getNumber();
        });
}

void menu(vector<NewPost*>& posts)
{
    int choice;
    while (true) {
        cout << "Welcome to the New Post, what services are you interested in?" << endl;
        cout << "Menu: " << endl;
        cout << "1. Add parcel " << endl;
        cout << "2. Show all " << endl;
        cout << "3. Search by user of parcel " << endl;
        cout << "4. Search by number of parcel" << endl;
        cout << "5. Delete parcel by number" << endl;
        cout << "6. Edit parcel by number" << endl;
        cout << "7. Print file contents to console" << endl;
        cout << "8. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Is this a tracked parcel? (y/n): ";
            char isTracked;
            cin >> isTracked;

            int num;
            string address;
            nameUser userInfo;

            cout << "Enter number of post: ";
            cin >> num;

            cout << "Enter address: ";
            cin.ignore();
            getline(cin, address);

            userInfo.setInfo();

            if (isTracked == 'y' || isTracked == 'Y') {
                string trackingNumber, status;

                cout << "Enter tracking number: ";
                getline(cin, trackingNumber);

                cout << "Enter status: ";
                getline(cin, status);

                posts.push_back(new TrackedPost(num, address, userInfo, trackingNumber, status));
            }
            else {
                posts.push_back(new NewPost(num, address, userInfo));
            }

            sortPostsByNumber(posts);
            savePostsToFile(posts, "parcels.txt");

            break;
        }
        case 2:
        {
            for (const auto& post : posts) {
                post->display();
            }
            break;
        }
        case 3:
        {
            cout << "Enter the user's name to search: ";
            string name;
            cin >> name;
            searchByName("parcels.txt", name);
            break;
        }
        case 4:
        {
            cout << "Enter the number of the parcel to search: ";
            int num;
            cin >> num;
            bool found = false;
            for (const auto& post : posts) {
                if (post->getNumber() == num) {
                    post->display();
                    found = true;
                }
            }
            if (!found) {
                cout << "Parcel with number " << num << " not found." << endl;
            }
            break;
        }
        case 5:
        {
            cout << "Enter the number of the parcel to delete: ";
            int num;
            cin >> num;
            deletePostByNumber(posts, "parcels.txt", num);
            break;
        }
        case 6:
        {
            cout << "Enter the number of the parcel to edit: ";
            int num;
            cin >> num;
            editPostByNumber(posts, "parcels.txt", num);
            break;
        }
        case 7:
        {
            printFileToConsole("parcels.txt");
            break;
        }
        case 8:
        {
            for (auto& post : posts) {
                delete post;
            }
            return;
        }
        default:
            cout << "Invalid choice, please try again." << endl;
        }
    }
}

int main()
{
    vector<NewPost*> posts;
    loadPostsFromFile(posts, "parcels.txt");
    sortPostsByNumber(posts);
    menu(posts);
}

