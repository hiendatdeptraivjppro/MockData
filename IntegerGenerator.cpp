#include "IntegerGenerator.h"
using namespace std;
IntegerGenerator::IntegerGenerator() {
    srand(time(NULL));
}

shared_ptr<IntegerGenerator> IntegerGenerator::instance() {
    if (_instance == NULL) {
        auto temp = new IntegerGenerator();
        _instance = shared_ptr<IntegerGenerator>(temp);
    }

    return _instance;
}

int IntegerGenerator::next() {
    return rand();
}

int IntegerGenerator::next(int left, int right) {
    int result = rand() % (right - left + 1) + left;
    return result;
}