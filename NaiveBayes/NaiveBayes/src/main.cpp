#include <cstdio>
#include "analyze_data.h"
#include "model.h"
#include "evaluate_data.h"

int main()
{
	EvaluateData evaluate_data;
	evaluate_data.PrintAccuracy();
	evaluate_data.GenerateConfusionMatrix();
    return 0;
}