#ifndef FIFO_H
#define FIFO_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <bits/stdc++.h>
#include "Algorithm.h"
#include "Table.h"
#include "Block.h"

/*
*
*/
class FIFO : public Algorithm
{
private:
	Table pageTable;
	Table frameTable;

public:
	FIFO();
	FIFO(std::vector<std::string> &_references);
	~FIFO();
	void runAlgorithm();
};

#endif