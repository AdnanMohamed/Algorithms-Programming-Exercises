#pragma once
#include<vector>

// A class to implement the median mantenance algorithm.
// Problem Statement: Given a sequence of n integers: X1, X2, X3, ..., Xn
// compute and return a list (vector) of the ith median 'Mi', where
// Mi is the median of the first i elements.
class median_maintenance
{
public:
	median_maintenance(std::vector<int> seq);
	std::vector<int> get_medians()const { return medians; }
	int get_median(int i) const { return medians[i]; }
private:
	std::vector<int> medians;
};

