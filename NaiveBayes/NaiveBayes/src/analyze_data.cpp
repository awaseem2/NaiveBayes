#include "analyze_data.h"

void AnalyzeData::PrintAccuracy()
{
	ClassifyData classify_data;
	classify_data.InitializeModel("../../../data/trainingimages.txt", "../../../data/traininglabels.txt");
	vector<int> correct_labels = LoadData::LoadLabelsVector("../../../data/testlabels.txt");
	vector<int> guessed_labels = classify_data.ClassOfAllImages(
		LoadData::LoadFeatureVectors("../../../data/testimages.txt"));

	int labels_guessed_accurately = 0;
	for (int index = 0; index < correct_labels.size(); index++)
	{
		if (correct_labels[index] == guessed_labels[index])
		{
			labels_guessed_accurately++;
		}
	}

	double accuracy = double(labels_guessed_accurately) / correct_labels.size();
	std::cout << "accuracy: " << accuracy << endl;
}