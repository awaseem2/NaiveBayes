#include "analyze_data.h"
#include "classify_data.h"
#include "load_data.h"


void AnalyzeData::PrintAccuracy()
{
	ClassifyData classify_data;
	LoadData load_data;
	classify_data.InitializeModel("../../../data/trainingimages.txt", "../../../data/traininglabels.txt");
	vector<int> correct_labels = load_data.LoadLabelsVector("../../../data/testlabels.txt");
	vector<int> guessed_labels = classify_data.ClassOfAllImages(
		load_data.LoadFeatureVectors("../../../data/testimages.txt"));

	int labels_guessed_accurately = 0;
	for (int index = 0; index < correct_labels.size(); index++)
	{
		std::cout << correct_labels[index] << " | " << guessed_labels[index] << endl;
		if (correct_labels[index] == guessed_labels[index])
		{
			labels_guessed_accurately++;
		}
	}

	double accuracy = double (labels_guessed_accurately) / double (correct_labels.size());
	std::cout << "accuracy: " << accuracy << endl;
}