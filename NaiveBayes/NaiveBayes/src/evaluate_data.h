#pragma once
#include <vector>
#include <map>
#include "classify_data.h"

using std::vector;
using std::map;

class EvaluateData
{
public:
	vector<vector<int>> GenerateCorrectlyGuessedPixels();
	vector<vector<double>> GenerateConfusionMatrix(vector<vector<int>> correctly_guessed_pixels);
	map<int, int> GenerateLabelFrequency(vector<int> labels);
	void PrintConfusionMatrix();
	void InitializeFields();
	ClassifyData classify_data;
	vector<vector<int>> images;
	vector<int> labels;
	vector<int> guessed_labels;

};

