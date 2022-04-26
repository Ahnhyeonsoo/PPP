#pragma once

class MObject 
{

public:
	int x, y;
	MObject()
	{
		x = 30;
		y = 7;
	}
	virtual ~MObject(){}

	virtual void Start(){}
	virtual void Update() {}
	virtual void Render() {}

private:

};
