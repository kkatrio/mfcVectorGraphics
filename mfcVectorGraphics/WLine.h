#pragma once
#include "Shape.h"

class WLine : public Shape
{
public:
	WLine(CPoint p1, CPoint p2);
	~WLine();

	void drawShape(HWND hwnd);
	void resizeShape(CPoint p2);

protected:
	//ID2D1RenderTarget* m_pRenderTarget;



private:
	CPoint P1;
	CPoint P2;
};
