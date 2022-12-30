#include <string>
#include <sstream>
#include "IntegerGenerator.h"
#include "VnFullnameGenerator.h"
using namespace std;
VnFullnameGenerator::VnFullnameGenerator() {
}

string VnFullnameGenerator::next() {
    stringstream builder;

    string firsts[30] = {"Nguyen","Tran","Le","Pham","Huynh","Hoang","Vu","Vo","Phan",
        "Truong","Bui","Dang","Do","Ngo","Ho","Duong","Dinh","Ai","Bach","Ca","Chu",
        "Diep","Gia","Khu","Ly","La","Mai","Phung","Quang","Ton"};

    string middles[11] = {
        "Van", "Phuc", "Dang", "Ngoc", "Huu", "Quoc",
        "Thi", "Le", "Chau", "My", "Hong" };
    string lasts[11] = {
        "Quyen", "Canh", "Tuan", "Toan", "Loi",
        "Linh", "Tam", "Thuy", "Mai", "Lan","Dat"};

    auto intGen = IntegerGenerator::instance();
    int i = intGen->next() % 30;
    int j = intGen->next() % 11;
    int k = intGen->next() % 11;
    builder << firsts[i] << " " << middles[j] << " " << lasts[k];

    string result = builder.str();
    return result;
}