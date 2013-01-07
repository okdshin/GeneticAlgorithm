#pragma once
//ElementGenerator:20121205
#include <iostream>
#include <functional>
#include "utility/TypeWrapper.h"
#include "GeneElement.h"

namespace ga
{

class ElementGeneratorType{};
using ElementGenerator = 
	utility::TypeWrapper<std::function<GeneElement ()>, ElementGeneratorType>;

}

