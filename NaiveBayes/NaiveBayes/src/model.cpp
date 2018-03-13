#include "model.h"
#include "load_data.h"




std::ostream& operator << (std::ostream& stream, const Model& model)
{
	for (auto const& feature : model.feature_frequency_map)
	{
		//stream << feature.first.first << " " << feature.first.second << " " << feature.second << endl;
	}
}

//map<tuple<pixel, class, color>, frequency> 
void Model::InitializeMaps(string images_file_name, string labels_file_name)
{
	vector<vector<int>> feature_vectors = LoadData::LoadFeatureVectors(images_file_name);
	vector<int> labels_vector = LoadData::LoadLabelsVector(labels_file_name);

	for (int image_index = 0; image_index < feature_vectors.size(); image_index++)
	{
		for (int pixel = 0; feature_vectors[image_index].size(); pixel++)
		{
			feature_frequency_map[std::make_tuple(pixel, labels_vector[image_index], feature_vectors[image_index][pixel])]++;
		}

		class_frequency_map[labels_vector[image_index]]++;
	}
	

}


