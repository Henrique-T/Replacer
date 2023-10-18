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

void FIFO::run(Table pageTable, Table frameTable, std::function<void(Block)> moveFrameToDisk, std::function<Block (int)> getFrameFromDisk) {
    runAlgorithm(
        pageTable, 
        frameTable,
        moveFrameToDisk,
        getFrameFromDisk,
        "FIFO"
        // specific FIFO params
    );
}