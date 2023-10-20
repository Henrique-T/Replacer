#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <functional>
#include <bits/stdc++.h>
#include "Algorithm.h"

using namespace std;

Algorithm::Algorithm() {}

Algorithm::~Algorithm() {}

std::vector<std::string> &Algorithm::getReferences()
{
	return references;
}

void Algorithm::setReferences(std::vector<std::string> &_references)
{
	references = _references;
}

void Algorithm::runAlgorithm(
	Table &_pageTable,
	Table &_frameTable,
	std::function<void(Block)> _moveFrameToDisk,
	std::function<Block(int)> _getFrameFromDisk,
	const std::string &_algorithm)
{

	/*
	* TODO: Organize counter for page faults
	* Will we need separate page faults for each algo?
	* In theory, as it is always the same PT, we won't. But his example showed different numbers.
	*/
	int pageFaultsFIFO = 0;
	int pageFaultsLRU = 0;
	int pageFaultsOPT = 0;
	int frameQuantity = 0;
	int refQuantity = 0;

	// FIFO
	// For each reference in references
	// 1. try to find that reference in PT
	// 2. If found, go to FT to get the page
	// 3. If not found, print "PAGE FAULT"
	// 3.1 Get the first inserted page in FT and remove it.
	// 3.2 bring the requested page from disk and insert that into FT.
	// 3.3. Update PT mapping (meaning, set presence bits)

	// LRU
	// Each page has a counter.
	// Every clock interruption we update the counter -> page counter = page counter + presence bit.
	// For each reference in references
	// 1. try to find that reference in PT.
	// 2. if found, go to FT to get the page.
	// 3. if not found, print "PAGE FAULT".
	// 3.1 Get the page with the biggest counter in FT and remove it.
	// 3.2 bring the requested page from disk and insert that into FT.
	// 3.3 update PT mapping (meaning, set presence bits).
	// Should we apply aging????????

	// Optimal
	// For each page in PT
	// We lable the page according to how many refrerences it will have in the future.
	// For each reference in references
	// 1. try to find that reference in PT
	// 2. If found, go to FT to get the page
	// 3. If not found, print "PAGE FAULT"
	// 3.1 ?

	std::cout << _algorithm << std::endl;

	for (std::size_t i = 0; i < references.size(); i++)
	{
		if (_pageTable.contains(references[i]))
		{
			std::cout << "Page found in PT!" << std::endl;

			std::size_t blockIndex = _pageTable.find(references[i]);
			std::string address = _pageTable.at(blockIndex).getAddressInFT(); /* How to define position? */
			Block block = _frameTable.at(atoi(address.c_str()));
			std::cout << "Block " << block.getId() << "was gotten from FT" << std::endl;
		}
		else
		{
			std::cout << "Page fault!" << std::endl;
			pageFaultsFIFO += 1;

			if (_algorithm == "FIFO")
			{
				Block oldestBlockInFT = _frameTable.popFront();
				_moveFrameToDisk(oldestBlockInFT);
				Block requestedBlock = _getFrameFromDisk(atoi(references[i].c_str()));
				_frameTable.pushFront(requestedBlock);
			}
			else if (_algorithm == "LRU")
			{
				Block leastRecentlyUsedBlockInFT = _frameTable.popFront(); // Wrong statement for LRU
				_moveFrameToDisk(leastRecentlyUsedBlockInFT);
				Block requestedBlock = _getFrameFromDisk(atoi(references[i].c_str()));
				_frameTable.pushFront(requestedBlock); // Are we going to push front for this?
			}
			else
			{
				Block blockWithLeastFutureReferencesInFT = _frameTable.popFront(); // Is this the right statement for optimal?
				_moveFrameToDisk(blockWithLeastFutureReferencesInFT);
				Block requestedBlock = _getFrameFromDisk(atoi(references[i].c_str()));
				_frameTable.pushFront(requestedBlock); // Are we going to push front for this?
			}
		}
	}

	std::cout << frameQuantity << " quadros" << std::endl;
	std::cout << refQuantity << " refs" << std::endl;
	std::cout << "FIFO: " << pageFaultsFIFO << std::endl;
	std::cout << "LRU: " << pageFaultsLRU << std::endl;
	std::cout << "OPT: " << pageFaultsOPT << std::endl;
}
