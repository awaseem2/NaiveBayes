#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include<tuple>
#include <sstream>
#include <iterator>
#include <fstream>

using std::map;
using std::pair;
using std::endl;
using std::vector;
using std::string;
using std::tuple;


class Model
{
public:
	void InitializeMaps(string images_file_name, string labels_file_name);
	map<tuple<int, int, int>, int> feature_frequency_map;
	map<int, int> class_frequency_map;
	void LoadModel();
	void SaveModel();
private:
	friend std::ostream& operator << (std::ostream& stream, const Model& model);
	friend std::istream& operator >> (std::istream& stream, Model& model);
};