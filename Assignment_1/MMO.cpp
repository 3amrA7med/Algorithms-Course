#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
struct matrix
{
	int rows;
	int cols;
};

long long MinOperation(vector<matrix>);
long long RecursiveMinOperation(vector<matrix>, long long);

/*
* This is the brute force solution
*/
int main()
{
	vector<matrix> matrices;
	int input;
	matrix m ;
	bool firstTime = true;
	long long minOperations;
	vector<int> v;
	while (cin >> input)
	{
		v.push_back(input);
	}
	for (int i = 0; i < v.size(); i++)
	{
		if (firstTime)
		{
			m.rows = v[i];
			firstTime = false;
		}
		else
		{
			m.cols = v[i];
			matrices.push_back(m);
			m.rows = v[i];
		}
	}
    auto start = chrono::steady_clock::now();
	if ((matrices.size() == 0) || (matrices.size() == 1))
	{
        auto end = chrono::steady_clock::now();
        auto diff = chrono::duration <double, milli>(end-start);
		cout << 0 << endl << diff.count();
		return 0;
	}
	if (matrices.size() == 2)
	{
        auto end = chrono::steady_clock::now();
        auto diff = chrono::duration <double, milli>(end-start);
		int result = matrices[0].rows * matrices[0].cols * matrices[1].cols;
		cout << result << endl << diff.count();
		return 0;
	}
	minOperations = MinOperation(matrices);
    auto end = chrono::steady_clock::now();
    auto diff = chrono::duration <double, milli>(end-start);
	cout << minOperations << endl;
    cout <<  chrono::duration <double, milli> (diff).count()<<endl;
	return 0;
}


long long MinOperation(vector<matrix>matrices)
{
	long long minOperations = 1e18;
	minOperations = RecursiveMinOperation(matrices, minOperations);
	return minOperations;
}
long long RecursiveMinOperation(vector<matrix>matrices, long long minOperations)
{
	if (matrices.size() == 1 || matrices.size() == 0)
		return 0;
	if (matrices.size() == 2)
		return matrices[0].rows * matrices[0].cols * matrices[1].cols;
	long long operations;
	vector<matrix> temp, empty;
	matrix m;
	for (int i = 0; i < (matrices.size()-1); i++)
	{
		temp = empty;
		m.rows = matrices[i].rows;
		m.cols = matrices[i + 1].cols;
		for (int j = 0; j < (matrices.size()); j++)
		{
			if (j == i)
				continue;
			if (j == i + 1)
				temp.push_back(m);
			else
				temp.push_back(matrices[j]);
		}
		operations = RecursiveMinOperation(temp, minOperations) + (long long)matrices[i].rows * matrices[i].cols * matrices[i + 1].cols;
		if (minOperations > operations)
			minOperations = operations;
	}
	return minOperations;
}