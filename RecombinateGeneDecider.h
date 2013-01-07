#pragma once
//RecombinateGeneDecider:20121205
#include <iostream>
#include <functional>
#include "utility/TypeWrapper.h"
#include "IsRecombinateGene.h"

namespace ga
{

class RecombinateGeneDeciderType{};
using RecombinateGeneDecider = 
	utility::TypeWrapper<std::function<IsRecombinateGene ()>, RecombinateGeneDeciderType>;

}

