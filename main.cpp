#include <iostream>
#include <fstream>
#include "IntegerGenerator.h"
#include "VnFullnameGenerator.h"
#include "StudentID.h"
#include "AddressGenerator.h"
#include "TelGenerator.h"
#include "BirthdayGenerator.h"
#include "Date.h"
#include "GPA.h"
#include "Email.h"
//forward declaration
class VnFullnameGenerator;
class StudentIdGenerator;
class Addressgenerator;
class TelGenerator;
class BirthdayGenerator;
class GPA;
class Email;
//
using namespace std;
void main() {
    VnFullnameGenerator name;
	StudentIdGenerator Id;
	AddressGenerator add;
	TelGenerator tel;
	BirthdayGenerator birth;
	GPA gba;
	Email email;
	fstream file;
	file.open("MockData.txt",ios::out);
	for (int i = 1; i <= 30; i++) {
		string fullname = name.next();
		string ID = Id.next();
		string address = add.next();
		string tele = tel.next();
		int currentYear = rand() % (2004-2000+1)+2000;
		Date dob = birth.next(currentYear);
		string score = gba.next();
		string e = email.next(fullname);
		cout << i << ". " << fullname << " - " << ID << " - " << address 
			<< " - " << tele << " - " << dob.toString() << " - " << score << " - " << e << endl;
		file << i << ". " << fullname << " - " << ID << " - " << address
			<< " - " << tele << " - " << dob.toString() << " - " << score << " - " << e << endl;
	}
	file.close();
}