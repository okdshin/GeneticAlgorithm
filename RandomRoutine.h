#pragma once
//RandomRoutine:20121205
#include <iostream>
#include <random>
#include <cmath>
#include <tuple>
#include <algorithm>
#include "MutateDecider.h"
#include "ChromosomeList.h"

namespace ga
{
inline
auto CreateRandomSeed() -> std::seed_seq {
	std::random_device rnd;
	std::vector<std::uint32_t> v(10);
	std::generate(v.begin(), v.end(), std::ref(rnd));
	return std::seed_seq(v.begin(), v.end());
}

inline
auto CreateRandomIntFunctor(
		int min, int max, std::seed_seq seed) -> std::function<int ()> {
	return std::bind(std::uniform_int_distribution<int>(min, max), std::mt19937(seed));
}

inline 
auto CreateRandomMutateDecider(double probability, std::seed_seq& seed) -> MutateDecider {	
	auto rand = std::bind(std::uniform_real_distribution<double>(0.0, 1.0), 
		std::mt19937(seed));
	return MutateDecider([&rand, probability](){
			return IsMutate(rand() < probability);	
		});
}

inline 
auto CreateRandomRecombinateGeneDecider(double probability, std::seed_seq& seed) -> MutateDecider {	
	auto rand = std::bind(std::uniform_real_distribution<double>(0.0, 1.0), 
		std::mt19937(seed));
	return MutateDecider([&rand, probability](){
			return IsRecombinateGene(rand() < probability);	
		});
}

inline 
auto DivideRandomly(
		const ChromosomeList& chromosome_list, 
		std::seed_seq seed) -> std::tuple<ChromosomeList, ChromosomeList>{
	auto smaller_list = ChromosomeList::WrappedType();
	auto src_list = chromosome_list();
	auto half_size = static_cast<unsigned int>(src_list.size()/2);
	auto rand = CreateRandomIntFunctor(0, pow(2, 16), seed);
	for(unsigned int i = 0; i < half_size; ++i){
		auto index = static_cast<unsigned int>(rand()%src_list.size());
		smaller_list.push_back(src_list.at(index));
		src_list.erase(src_list.begin()+index);
	}
	return std::make_tuple(ChromosomeList(src_list), ChromosomeList(smaller_list));
}

}

