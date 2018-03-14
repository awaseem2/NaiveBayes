#include "evaluate_data.h"
#include "load_data.h"
#include "classify_data.h"

vector<vector<int>> EvaluateData::GenerateCorrectlyGuessedPixels()
{
	vector<vector<int>> correctly_guessed_pixels(10, vector<int>(10)); //10 x 10

	for (int image_index = 0; image_index < images.size(); image_index++)
	{
		int image_class = labels[image_index];
		if (image_class == guessed_labels[image_index])
		{
			int updated_pixels = 0;
			while (updated_pixels < 10)
			{
				correctly_guessed_pixels[image_class][updated_pixels]++;
				updated_pixels++;
			}
		}
		
	}

	return correctly_guessed_pixels;
}

vector<vector<double>> EvaluateData::GenerateConfusionMatrix(vector<vector<int>> correctly_guessed_pixels)
{
	vector<vector<double>> confusion_matrix(10, vector<double>(10));
	map<int, int> label_frequency = EvaluateData::GenerateLabelFrequency(labels);

	for (int row = 0; row < correctly_guessed_pixels.size(); row++)
	{
		vector<double> current_row;

		for (int col = 0; col < correctly_guessed_pixels[row].size(); col++)
		{
			current_row.push_back((double)(correctly_guessed_pixels[row][col]) / label_frequency[row]);
		}

		confusion_matrix.push_back(current_row);
	}

	return confusion_matrix;
}

map<int, int> EvaluateData::GenerateLabelFrequency(vector<int> labels)
{
	map<int, int> label_frequencies;
	
	for (int index = 0; index < labels.size(); index++)
	{
		label_frequencies[labels[index]]++;
	}

	return label_frequencies;
}

void EvaluateData::PrintConfusionMatrix()
{
	InitializeFields();
	vector<vector<int>> correctly_guessed_pixels = GenerateCorrectlyGuessedPixels();
	vector<vector<double>> confusion_matrix = GenerateConfusionMatrix(correctly_guessed_pixels);

	for (int i = 0; i < confusion_matrix.size(); i++)
	{
		for (int j = 0; j < confusion_matrix[i].size(); j++)
		{
			std::cout << confusion_matrix[i][j] << " ";
		}
		
		std::cout << endl;
	}

}

void EvaluateData::InitializeFields()
{
	classify_data.InitializeModel("../../../data/trainingimages.txt", "../../../data/traininglabels.txt");
	images = LoadData::LoadFeatureVectors("../../../data/testimages.txt");
	labels = LoadData::LoadLabelsVector("../../../data/testlabels.txt");
	guessed_labels = classify_data.ClassOfAllImages(
		LoadData::LoadFeatureVectors("../../../data/testimages.txt"));
}