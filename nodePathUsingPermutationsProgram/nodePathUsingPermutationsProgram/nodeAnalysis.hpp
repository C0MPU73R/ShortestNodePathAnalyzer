#pragma once
#include <cmath>
#include <vector>
#include <algorithm>
#include "nodeInformation.hpp"
class nodeAnalysis
{
public:
	double getDistance(int x1, int y1, int x2, int y2)
	{
		int computation1 = (x2 - x1);
		int powComp1 = pow(computation1, 2);
		int computation2 = (y2 - y1);
		int powComp2 = pow(computation2, 2);
		int preDistance = powComp1 + powComp2;
		double distance = sqrt(preDistance);
		return distance;
	}
	double findMin(vector<double> distances)
	{
		double min = distances[0];
		for (int index = 1; index < distances.size(); index++)
		{
			if (distances[index] < min)
			{
				min = distances[index];
				grabIndex(index);
			}
		}
		return min;
	}

	void grabIndex(int i)
	{
		this->index = i;

	}
	int getIndex()
	{
		return this->index;
	}




	vector<vector<nodeInformation>> Permutations(vector<nodeInformation> nodes)
	{
		sort(nodes.begin(), nodes.begin() + nodes.size());
		vector<vector<nodeInformation>> perms;
		vector<nodeInformation> manipulatedList;
		do
		{
			for (int index = 0; index < nodes.size(); index++)
			{

				manipulatedList.push_back(nodes[index]);
			}
			perms.push_back(manipulatedList);
			manipulatedList.clear();
		} while (next_permutation(nodes.begin(), nodes.begin() + nodes.size()));

		return perms;
	}


private:
	int index;


};