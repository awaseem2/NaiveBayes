#pragma once
#include "model.h"
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>

using std::vector;
using std::map;

class ClassifyData
{
public:
	Model model;
	int ClassOfImage(vector<int> image);
	void InitializeModel(string images_file_name, string labels_file_name);
	vector<int> ClassOfAllImages(vector<vector<int>> all_images);
};

