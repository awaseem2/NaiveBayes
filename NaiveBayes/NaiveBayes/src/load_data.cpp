#include "load_data.h"


vector<vector<int>> LoadData::LoadFeatureVectors(string file_name)
{
	const int kPixelsPerImage = 784;
	vector<vector<int>> all_images_data;
	std::ifstream file(file_name);
	char current_character;

	int characters_added = 0;
	vector<int> current_vector;
	while (file.get(current_character))
	{
		if (current_character == '\n')
		{
			continue;
		}

		current_vector.push_back(GetTypeOfChar(current_character));
		characters_added++;

		if (characters_added % kPixelsPerImage == 0 && characters_added != 0)
		{
			all_images_data.push_back(current_vector);
			current_vector.clear();
		}



	}

	return all_images_data;
}

int LoadData::GetTypeOfChar(char character)
{
	switch (character)
	{
	case ' ':
		return 0;
	case '+':
		return 1;
	case '#':
		return 2;

	}
}

vector<int> LoadData::LoadLabelsVector(string file_name)
{
	//std::cout << "has to at least be here" << std::endl;
	vector<int> labels;
	std::ifstream file(file_name);
	char current_character;
	while (file.get(current_character))
	{
		if (current_character == '\n')
		{
			continue;
		}

		int character_converted_to_int = current_character - '0';
		labels.push_back(character_converted_to_int);
	}

	//std::cout << "and here" << std::endl; last thing it does
	return labels;

}

