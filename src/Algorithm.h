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

	static bool compareBlocksByReachCounter(Block &a, Block &b);

	void runAlgorithm(
		Table &_pageTable,
		const std::string &algorithm);
};

#endif