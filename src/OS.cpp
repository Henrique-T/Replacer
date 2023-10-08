#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <bits/stdc++.h>
#include "OS.h"

OS::OS() {}
OS::~OS() {}

void OS::algorithm() {}

void OS::pushBackPageToPT(Block _page) {}
void OS::pushFrontPageToPT(Block _page) {}
Block OS::popBackPageFromPT(Block _page) {}
Block OS::popFrontPageFromPT(Block _page) {}

void OS::pushBackFrameToFT(Block _frame) {}
void OS::pushFrontFrameToFT(Block _frame) {}
Block OS::popBackFrameFromPT(Block _frame) {}
Block OS::popFrontFrameFromPT(Block _frame) {}

void OS::moveFrameToDisk(int _id) {}
Block OS::getFrameFromDisk(int _id) {}