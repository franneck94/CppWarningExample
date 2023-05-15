#pragma once

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <random>
#include <iterator>
#include <numeric>
#include <chrono>

#include "Matrix.hpp"

using namespace std;

/*********************************************************************************/
/*                                HELPER FUNCTIONS                               */
/*********************************************************************************/

// Select Random index from Vector
template<typename T>
int select_randomly(const vector<T> &vec)
{
	if (vec.size() > 1)
	{
		random_device random_device;
		mt19937 engine{ random_device() };
		size_t upper = vec.size() - 1;
		uniform_int_distribution<int> dist(0, upper);

		return dist(engine);
	}

	return 0;
}

// Get Uniform Randomly Double or Integer Value
double get_random_double(const double lower, const double upper);
int get_random_int(const int lower, const int upper);

void printFinalSolution(
	const vector<bool> &yi,
	const double &fx,
	const unsigned int &kMax,
	const unsigned int &tMax,
	const unsigned int &shaking_mode,
	const unsigned int &local_search_mode,
	const unsigned int &update_xij_mode,
	const unsigned int &init_mode,
	const string &directory,
	chrono::steady_clock::time_point &bvns_start,
	chrono::steady_clock::time_point &bvns_end); // Print Solution Functions