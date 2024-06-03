#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <sstream>

using namespace std;

struct Student {
    int id;
    string name;
    string email;

    bool operator<(const Student& other) const {
        return id < other.id;
    }

    bool operator==(const Student& other) const {
        return id == other.id;
    }
};

struct StudentHash {
    size_t operator()(const Student& student) const {
        return hash<int>()(student.id);
    }
};

class CourseManagementSystem {
private:
    multimap<string, Student> courseToStudents; 
    unordered_map<Student, multiset<int>, StudentHash> studentToGrades;
    unordered_set<Student, StudentHash> uniqueStudents;

    void saveToFile(const string& filename) const {
        ofstream file(filename);
        if (!file) {
            cerr << "Failed to open the file for writing." << endl;
            return;
        }

        for (const auto& entry : courseToStudents) {
            const string& course = entry.first;
            const Student& student = entry.second;
            const auto& grades = studentToGrades.at(student);
            for (int grade : grades) {
                file << course << "," << student.id << "," << student.name << "," << student.email << "," << grade << endl;
            }
        }

        file.close();
    }

public:
    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cerr << "Failed to open the file." << endl;
            return;
        }

        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string course;
            Student student;
            int grade;

            getline(ss, course, ',');
            ss >> student.id;
            ss.ignore(1, ',');
            getline(ss, student.name, ',');
            getline(ss, student.email, ',');
            ss >> grade;

            addStudentToCourse(course, student, grade);
        }

        file.close();
    }

    void addStudentToCourse(const string& course, const Student& student, int grade) {
        courseToStudents.insert({ course, student });
        studentToGrades[student].insert(grade);
        uniqueStudents.insert(student);
    }

    void updateStudentGrade(const Student& student, int oldGrade, int newGrade) {
        if (studentToGrades.find(student) != studentToGrades.end()) {
            auto& grades = studentToGrades[student];
            auto it = grades.find(oldGrade);
            if (it != grades.end()) {
                grades.erase(it);
                grades.insert(newGrade);
            }
            else {
                cout << "Old grade not found for the student." << endl;
            }
        }
        else {
            cout << "Student not found." << endl;
        }
    }

    void removeStudentFromCourse(const string& course, const Student& student) {
        auto range = courseToStudents.equal_range(course);
        for (auto it = range.first; it != range.second; ++it) {
            if (it->second == student) {
                courseToStudents.erase(it);
                break;
            }
        }

        if (studentToGrades.find(student) != studentToGrades.end()) {
            studentToGrades.erase(student);
        }

        uniqueStudents.erase(student);
    }

    void printCourses() const {
        for (const auto& course : courseToStudents) {
            cout << "Course: " << course.first << ", Student ID: " << course.second.id
                << ", Name: " << course.second.name << ", Email: " << course.second.email << endl;
        }
    }

    void printUniqueStudents() const {
        cout << "Unique Students:" << endl;
        for (const auto& student : uniqueStudents) {
            cout << "ID: " << student.id << ", Name: " << student.name << ", Email: " << student.email << endl;
        }
    }

    void printStudentsByGrades() const {
        multimap<int, Student, greater<int>> gradesToStudents; 

        for (const auto& pair : studentToGrades) {
            const Student& student = pair.first;
            for (int grade : pair.second) {
                gradesToStudents.insert({ grade, student });
            }
        }

        cout << "Students by Grades:" << endl;
        for (const auto& pair : gradesToStudents) {
            cout << "Grade: " << pair.first << ", Student ID: " << pair.second.id
                << ", Name: " << pair.second.name << ", Email: " << pair.second.email << endl;
        }
    }

    void inputStudentAndAddToCourse(const string& filename) {
        Student student;
        string course;
        int grade;

        cout << "Enter student ID: ";
        cin >> student.id;
        cin.ignore();
        cout << "Enter student name: ";
        getline(cin, student.name);
        cout << "Enter student email: ";
        getline(cin, student.email);
        cout << "Enter course name: ";
        getline(cin, course);
        cout << "Enter grade: ";
        cin >> grade;

        addStudentToCourse(course, student, grade);
        saveToFile(filename);  
    }
};

int main() {
    const string filename = "courses.txt";
    CourseManagementSystem cms;
    cms.loadFromFile(filename);

    cout << "Courses and Students:" << endl;
    cms.printCourses();

    cout << "\nAdding a new student to a course:" << endl;
    cms.inputStudentAndAddToCourse(filename);
    cms.printCourses();

    cout << "\nUpdating a student's grade:" << endl;
    Student updatedStudent{};
   
    cms.printStudentsByGrades();

    cout << "\nRemoving a student from a course:" << endl;
   cms.printCourses();

    cout << "\nUnique Students:" << endl;
    cms.printUniqueStudents();

    cout << "\nStudents by Grades:" << endl;
    cms.printStudentsByGrades();

    
}

