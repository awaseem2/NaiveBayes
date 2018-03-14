#include "model.h"
#include "load_data.h"




std::ostream& operator << (std::ostream& stream, const Model& model)
{
	for (auto const& feature : model.feature_frequency_map)
	{
		stream << std::get<0>(feature.first) << " " << std::get<1>(feature.first) << std::get<2>(feature.first) 
			<< feature.second << " " << feature.second << endl;
	}

	stream << "-" << endl;

	for (auto const& feature : model.class_frequency_map)
	{
		stream << feature.first << " " << feature.second << endl;
	}
}

std::istream& operator >> (std::istream& stream, const Model& model)
{
	string current_string;
	while (getline(stream, current_string) && current_string != "-")
	{
		std::istringstream iss(current_string);
		std::vector<string> entry{ std::istream_iterator<string>{iss}, std::istream_iterator<std::string>{} };

		model.class_frequency_map[std::stoi(entry[0]), std::stoi(entry[1]), std::stoi(entry[2])] = std::stoi(entry[3]);
	}

	while (getline(stream, current_string))
	{
		std::istringstream iss(current_string);
		std::vector<string> entry{ std::istream_iterator<string>{iss}, std::istream_iterator<std::string>{} };

		model.class_frequency_map[std::stoi(entry[0])] = std::stoi(entry[1]);
	}

}

//map<tuple<pixel, class, color>, frequency> 
void Model::InitializeMaps(string images_file_name, string labels_file_name)
{
	vector<vector<int>> feature_vectors = LoadData::LoadFeatureVectors(images_file_name);
	vector<int> labels_vector = LoadData::LoadLabelsVector(labels_file_name);
	for (int image_index = 0; image_index < feature_vectors.size(); image_index++)
	{
		for (int pixel = 0; pixel < feature_vectors[image_index].size(); pixel++)
		{
			feature_frequency_map[std::make_tuple(pixel, labels_vector[image_index], feature_vectors[image_index][pixel])]++;
		}

		class_frequency_map[labels_vector[image_index]]++;
	}
	//finishes this loop

}

void Model::LoadModel()
{
	std::ifstream stream("../../../data/model.txt");
	stream >> *this;
}

void Model::SaveModel()
{
	std::ofstream stream("../../../data/model.txt");
	stream << *this;
}

