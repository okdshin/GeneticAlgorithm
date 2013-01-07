#pragma once
//Chromosome:20121204
#include <iostream>
#include <cassert>
#include "Gene.h"
#include "ElementGenerator.h"
#include "MutateDecider.h"
#include "RecombinateGeneDecider.h"

namespace ga
{

class Chromosome{
public:
    Chromosome(const Gene& gene) : gene(gene){}

	auto GetGene() const -> Gene {
		return gene;	
	}

private:
	Gene gene;
};

inline
auto operator<<(std::ostream& os, const Chromosome& chromosome) -> std::ostream& {
	assert(!chromosome.GetGene().empty());
	os << "[" << chromosome.GetGene().front();
	for(unsigned int i=1; i < chromosome.GetGene().size(); ++i){
		os << "," << static_cast<int>(chromosome.GetGene().at(i));
	}
	os << "]";
	return os;	
}

inline
auto CreateChromosome(
		unsigned int length, 
		ElementGenerator generator) -> Chromosome {
	Gene gene;
	for(unsigned int i = 0; i < length; ++i){
		gene.push_back(generator()());
	}
	return Chromosome(gene);
}

inline
auto Mutate(
		const Chromosome& chromosome, 
		MutateDecider decider) -> Chromosome {
	auto gene = chromosome.GetGene();
	auto wrapped_decider = decider();
	for(auto& gene_element : gene){
		if(wrapped_decider()){
			gene_element = gene_element ? 0 : 1;
		}
	}
	return Chromosome(gene);

} 

inline
auto RecombinateGene(
		const Chromosome& left, 
		const Chromosome& right,
		RecombinateGeneDecider decider
			) -> std::tuple<Chromosome, Chromosome> {

	auto left_gene = left.GetGene();
	auto right_gene = right.GetGene();
	for(unsigned int i = 0; i < left_gene.size(); ++i){
		if(decider()()){
			auto new_left_gene = Gene();
			std::copy(left_gene.begin(), left_gene.begin()+i, std::back_inserter(new_left_gene));
			std::copy(right_gene.begin()+i, right_gene.end(), std::back_inserter(new_left_gene));
			auto new_right_gene = Gene();
			std::copy(right_gene.begin(), right_gene.begin()+i, std::back_inserter(new_right_gene));
			std::copy(left_gene.begin()+i, left_gene.end(), std::back_inserter(new_right_gene));
			left_gene = new_left_gene;
			right_gene = new_right_gene;
		}
	}
	return std::make_tuple(Chromosome(left_gene), Chromosome(right_gene));
}

}

