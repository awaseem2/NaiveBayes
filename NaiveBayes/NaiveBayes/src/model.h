#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>

using std::map;
using std::pair;
using std::endl;
using std::vector;
using std::string;


class Model
{
public:
	friend std::ostream& operator << (std::ostream& stream, const Model& model);


private:
	map<pair<int, int>, int> feature_map;

};