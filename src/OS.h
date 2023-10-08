#ifndef OS_H
#define OS_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <bits/stdc++.h>
#include "Table.h"
#include "Block.h"

/*
* Represents the operating system.
* For now, the MMU is integrated in here. We are not sure if we'll keep this way.
* Responsible for inserting and removing pagesand frames of pages.
* FT = Frame Table; PT = Page Table
*/
class OS
{
private:
	Table pageTable;
	Table frameTable;
	std::vector<Block> disk;

public:
	OS();
	~OS();

	/* 
	* Generic method that receives parameters to decide what algorithm to use.
	* We are still unsure if this should be a separate class or not.	
	*/
	void algorithm();

	void pushBackPageToPT(Block _page);
	void pushFrontPageToPT(Block _page);
	Block popBackPageFromPT(Block _page);
	Block popFrontPageFromPT(Block _page);

	void pushBackFrameToFT(Block _frame);
	void pushFrontFrameToFT(Block _frame);
	Block popBackFrameFromPT(Block _frame);
	Block popFrontFrameFromPT(Block _frame);

	void moveFrameToDisk(int _id);
	Block getFrameFromDisk(int _id);
};

#endif