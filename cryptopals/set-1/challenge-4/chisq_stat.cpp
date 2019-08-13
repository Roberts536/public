#include <iostream>
#include <vector>
#include <cassert>
#include <math.h>

/*
Calculates the Chi-squared statistic for the
data provided.
*/
float chisq_stat(
	const std::vector<float> observed, 
	const std::vector<float> expected)
{

	// Check the vectors have equal length at least 1
	assert(observed.size() == expected.size()
		&& "Must compare vectors of equal length");
	assert(observed.size()>0 &&
		"Input vectors cannot have length zero.");

	// Calculate the Chi-squared score
	float score = 0;
	for (int i=0; i<observed.size(); i++)
	{

		// Check no zero entries
		assert(expected[i]!=0 &&
			"No zero entries permitted in "
			"vector of expected values");

		float to_add = observed[i] - expected[i];
		to_add = pow(to_add, 2);
		to_add /= expected[i];
		score += to_add;
	}

	return score;
}
