#include "classify_data.h"

int ClassifyData::ClassOfImage(vector<int> image)
{
	map<int, double> posterior_per_class;
	double k_constant = 0.1;

	for (int class_number = 0; class_number < 10; class_number++) 
	{
		double current_posterior_variable = log( model.class_frequency_map[class_number]
			/ model.class_frequency_map.size() );

		for (int pixel = 0; pixel < image.size(); pixel++)
		{
			double numerator = k_constant +
				model.feature_frequency_map[std::make_tuple(pixel, class_number, image[pixel])];
			double denominator = (2 * k_constant) + model.class_frequency_map[class_number];
			current_posterior_variable += log( numerator / denominator);
		}

		posterior_per_class[class_number] = current_posterior_variable;
	}

	//https://stackoverflow.com/questions/30611709/find-element-with-max-value-from-stdmap
	auto max_value = std::max_element(posterior_per_class.begin(), posterior_per_class.end(), 
		[](const pair<double, double>& pair1, const pair<double, double>& pair2)
	{
		return pair1.second < pair2.second;
	});
	
	double max_key = max_value -> first;

	return max_key;
}

vector<int> ClassifyData::ClassOfAllImages(vector<vector<int>> all_images)
{
	vector<int> classified_images;
	for (vector<int> current_image : all_images)
	{
		classified_images.push_back(ClassOfImage(current_image));
	}

	return classified_images;
}

void ClassifyData::InitializeModel(string images_file_name, string labels_file_name)
{
	model.InitializeMaps(images_file_name, labels_file_name);
}





