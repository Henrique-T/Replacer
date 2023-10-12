#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <bits/stdc++.h>
#include <bits/stdc++.h>
#include "Algorithm.h"

Algorithm::Algorithm() {}

Algorithm::Algorithm(std::vector<std::string> &_references)
{
	references = _references;
}

Algorithm::~Algorithm() {}

std::vector<std::string> &Algorithm::getReferences()
{
	return references;
}
