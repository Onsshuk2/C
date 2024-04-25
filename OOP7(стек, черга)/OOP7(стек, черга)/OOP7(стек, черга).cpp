#include <iostream>
#include <stack>
#include <string>
using namespace std;


bool Stack(string str) {
    stack<char> s;

    for (char& c : str) {
        if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (s.empty()) {
                return false;
            }

            char top = s.top();
            if ((c == ')' && top == '(') || (c == ']' && top == '[') || (c == '}' && top == '{')) {
                s.pop();
            }
            else {
                return false; 
            }
        }
    }

    return s.empty(); 
}


int main()
{
    string str = "({x-y-z} * [x + 2y] - (z + 4x)).";
    if (Stack(str)) {
        cout << "Everything is correct" << endl;
    }
    else {
        cout << "It needs to be reworked" << endl;
    }

}


