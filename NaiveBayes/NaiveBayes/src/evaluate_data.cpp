#include "evaluate_data.h"
#include "load_data.h"
#include "classify_data.h"
#include "analyze_data.h"

void EvaluateData::InitializeFields()
{
	classify_data.InitializeModel("../../../data/trainingimages.txt", "../../../data/traininglabels.txt");
	images = LoadData::LoadFeatureVectors("../../../data/testimages.txt");
	labels = LoadData::LoadLabelsVector("../../../data/testlabels.txt");
	guessed_labels = classify_data.ClassOfAllImages(
		LoadData::LoadFeatureVectors("../../../data/testimages.txt"));
}

void EvaluateData::GenerateConfusionMatrix()
{
	InitializeFields();
	vector<vector<double>> confusion_matrix(10, vector<double>(10));
	map<int, int> label_frequency = EvaluateData::GenerateLabelFrequency(labels);

	for (int i = 0; i < labels.size(); i++)
	{
		confusion_matrix[labels[i]][guessed_labels[i]]++;
		label_frequency[labels[i]]++;
	}

	std::cout << "confusion matrix: " << endl;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++) {
			confusion_matrix[i][j] /= label_frequency[i];
			printf("%-5.1f", confusion_matrix[i][j] * 100);
		}
	}
	std::cout << endl;
}

map<int, int> EvaluateData::GenerateLabelFrequency(vector<int> labels)
{
	/*map<int, int> label_frequencies;
	
	for (int index = 0; index < labels.size(); index++)
	{
		label_frequencies[labels[index]]++;
	}

	return label_frequencies;*/
}

void EvaluateData::GeneratePosteriorProbabilityImages()
{
	//label, vector<probability, image>
	/*map<int, vector<pair<double, vector<int>>>> best_images;


	for (auto it = best_images.begin(); it != best_images.end(); ++it)
	{
		sort(it->second.begin(), it->second.end(), [](std::pair<double, vector<int>> firstPair, std::pair<double, vector<int>> secondPair)
		{
			return firstPair.first < secondPair.first;
		});

		PrintMostAndLeastProbableImages(it->second.back().second, it->second[0].second, it->first);
	}*/
}

void EvaluateData::PrintMostAndLeastProbableImages(vector<int> worst_image, vector<int> best_image, int label_number)
{
	/*for (int pixel = 0; pixel < best_image.size(); pixel++)
	{
		if (pixel % 28 == 0 && pixel != 0)
		{
			std::cout << endl;
		}

		std::cout << best_image[pixel];
	}

	for (int pixel = 0; pixel < worst_image.size(); pixel++)
	{
		if (pixel % 28 == 0 && pixel != 0)
		{
			std::cout << endl;
		}

		std::cout << worst_image[pixel];
	}*/
}
