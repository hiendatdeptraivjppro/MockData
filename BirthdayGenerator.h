#pragma once
#include "Date.h"

class BirthdayGenerator {
public:
    Date next();
    Date next(int year);
};
