// Name: Arhan Thaker

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

const int MAX_SIZE = 4;
vector<string> Stack; // vector stack
string* top = nullptr; // Pointer to the top element
string* bottom = nullptr; // Pointer to the bottom element

void stackPointer() {
    if (Stack.empty()) {
        top = bottom = nullptr; // Stack is empty
    } else {
        bottom = &Stack.front(); // Points to the first element
        top = &Stack.back(); // Points to the last element
    }
}

void push(const string& digram) {
    if (Stack.size() >= MAX_SIZE) {
        cout << "STACK OVERFLOW" << endl;
    } else {
        Stack.push_back(digram);    // push
        stackPointer();     // update pointers
    }
}

string pop() {
    if (Stack.empty()) {        // check for empty stack
        return "";              // returns empty string
    }

    string top = Stack.back(); // access last element
    Stack.pop_back();
    stackPointer(); // update pointer
    return top; // return last element
}

bool validate(const string& digram) {
    if (digram.length() > 2) {
        return false;       // checks for digram grater than 2
    }
    for (char c : digram) {
        if (!isalpha(c) && !ispunct(c)) {       // checks if digram is alphabet or punctuation
            return false;
        }
    }
    return true;
}

string format(string digram) {
    string formated = "";
    for (char& c : digram) {        // converts punctuation to space
        if (ispunct(c)) {
            formated += ' ';
        } else {
            formated += c;       // else adds alphabet char
        }
    }

    if (formated.length() == 1) {       // if single char adds space
        formated += ' ';
    }
    return formated;
}

void display() {
    for (auto it = Stack.rbegin(); it != Stack.rend(); ++it) {
        cout << *it << endl;
    }
}

string toUpperCase(string digram) {
    for (char& c : digram) {
        c = toupper(c);
    }

    return digram;
}

int main() {
    while (true) {
        int input;
        cout << "Press 1 to PUSH \nPress 2 to POP \nPress 3 to DISPLAY \nPress any other key to EXIT." << endl;
        cin >> input;

        if (input == 1) {       // push
            string digram;
            cout << "Enter a digram: ";
            cin >> digram;

            if (validate(digram)) {     // validate
                string cleanDigram = format(digram);     // call clean
                push(toUpperCase(cleanDigram));     // uppercase
            } else {
                cout << "Invalid input. Please enter two alphabetic characters." << endl;
            }
        } else if (input == 2) {        // pop
            string popped = pop();
            if (!popped.empty()) {
                cout << "Popped: \"" << popped << "\"" << endl;
            } else {
                cout << "STACK UNDERFLOW" << endl;      // underflow
            }
        } else if (input == 3) {
            display();
        } else {
            cout << "Exited Program" << endl;
            break;      // exit
        }
    }

    return 0;
}
