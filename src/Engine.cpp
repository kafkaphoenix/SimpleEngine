#include "Engine.h"
#include <iostream>

namespace SimpleEngine {
    void Initialize() {
        std::cout << "SimpleEngine Initialized!" << std::endl;
    }

    void Shutdown() {
        std::cout << "SimpleEngine Shutdown!" << std::endl;
    }
}
