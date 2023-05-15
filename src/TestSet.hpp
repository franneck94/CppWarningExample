#pragma once
using namespace std;

#include "Matrix.hpp"

/*********************************************************************************/
/*                                CLASS FOR TESTSET                              */
/*********************************************************************************/

class TestSet
{
public:
	TestSet(const string &directory); // Loads Data from TestSet
	void ReadInData(
		const string &directory,
		vector<double> &dj,
		vector<double> &bi,
		vector<double> &fi,
		Matrix<double> &cij); // RAII Model to Read in Data

protected:
	const string m_directory; // Directory
	// Set Ranges
	size_t m_locationNumber; // I = 0, ..., I - 1
	size_t m_customerNumber; // J = 0, ..., J - 1
	// Vector
	vector<double> m_dj; // Demand of customer j
	vector<double> m_bi; // Capacity of facility i
	vector<double>m_fi; // Opening Costs of Facility i
	// Matrix
	Matrix<double> m_cij; // Link Costs (i,j)
};