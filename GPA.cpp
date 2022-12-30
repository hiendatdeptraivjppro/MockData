#include "IntegerGenerator.h"
#include "GPA.h"
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

GPA::GPA() {

}


string GPA::next() {
	stringstream builder;
	auto intGen = IntegerGenerator::instance();
	float GPA = (float)intGen->next(7, 10) / (float)intGen->next(1, 5);
	builder << "GPA: " << setprecision(1) << fixed << GPA;
	string result = builder.str();
	return result;
}
