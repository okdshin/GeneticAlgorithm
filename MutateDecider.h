#pragma once
//MutateDecider:20121205
#include <iostream>
#include <functional>
#include "utility/TypeWrapper.h"
#include "IsMutate.h"

namespace ga
{

class MutateDeciderType{};
using MutateDecider = 
	utility::TypeWrapper<std::function<IsMutate ()>, MutateDeciderType>;

}

