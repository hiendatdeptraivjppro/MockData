#include "Date.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
using namespace std;

Date::Date(int day, int month, int year) {
    this->_day = day;
    this->_month = month;
    this->_year = year;
}

Date::Date() {
    time_t info = time(NULL);
    tm now;
    localtime_s(&now, &info);

    _year = now.tm_year + 1900;
    _month = now.tm_mon + 1;
    _day = now.tm_mday;
}

bool Date::isLeapYear(int year) {
    bool result = (year % 400) ||
        ((year % 4 == 0) && (year % 100 != 0));
    return result;
}

string Date::toString() {
    stringstream builder;

    builder << setw(2) << setfill('0') << _day << "/"
        << setw(2) << setfill('0') << _month << "/" << _year;

    string result = builder.str();
    return result;
}