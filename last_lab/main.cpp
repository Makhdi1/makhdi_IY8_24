
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <unordered_set>
#include "Student.h"

using namespace std;

ostream& operator<<(ostream& out, const Student& s) {
    out << s.surname << " " << s.group << " " << s.average_grade;
    return out;
}

int main() {
    set<Student> studentSet;
    unordered_set<Student, StudentHasher> studentUnorderedSet;

    ifstream file("input.txt");
    if (!file) {
        cerr << "File not found" << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        istringstream iss(line);
        string surname, group;
        double grade;
        if (iss >> surname >> group >> grade) {
            Student s(surname, group, grade);
            studentSet.insert(s);
            studentUnorderedSet.insert(s);
        }
    }

    cout << "Set (sorted by surname):" << endl;
    for (const auto& s : studentSet) {
        cout << s << endl;
    }

    cout << "\nUnordered set:" << endl;
    for (const auto& s : studentUnorderedSet) {
        cout << s << endl;
    }

    return 0;
}