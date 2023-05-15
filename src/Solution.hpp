#pragma once

#include "Matrix.hpp"
#include "Solution.hpp"

using namespace std;

bool checkSolution(
	const vector<bool> &yi,
	const vector<tuple<int, int, double>> &flow,
	const unsigned int &flowNumber,
	const Matrix<double> &cij,
	const vector<double> &bi,
	vector<double> dj,
	const double &sum_dj);// Check if Solution is feasible

double f(
	const vector<bool> &yi,
	const vector<double> &fi,
	const double &transportation_cost); // Objective Function 

bool canUpdateXij(
	const vector<double> &bi,
	const vector<bool> &yi,
	const double &sum_dj); // Checks if Capacity can fullfill the Demand