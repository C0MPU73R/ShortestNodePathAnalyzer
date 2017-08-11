#include <iostream>
#include <vector>
#include <algorithm>
#include "nodeInformation.hpp"
#include "nodeAnalysis.hpp"
using namespace std;
int main()
{
	int numberOfLocations;
	vector<nodeInformation> nodeStops;
	int x;
	int y;
	string name;
	cout << "Enter the amount of locations to consider: ";
	cin >> numberOfLocations;
	cout << endl;
	cout << "NOTE: This program starts you at the location 0,0 and ends you at the location 0,0. So consider this if you want to work out the maths" << endl;
	cout << "SO: If you are analyzing the permutation 1234, you will start at position 0,0 go to whatever x,y location 1 has, then to 2, then to 3, then to 4, and back to 0,0" << endl;
	cout << "Enter the x position, y position, and the name of the node for each of the" << numberOfLocations << " locations: " << endl;

	for (int index = 0; index < numberOfLocations; index++)
	{
		cin >> x;
		cin >> y;
		cin >> name;
		nodeStops.push_back(nodeInformation(x, y, name));
		nodeStops[index].setLoc(index + 1);

	}
	cout << "The data about to be printed will be the permutations of all the locations that you just entered." << endl;
	cout << "The first location you entered is denoted as a 1, the second location as a 2, and so on..." << endl;
	nodeAnalysis obj;
	vector<vector<nodeInformation>> perms = obj.Permutations(nodeStops);

	//print test
	cout << "These are the possible permutations we will consider to visit" << endl;
	for (int index = 0; index < perms.size(); index++)
	{
		for (int index2 = 0; index2 < perms[index].size(); index2++)
		{
			cout << perms[index][index2];
		}
		cout << endl;
	}

	//time to infuse  starting at 0,0
	vector<double> distances;
	vector<vector<nodeInformation>> permutationsToAccess;
	double tD = 0.0;
	int index2 = 0;
	for (int index = 0; index < perms.size(); index++)
	{
		tD = 0.0;
		tD += obj.getDistance(0, 0, perms[index][index2].getX(), perms[index][index2].getY());

		for (index2 = 0; index2 < perms[index].size() - 1; index2++)
		{
			tD += obj.getDistance(perms[index][index2].getX(), perms[index][index2].getY(), perms[index][index2 + 1].getX(), perms[index][index2 + 1].getY());

		}
		tD += obj.getDistance(perms[index][index2].getX(), perms[index][index2].getY(), 0, 0);

		distances.push_back(tD);
		permutationsToAccess.push_back(perms[index]);


	}

	cout << "These are all the possible distances from the permutations above" << endl;
	cout << "So the first number displayed below this message represents the distance of the first permutation and so on..." << endl;
	for (int index = 0; index < distances.size(); index++)
	{
		cout << distances[index] << endl;
	}

	cout << "The minimum distance to visit all locations is: " << obj.findMin(distances) << endl;
	int i = obj.getIndex();

	cout << "The permutation that has the minimum distance to visit all locations is: ";
	for (int index2 = 0; index2 < permutationsToAccess[i].size(); index2++)
	{
		cout << permutationsToAccess[i][index2];
	}



	system("pause");
	return 0;
}