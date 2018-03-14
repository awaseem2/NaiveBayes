#include <cstdio>
#include "analyze_data.h"
#include "model.h"
#include "evaluate_data.h"

int main()
{
	AnalyzeData analyze_data;
	//analyze_data.PrintAccuracy();
	EvaluateData evaluate_data;
	evaluate_data.PrintConfusionMatrix();
    return 0;
}