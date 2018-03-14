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
	void GenerateConfusionMatrix();
	map<int, int> GenerateLabelFrequency(vector<int> labels);
	void PrintConfusionMatrix();
	void InitializeFields();
	void GeneratePosteriorProbabilityImages();
	void PrintMostAndLeastProbableImages(vector<int> worst_image, vector<int> best_image, int label_number);
	void PrintAccuracy();
	ClassifyData classify_data;
	vector<vector<int>> images;
	vector<int> labels;
	vector<int> guessed_labels;

};

