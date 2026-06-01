#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <functional>

class Student {
public:
    std::string surname;
    std::string group;
    double average_grade;

    Student() : average_grade(0.0) {}
    Student(const std::string& s, const std::string& g, double a)
     : surname(s), group(g), average_grade(a) {}

    bool operator<(const Student& other) const {
        return surname < other.surname;
    }

    bool operator==(const Student& other) const {
        return surname == other.surname &&
               group == other.group &&
               average_grade == other.average_grade;
    }
};

struct StudentHasher {
    std::hash<std::string> shash;
    std::hash<double> dhash;

    size_t operator()(const Student& s) const {
        const size_t coef = 11171;
        return coef * coef * shash(s.surname) +
               coef * shash(s.group) +
               dhash(s.average_grade);
    }
};

#endif