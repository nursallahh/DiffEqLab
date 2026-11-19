#include <iostream>
#include "mathcore/expr/smoke.hpp"

int main() {
    std::cout << "DiffEqLab CLI ready: 2 + 3 = " << diffeqlab::add(2, 3) << "\n";
    return 0;
}