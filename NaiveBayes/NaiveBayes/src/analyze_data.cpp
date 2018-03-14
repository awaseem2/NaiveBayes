#include "analyze_data.h"

void AnalyzeData::PrintAccuracy(std::vector<int> correct_labels, std::vector<int> guessed_labels)
{

	int labels_guessed_accurately = 0;
	for (int index = 0; index < correct_labels.size(); index++)
	{
		if (correct_labels[index] == guessed_labels[index])
		{
			labels_guessed_accurately++;
		}
	}

	double accuracy = double (labels_guessed_accurately) / correct_labels.size();
	std::cout << "accuracy: " << accuracy << std::endl;
}