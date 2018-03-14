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
	map<int, double> posterior_per_class;
	int ClassOfImage(vector<int> image);
	void InitializeModel(string images_file_name, string labels_file_name);
	vector<int> ClassOfAllImages(vector<vector<int>> all_images);
	double FindPosteriorProbability(int pixel, int class_number, int value);
	//map<pair<vector<int>, int>, double> posterior_probabilities;
	vector<int, pair<vector<int>, double>> posterior_probabilities;
};

