#include <iostream>
#include <string>
#include <sstream>
#include "IntegerGenerator.h"
#include "TelGenerator.h"
using namespace std;
TelGenerator::TelGenerator() {

}

string TelGenerator::next() {
	stringstream builder;
	auto intGen = IntegerGenerator::instance();
	int number1 = intGen->next(100, 999);
	int number2 = intGen->next(1000, 9999);

	string First[12] = { "086","096","097","098","032","033","034","035","036","037",
		"038","039" };
	int i = intGen->next() % 12;
	builder << First[i] << " " << number1 << number2;
	string result = builder.str();
	return result;
}