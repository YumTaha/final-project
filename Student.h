//
// Created by lithi on 14/06/2024.
//

#ifndef QUANTUMDINGLES_STUDENT_H
#define QUANTUMDINGLES_STUDENT_H

#include <string>
#include <sstream>
#include <ctime>
#include <utility>

using namespace std;

class Student {
private:
    string FirstName;
    string LastName;
    string MNumber;
    tm Birthday;
    double GPA;

public:
    Student(string  FirstName, string  LastName, string  MNumber, tm Birthday, double GPA = 0.0) :
            FirstName(std::move(FirstName)), LastName(std::move(LastName)), MNumber(std::move(MNumber)), Birthday(Birthday), GPA(GPA) {}

    string GetName() {return FirstName + " " + LastName;};
    string GetMNumber() {return MNumber;};

    [[nodiscard]] int GetAge() const {
        time_t now = time(nullptr);
        tm* currentTime = gmtime(&now);

        int currentMonth = currentTime -> tm_mon;
        int currentDay = currentTime -> tm_mday;
        int currentYear = currentTime -> tm_year + 1900;

        int month = Birthday.tm_mon;
        int day = Birthday.tm_mday;
        int year = Birthday.tm_year;

        int age = currentYear - year;
        if ((currentMonth < month) || currentMonth == month && currentDay < day) {age--;}

        return age;
    }

    bool operator>(const Student& otherStudent) const {return MNumber > otherStudent.MNumber;};
    bool operator<(const Student& otherStudent) const {return MNumber < otherStudent.MNumber;};
    bool operator==(const Student& otherStudent) const {return MNumber == otherStudent.MNumber;};




};

#endif //QUANTUMDINGLES_STUDENT_H
