#include "model.h"
#include "load_data.h"



std::ostream& operator << (std::ostream& stream, const Model& model)
{
	for (auto const& feature : model.feature_map)
	{
		stream << feature.first.first << " " << feature.first.second << " " << feature.second << endl;
	}
}

map<pair<int, int>, int> GenerateFeatureFrequencyMap(string file_name)
{
	vector<vector<int>> feature_vectors = LoadData::LoadFeatureVectors(file_name);
	vector<int> solutions_vectors = LoadData::LoadSolutionsVector(file_name);
	map<pair<int, int>, int> feature_frequency_map;


}



