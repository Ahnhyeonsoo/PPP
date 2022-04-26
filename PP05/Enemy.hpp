#include "MObject.hpp"

class Enemy : public MObject
{
public:
	int x, y;
	Enemy()
	{
		x = 30;
		y = 7;
	}
	void Move()
	{
		if (x > 0) {
			x -= 1;
		}
		else {
			x = 30;
		}
	}
	

};