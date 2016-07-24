#pragma once
#include "Shape.h"

class WEllipse : public Shape
{
public:
	WEllipse(CPoint p1, CPoint p2);
	~WEllipse();

	void resizeShape(CPoint p2);
	void drawShape(HWND hwnd);

private:
	CPoint P1;
	CPoint P2;
};

