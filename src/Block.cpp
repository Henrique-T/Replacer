#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <bits/stdc++.h>
#include "Block.h"

Block::Block() {}

Block::Block(int _id)
{
	id = _id;
	presence = 0;
	counter = 1; // Starting counter as 1 in the constructor
}

Block::~Block() {}

int Block::getId() const
{
	return id;
}

bool Block::isBlockPresent()
{
	return presence == 1;
}

int Block::getCounter() { return counter; }
void Block::incrementCounter(int _increment) { counter = counter + _increment; }
int Block::getReachCounter() const { return this->reachCounter; }
void Block::setReachCounter(int &_value) { reachCounter = _value; }
void Block::setPresenceBit(const bool _bit) { presence = _bit; }