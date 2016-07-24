#include "stdafx.h"
#include "WRectangle.h"


WRectangle::WRectangle(CPoint p1, CPoint p2) : P1(p1), P2(p2)
{
}


WRectangle::~WRectangle()
{
}

void WRectangle::drawShape(HWND hwnd) {

	HDC hdc;
	hdc = GetDC(hwnd);

	Rectangle(hdc, P1.x, P1.y, P2.x, P2.y);

	ReleaseDC(hwnd, hdc);
}

void WRectangle::resizeShape(CPoint p2) {

	P2 = p2;
}