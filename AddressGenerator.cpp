#include <iostream>
#include <string>
#include <sstream>
#include "AddressGenerator.h"
#include "IntegerGenerator.h"
using namespace std;

AddressGenerator::AddressGenerator() {

}

string AddressGenerator::next() {
	stringstream builder;
	auto intGen = IntegerGenerator::instance();
	int number = intGen->next(100, 999);
	string district[5] = { "1","2", "3","4" ,"5" };

	string ward[8] = { "Tan Binh","Tan Phu","Ben Nghe","Cau Kho",
		"Co Giang","Thai Binh","Phu My","Bach Dang" };
	string street[5] = { "Vo Tru","Hong Bang","Dong Da","Le Loi",
	"Van Don" };
	int i = intGen->next() % 5;
	int j = intGen->next() % 8;
	int k = intGen->next() % 5;
	builder << number << " Street " << street[k] << " District " << district[i] << " Ward " << ward[j];
	string result = builder.str();
	return result;
}
