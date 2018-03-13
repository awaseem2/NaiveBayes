#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class LoadData
{

public:
	static vector<vector<int>> LoadFeatureVectors(string fileName);
	static vector<int> LoadLabelsVector(string file_name);

private:
	int GetTypeOfChar(char character);

};

