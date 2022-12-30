#include <iostream>
#include "IntegerGenerator.h"
#include "VnFullnameGenerator.h"
#include "Email.h"
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

Email::Email() {

}

string Email::next(string fullname) {
	stringstream builder;
	auto intGen = IntegerGenerator::instance();
	int j = intGen->next() % 5;
	stringstream ss(fullname);
	string word;
	string a[3];
	string tail[5] = { "apple.com","microsoft.com","facebook.com","twitter.com","hcmus.edu.vn" };
	int i = 0;
	while (ss >> word) {
		a[i] = word;
		i++;
	}
	string first = a[0].substr(0, 1);
	string middle = a[1].substr(0, 1);
	transform(first.begin(), first.end(), first.begin(), ::tolower);
	transform(middle.begin(), middle.end(), middle.begin(), ::tolower);
	transform(a[2].begin(), a[2].end(), a[2].begin(), ::tolower);
	builder << first << middle << a[2] << "@" << tail[j];
	string result = builder.str();
	return result;
}
