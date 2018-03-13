#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include<tuple>

using std::map;
using std::pair;
using std::endl;
using std::vector;
using std::string;
using std::tuple;


class Model
{
public:
	friend std::ostream& operator << (std::ostream& stream, const Model& model);
	void InitializeMaps(string images_file_name, string labels_file_name);
	map<tuple<int, int, int>, int> feature_frequency_map;
	map<int, int> class_frequency_map;


	

};