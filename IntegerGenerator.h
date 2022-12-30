#pragma once
#include <iostream>
#include <memory>

class IntegerGenerator {
private:
    inline static std::shared_ptr<IntegerGenerator> _instance = NULL;

    IntegerGenerator();
public:
    static std::shared_ptr<IntegerGenerator> instance();

    int next();
    int next(int, int);
};