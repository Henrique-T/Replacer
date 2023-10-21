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

bool compareBlocksByReachCounter(const Block &a, const Block &b) {
	return a.getReachCounter() > b.getReachCounter();
};

void Algorithm::runAlgorithm(
	Table &_pageTable,
	Table &_frameTable,
	std::function<void(Block)> _moveFrameToDisk,
	std::function<Block(int)> _getFrameFromDisk,
	const std::string &_algorithm)
{

	/*
	* TODO: Organize counter for page faults
	* Will we need separate page faults for each algo? A: Nope, since we'll ran 3 different times, and the counter will be reset everytime
	* In theory, as it is always the same PT, we won't. But his example showed different numbers.
	*/
	int pageFaults = 0;

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

	std::vector<Block> frameTable; 

	for (std::size_t i = 0; i < references.size(); i++)
	{
		if (_pageTable.contains(references[i]))
		{
			std::cout << "Page found in FT!" << std::endl;
			std::size_t blockIndex = _pageTable.find(references[i]);
			std::cout << "Block " << _pageTable.at(blockIndex).getId() << "was gotten from FT" << std::endl;
		}
		else
		{
			std::cout << "Page fault!" << std::endl;
			pageFaults += 1;

			std::size_t blockIndex = _pageTable.find(references[i]);
			Block requestedBlock = _pageTable.at(blockIndex);

			if (_algorithm == "FIFO")
			{
				Block oldestBlockInFT = frameTable.at(0);
				oldestBlockInFT.setPresenceBit(0);

				frameTable.erase(frameTable.begin()); // Remove first block from frame table
			}
			else if (_algorithm == "LRU")
			{
				//Block leastRecentlyUsedBlockInFT = _frameTable.popFront(); // Wrong statement for LRU
			}
			else
			{
				_pageTable.recalculateReach(i, references);
				std::sort(frameTable.begin(), frameTable.end(), this->compareBlocksByReachCounter);

				Block blockWithLeastFutureReferencesInFT = frameTable.at(0); // We get the first block after reordering
				blockWithLeastFutureReferencesInFT.setPresenceBit(0);
				frameTable.erase(frameTable.begin());
			}

			frameTable.insert(frameTable.begin(), requestedBlock);
			requestedBlock.setPresenceBit(1);
		}
	}

	std::cout << _algorithm << pageFaults << std::endl;
}
