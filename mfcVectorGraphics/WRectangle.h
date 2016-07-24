#pragma once
#include "Shape.h"

class WRectangle : public Shape
{
public:
	WRectangle(CPoint p1, CPoint p2);
	~WRectangle();

	void resizeShape(CPoint P2);
	void drawShape(HWND hwnd);

private:
	CPoint P1;
	CPoint P2;
};

