#pragma once
#include <string>
using namespace std;
class nodeInformation
{

public:

	nodeInformation(int x, int y)
	{
		this->x = x;
		this->y = y;
		
	}

	int getX()
	{
		return this->x;
	}

	int getY()
	{
		return this->y;
	}


	void setLoc(int Loc)
	{
		location = Loc;
	}

	int getLoc()
	{
		return this->location;
	}
	//overloaded equal sign for possible use
	void operator= (int Loc)
	{
		location = Loc;
	}

	friend ostream& operator<<(ostream& out, nodeInformation rhs)
	{
		out << rhs.getLoc();

		return out;
	}


private:

	int x;
	int y;
	int location;
	friend bool operator<(const nodeInformation& lhs, const nodeInformation& rhs)
	{
		return lhs.location < rhs.location;
	}

};