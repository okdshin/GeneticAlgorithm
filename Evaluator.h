#pragma once
//Evaluator:20121205
#include <iostream>
#include "Chromosome.h"
#include "Fitness.h"

namespace ga
{
class EvaluatorType{};
using Evaluator = 
	utility::TypeWrapper<std::function<Fitness (const Chromosome&)>, EvaluatorType>;
}

