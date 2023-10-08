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
* Responsible for inserting and removing pages and frames of pages.
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

	void moveFrameToDisk(Block _block);
	Block getFrameFromDisk(int _id);
};

#endif