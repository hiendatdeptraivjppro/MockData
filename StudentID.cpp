#include <iostream>
#include <string>
#include <sstream>
#include "StudentID.h"
#include "IntegerGenerator.h"
using namespace std;

StudentIdGenerator::StudentIdGenerator() {
}

string StudentIdGenerator::next() {
	stringstream builder;
    auto intGen = IntegerGenerator::instance();
	int i = intGen->next(190000,220000);
	builder << "ID: " << i;
	string result = builder.str();
	return result;
}

