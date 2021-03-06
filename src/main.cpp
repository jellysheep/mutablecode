/**
 * \file
 * \author jellysheep, ClundXIII, edlervonhuber.
 * \section LICENSE
 * Copyright (c) 2014, jellysheep, ClundXIII, edlervonhuber.
 * All rights reserved.
 * This file is licensed under the "BSD 3-Clause License".
 * Full license text is under the file "LICENSE" provided with this code.
 */

#include <iostream>

#include "Mutator.hpp"
#include "StringEvaluator.hpp"

using namespace MutableCode;

int main(int argc, char *argv[])
{
	StringEvaluator evaluator("ABCDEF");
	Mutator mutator(&evaluator);
	mutator.runGeneticProgramming(2000);
	ProgramItem programItem = mutator.getBestProgramItem();
	std::cout<<"\nBest program:\t"<<programItem.program<<"\n";
	std::cout<<"Program input:\t'"<<mutator.getInput()<<"'\n";
	std::cout<<"Program output:\t'"<<programItem.output<<"'\n";
	std::cout<<"Program score:\t"<<programItem.score<<"\n";
	return 0;
}
