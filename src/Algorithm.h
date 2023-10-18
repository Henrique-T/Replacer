#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <functional>
#include <bits/stdc++.h>
#include "Table.h"
#include "Block.h"

/*
* Each Algorithm will have its own class, inhereting from this one.
* Each instance will receive a list of references and each algorithm will sort
* according to their needs.
*/
class Algorithm
{
private:
	std::vector<std::string> references;

public:
	Algorithm();
	~Algorithm();

	std::vector<std::string> &getReferences();
	void setReferences(std::vector<std::string> &_references);

	void runAlgorithm(
		Table pageTable, 
		Table frameTable, 
		std::function<void(Block)> moveFrameToDisk, 
		std::function<Block (int)> getFrameFromDisk,
		std::string algorithm
		);
};

#endif