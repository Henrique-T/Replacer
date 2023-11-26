#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <bits/stdc++.h>
#include <functional>
#include "Algorithm.h"
#include "Table.h"
#include "Block.h"
#include "FIFO.h"
#include "OS.h"

FIFO::FIFO() {}

FIFO::~FIFO() {}

void FIFO::run(Table &_pageTable)
{
	runAlgorithm(
		_pageTable,
		"FIFO"
		// specific FIFO params
	);
}