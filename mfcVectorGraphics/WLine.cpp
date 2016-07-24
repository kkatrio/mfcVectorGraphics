#include "stdafx.h"
#include "WLine.h"

WLine::WLine(CPoint p1, CPoint p2)
{

	P1 = p1;
	P2 = p2;
}

WLine::~WLine()
{
}

void WLine::drawShape(HWND hwnd) {

	HDC hdc;
	hdc = GetDC(hwnd);

	MoveToEx(hdc, P1.x, P1.y, NULL);
	LineTo(hdc, P2.x, P2.y);

	ReleaseDC(hwnd, hdc);

}

void WLine::resizeShape(CPoint p2) {

	P2 = p2;
}