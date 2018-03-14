#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "..\src\load_data.h"

TEST_CASE("Get Features Test")
{
	std::vector<int> expected_features = {0, 0, 1, 2, 2, 2, 0, 1, 0};
	std::vector<std::vector<int>> expected_result = { expected_features };
	REQUIRE(expected_result == LoadData::LoadFeatureVectors("test_3x3.txt"));
}

TEST_CASE("Get Labels Test")
{
	std::vector<int> expected_labels = { 4, 5, 6 };
	REQUIRE(expected_labels == LoadData::LoadLabelsVector("test_threelabels.txt"));
}

TEST_CASE("Get Type of Char Space Test")
{
	REQUIRE(0 == LoadData::GetTypeOfChar(' '));
}

TEST_CASE("Get Type of Char Plus Test")
{
	REQUIRE(1 == LoadData::GetTypeOfChar('+'));
}

TEST_CASE("Get Type of Char Hashtag Test")
{
	REQUIRE(2 == LoadData::GetTypeOfChar('#'));
}