#include <iostream>
#include <vector>
#include <chrono>

/*
* This is the brute force solution
*/
using namespace std;
vector<int> CheckInClique(int, vector<int>cliqueVec, int**);
int main()
{
	int numberOfNodes;
	int numberOfEdges;
	int firstNode, secondNode;
	int maxClique=1;
	cin >> numberOfNodes >> numberOfEdges;

    auto start = chrono::steady_clock::now();

	int** graph = new int*[numberOfNodes];

	for (int i = 0; i < numberOfNodes; i++)
	{
		graph[i] = new int[numberOfNodes] {0};
	}
	if (numberOfNodes == 0)
	{
        auto end = chrono::steady_clock::now();
        auto diff = chrono::duration <double, milli>(end-start);
		cout << 0 << endl << diff.count() ;
		return 0;
	}
	if (numberOfNodes == 1)
	{
        auto end = chrono::steady_clock::now();
        auto diff = chrono::duration <double, milli>(end-start);
		cout << 1 << endl << diff.count() ;
		return 0;
	}
	if (numberOfEdges == 0)
	{
        auto end = chrono::steady_clock::now();
        auto diff = chrono::duration <double, milli>(end-start);
		cout << 1 << endl << diff.count() ;
		return 0;
	}
	if (numberOfEdges == 1)
	{

		cin >> firstNode >> secondNode;
        auto end = chrono::steady_clock::now();
        auto diff = chrono::duration <double, milli>(end-start);
		cout << 2 << endl << diff.count() ;
		return 0;
	}


	for (int i = 0; i < numberOfEdges; i++)
	{
		cin >> firstNode >> secondNode;
		graph[firstNode][secondNode] = 1;
		graph[secondNode][firstNode] = 1;
	}
    start = chrono::steady_clock::now();
	vector<int> cliqueVec, temp;
	for (int i = 0; i < numberOfNodes; i++)
	{
		for (int j = i+1; j < numberOfNodes; j++)
		{
			cliqueVec = temp;
			if (graph[i][j] == 0)
				continue;
			cliqueVec.push_back(i);
			cliqueVec.push_back(j);
			for (int k = j + 1; k < numberOfNodes; k++)
			{
				cliqueVec = CheckInClique(k,cliqueVec,graph);
			}
			if (maxClique < cliqueVec.size())
				maxClique = cliqueVec.size();

		}
	}

    auto end = chrono::steady_clock::now();
    auto diff = chrono::duration <double, milli>(end-start);
	cout << maxClique << endl << diff.count() ;
	return 0;
}


vector<int> CheckInClique(int k, vector<int>cliqueVec, int** graph)
{
	bool isInClique = true;
	for (int i = 0; i < cliqueVec.size(); i++) 
	{
		if (graph[k][cliqueVec[i]] == 0)
		{
			isInClique = false;
			break;
		}
	}
	if (isInClique)
		cliqueVec.push_back(k);
	return cliqueVec;
}