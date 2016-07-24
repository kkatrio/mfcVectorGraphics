#pragma once
class Shape
{
public:

	virtual void resizeShape(CPoint p2) = 0;
	virtual void drawShape(HWND hwnd) = 0;

};

