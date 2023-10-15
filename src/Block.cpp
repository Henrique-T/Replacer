#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <bits/stdc++.h>
#include "Block.h"

Block::Block() {}

Block::Block(int _id, std::string _kind)
{
	id = _id;
	kind = _kind;
	presence = 0;
	addressInFT = "";
	counter = 0;
}

Block::~Block() {}

int Block::getId()
{
	return id;
}

bool Block::isBlockPresent()
{
	return presence == 1;
}

std::string Block::getKind()
{
	return kind;
}

std::string Block::getAddressInFT() { return addressInFT; }
void Block::setAddressInFT(std::string &_address) { addressInFT = _address; }

int Block::getCounter() { return counter; }
int Block::incrementCounter(int _increment) { counter = counter + _increment; }