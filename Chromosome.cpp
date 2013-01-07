#ifdef CHROMOSOME_UNIT_TEST
#include "Chromosome.h"
#include "RandomRoutine.h"
#include "RecombinateGeneDecider.h"
#include <iostream>

using namespace ga;

int main(int argc, char* argv[])
{

	auto seed = CreateRandomSeed();
	auto rand = std::bind(std::uniform_int_distribution<int>(0, 1), std::mt19937(seed));
	unsigned int gene_length = 20;
	
	auto chromosome_left = ga::CreateChromosome(gene_length, ga::ElementGenerator(std::ref(rand)));
	auto chromosome_right = ga::CreateChromosome(gene_length, ga::ElementGenerator(std::ref(rand)));
	std::cout << chromosome_left << std::endl;
	std::cout << chromosome_right << std::endl;
	auto recombinate_gene_decider = CreateRandomRecombinateGeneDecider(0.1, seed);
	auto recombinated_gene_tuple = RecombinateGene(chromosome_left, chromosome_right, recombinate_gene_decider());
	std::cout << std::get<0>(recombinated_gene_tuple) << std::endl;
	std::cout << std::get<1>(recombinated_gene_tuple) << std::endl;
	return 0;
}

#endif
