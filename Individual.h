#pragma once
//Individual:20121204
#include <iostream>
#include "Chromosome.h"

namespace ga
{
class Individual{
public:
    Individual(){}
	auto GetChromosome() -> chromosome {
		return chromosome;	
	}

private:
	Chromosome chromosome;	

};

auto operator<<(std::ostream& os, const Individual& individual) -> std::ostream& {
	return os;	
}

}

