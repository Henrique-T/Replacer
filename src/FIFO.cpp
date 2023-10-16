#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <bits/stdc++.h>
#include "Algorithm.h"
#include "Table.h"
#include "Block.h"
#include "FIFO.h"

FIFO::FIFO() {}

FIFO::~FIFO() {}

void FIFO::run(Table pageTable, Table frameTable) {
    runAlgorithm(
        pageTable, 
        frameTable
    );
}