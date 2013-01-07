#ifdef RANDOMROUTINE_UNIT_TEST
#include "RandomRoutine.h"
#include <iostream>
#include "Chromosome.h"
using namespace ga;

int main(int argc, char* argv[])
{
	auto seed = CreateRandomSeed();
	//auto rand = std::bind(std::uniform_int_distribution<int>(0, 1), std::mt19937(seed));
	auto rand = std::bind(std::uniform_int_distribution<int>(0, 1), std::mt19937(seed));
	/*
	auto chromosome = CreateRandomChromosome(10, ElementGenerator(rand));
	std::cout << chromosome << std::endl;

	double mutate_probability = 0.2;
	auto mutated_chromosome = 
		Mutate(chromosome, CreateRandomMutateDecider(mutate_probability, seed));
	std::cout << mutated_chromosome << std::endl;
    */

	auto chromosome_list = ChromosomeList::WrappedType();
	for(unsigned int i = 0; i < 101; ++i){
		chromosome_list.push_back(
			CreateRandomChromosome(10, ElementGenerator(std::ref(rand))));
	}
	
	std::cout << "src:" << chromosome_list.size() << std::endl;
	for(const auto& e : chromosome_list){
		std::cout << e << std::endl;;
	}

	auto divided_tuple = DivideRandomly(ChromosomeList(chromosome_list), seed);
	auto bigger = std::get<0>(divided_tuple)();
	std::cout << "bigger:" << bigger.size() << std::endl;
	for(auto e : bigger){
		std::cout << e << std::endl;;
	}
	auto smaller = std::get<1>(divided_tuple)();
	std::cout << "smaller:" <<  smaller.size() << std::endl;
	for(auto e : smaller){
		std::cout << e << std::endl;;
	}

    return 0;
}

#endif
