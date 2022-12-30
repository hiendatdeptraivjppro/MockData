#include "BirthdayGenerator.h"
#include "IntegerGenerator.h"
using namespace std;

Date BirthdayGenerator::next(int year) {
    auto intGen = IntegerGenerator::instance();
    int month = intGen->next(1, 12);

    int maxDaysInMonth[] = { -1,
        31, 28, 31, 30, 31, 30, 31,
        31, 30, 31, 30, 31
    };

    if (Date::isLeapYear(year)) {
        maxDaysInMonth[2] = 29;
    }

    int day = intGen->next(1, maxDaysInMonth[month]);
    Date result(day, month, year);
    return result;
}

Date BirthdayGenerator::next() {
    const int MAX_AGE = 118;
    int currentYear = Date::Now().year();
    auto intGen = IntegerGenerator::instance();

    int year = intGen->next(1930, 2021);

    Date result = next(year);
    return result;
}