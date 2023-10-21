#ifndef FIFO_H
#define FIFO_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <functional>
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
public:
	FIFO();
	~FIFO();

	void run(Table &_pageTable);
};

#endif