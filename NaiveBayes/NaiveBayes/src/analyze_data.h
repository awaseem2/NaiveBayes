#pragma once

#include <vector>
#include <iostream>

class AnalyzeData
{
public:
	static void PrintAccuracy(std::vector<int> correct_labels, std::vector<int> guessed_labels);
};

