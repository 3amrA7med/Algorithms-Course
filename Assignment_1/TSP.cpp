#include <iostream>
#include <vector>
#include<algorithm>
#include <chrono>
using namespace std;


int Tps(int**, int, int, bool&);
int calcRoute(vector<int>, int**, int, int, bool&);

/*
* This is the brute force solution
*/

int main()
{
	int numberOfCities, numberOfEdges, sourceCityIndex;
	int firstCity, secondCity, distanceBetween2Cities;
	int minDistance = 0;
	bool noRoute = true;
	cin >> numberOfCities >> sourceCityIndex >> numberOfEdges;

    auto start = chrono::steady_clock::now();

	int** graph = new int* [numberOfCities];

	for (int i = 0; i < numberOfCities; i++)
	{
		graph[i] = new int[numberOfCities] {0};
	}
	if (numberOfCities == 0)
	{
        auto end = chrono::steady_clock::now();
        auto diff = chrono::duration <double, milli>(end-start);
		cout << 0 << endl << diff.count();
		return 0;
	}
	if (numberOfCities == 1)
	{
        auto end = chrono::steady_clock::now();
        auto diff = chrono::duration <double, milli>(end-start);
		cout << 0 << endl << diff.count();
		return 0;
	}
	if (numberOfEdges == 0)
	{
        auto end = chrono::steady_clock::now();
        auto diff = chrono::duration <double, milli>(end-start);        
		cout << 0 << endl << diff.count();
		return 0;
	}



	for (int i = 0; i < numberOfEdges; i++)
	{
		cin >> firstCity >> secondCity >> distanceBetween2Cities;
		graph[firstCity][secondCity] = distanceBetween2Cities;
		graph[secondCity][firstCity] = distanceBetween2Cities;
	}
    start = chrono::steady_clock::now();
	if (numberOfCities == 2)
	{
		cout << graph[0][1]*2;
		return 0;
	}

	minDistance = Tps(graph, numberOfCities, sourceCityIndex, noRoute);
	if (noRoute) {
		cout << -1;
		return 0;
	}

    auto end = chrono::steady_clock::now();
    auto diff = chrono::duration <double, milli>(end-start);
	cout << minDistance << endl << diff.count() << endl;
	return 0;
}

int Tps(int** graph, int numberOfCities, int sourceCityIndex, bool&noRoute)
{
	vector<int> route;
	int distance, minDistance = 10000;
	for (int i = 0; i < numberOfCities; i++)
	{
		if (i != sourceCityIndex)
			route.push_back(i);
	}
	//Sort routes before loop
	sort(route.begin(), route.end());
	
	do
	{
		distance = calcRoute(route, graph, sourceCityIndex, numberOfCities, noRoute);
		if(distance != 0)
			if (distance < minDistance)
				minDistance = distance;

	} while (next_permutation(route.begin(), route.end()));
	return minDistance;
}


int calcRoute(vector<int> route, int** graph, int source , int numberOfCities , bool& noRoute)
{
	int distance = graph[source][route[0]];
	bool isRoute = true;
	if (distance == 0)
	{

		isRoute = false;
	}
	for (int i = 0; (i < (route.size()-1))&&isRoute; i++)
	{
		if (graph[route[i]][route[i + 1]] == 0)
		{
			isRoute = false;
			break;
		}
		distance += graph[route[i]][route[i + 1]];
	}
	if (isRoute)
	{
		distance += graph[route[route.size() - 1]][source];
		if (graph[route[route.size() - 1]][source] == 0)
		{
			distance = 0;
		}
		else
			noRoute = false;
	}
	else
		distance = 0;
	return distance;
}

