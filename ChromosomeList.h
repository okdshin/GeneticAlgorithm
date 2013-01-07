#pragma once
//ChromosomeList:20121212
#include <iostream>
#include <vector>
#include "utility/TypeWrapper.h"
#include "Chromosome.h"

namespace ga
{
class ChromosomeListType{};
using ChromosomeList = utility::TypeWrapper<std::vector<Chromosome>, ChromosomeListType>;
}

