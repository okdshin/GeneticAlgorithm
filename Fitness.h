#pragma once
//Fitness:20121205
#include <iostream>
#include "utility/TypeWrapper.h"

namespace ga
{
class FitnessType{};
using Fitness = utility::TypeWrapper<double, FitnessType>;

auto operator<<(std::ostream& os, const Fitness& fitness) -> std::ostream& {
	os << "Fitness: " << fitness();
	return os;
}
}

