#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

class Station
{
    int numberTrain;
    string time;
    string place;
public:
    Station()
    {
        numberTrain = 0;
        time = "no time";
        place = "no place";
    }

    Station(int num, string t, string p)
    {
        numberTrain = num;
        time = t;
        place = p;
    }

    void setNumberTrain(int num) {
        numberTrain = num;
    }

    void setTime(string t) {
        time = t;
    }

    void setPlace(string p) {
        place = p;
    }

    int getNumberTrain()const {
        return numberTrain;
    }

    string getTime()const {
        return time;
    }

    string getPlace()const {
        return place;
    }

    void writeToFile(ofstream& file) const
    {
        file << numberTrain << " " << time << " " << place << endl;
    }

    void readFromFile(ifstream& file)
    {
        file >> numberTrain >> time >> place;
    }
};

void writeToFile(const vector<Station>& stations, const string& filename)
{
    ofstream file(filename, ios::app);
    if (!file)
    {
        cerr << "Failed to open the file." << endl;
        return;
    }

    for (const auto& station : stations)
    {
        station.writeToFile(file);
    }

    file.close();
}

void readFromFile(vector<Station>& stations, const string& filename)
{
    ifstream file(filename);
    if (!file)
    {
        cerr << "Failed to open the file." << endl;
        return;
    }

    Station station;
    while (file.peek() != EOF)
    {
        station.readFromFile(file);
        stations.push_back(station);
    }

    file.close();
}

void menu(vector <Station>& stations)
{
    int choice;
    while (true) {
        cout << "Menu: " << endl;
        cout << "1. Add train " << endl;
        cout << "2. Show all " << endl;
        cout << "3. Search by number of train" << endl;
        cout << "4. Search by time of train" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;

        switch (choice) {
        case 1: {
            Station station;

            cout << "Enter number of train: ";
            int num;
            cin >> num;
            station.setNumberTrain(num);

            cout << "Enter time (HH:MM): ";
            string time;
            cin >> time;
            station.setTime(time);

            cout << "Enter place: ";
            string place;
            cin >> place;
            station.setPlace(place);

            stations.push_back(station);

            ofstream file("trains.txt", ios::app);
            if (file)
            {
                station.writeToFile(file);
                file.close();
            }
            else
            {
                cerr << "Failed to open the file." << endl;
            }

            break;
        }
        case 2: {
            cout << "All trains:" << endl;
            for (const auto& s : stations)
            {
                cout << "Number of train: " << s.getNumberTrain() << endl;
                cout << "Time: " << s.getTime() << endl;
                cout << "Place: " << s.getPlace() << endl;
                cout << "------------------------" << endl;
            }
            break;
        }
        case 3: {
            int trainNumber;
            cout << "Enter number of train: ";
            cin >> trainNumber;

            bool found = false;
            for (const auto& s : stations) {
                if (s.getNumberTrain() == trainNumber) {
                    cout << "Number: " << s.getNumberTrain() << endl;
                    cout << "Time: " << s.getTime() << endl;
                    cout << "Place: " << s.getPlace() << endl;
                    cout << "------------------------" << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "No train found." << endl;
            }
            break;
        }
        case 4: {
            string trainTime;
            cout << "Enter time of train: ";
            cin >> trainTime;

            bool found = false;
            for (const auto& s : stations) {
                if (s.getTime() == trainTime) {
                    cout << "Number: " << s.getNumberTrain() << endl;
                    cout << "Time: " << s.getTime() << endl;
                    cout << "Place: " << s.getPlace() << endl;
                    cout << "------------------------" << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "No train found." << endl;
            }
            break;
        }
        case 5:
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

int main()
{
    vector<Station> stations;
    readFromFile(stations, "trains.txt");

    menu(stations);

    return 0;
}