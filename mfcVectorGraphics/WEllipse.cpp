#include "stdafx.h"
#include "WEllipse.h"


WEllipse::WEllipse(CPoint p1, CPoint p2) : P1(p1), P2(p2)
{
}


WEllipse::~WEllipse()
{
}

void WEllipse::drawShape(HWND hwnd) {

	HDC hdc;
	hdc = GetDC(hwnd);

	Ellipse(hdc, P1.x, P1.y, P2.x, P2.y);

	ReleaseDC(hwnd, hdc);
}

void WEllipse::resizeShape(CPoint p2)
{
	P2 = p2;
}
