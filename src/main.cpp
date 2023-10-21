#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <bits/stdc++.h>
#include "Table.h"
#include "Block.h"
#include "OS.h"

using namespace std;

int main(int argc, char *argv[])
{
	int QTY_FRAMES = atoi(argv[1]);
	vector<string> references;

	/* Store input file data into vector references */
	for (std::string line; std::getline(std::cin, line);)
	{
		references.push_back(line);
	}

	/* Create OS instance and call algorithms */
	OS os(references, QTY_FRAMES);

	os.runFIFO();
	// os.runLRU();
	// os.runOptimal();

	return 0;
}