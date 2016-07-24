
// ChildView.h : interface of the CChildView class
//

#pragma once
#include <vector>
#include "Shape.h"
#include "WLine.h"
#include "WRectangle.h"
#include "WEllipse.h"

// CChildView window

class CChildView : public CWnd
{
	// Construction
public:
	CChildView();

	// Attributes
public:

	enum ShapeGeometry { LineG, RectangleG, EllipseG };

	ShapeGeometry Type;

	// Operations
public:

	// Overrides
protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

	// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnToolBarButton1();
	afx_msg void OnToolBarButton2();
	afx_msg void OnToolBarButton3();
	DECLARE_MESSAGE_MAP()

private:
	CPoint pressedPoint;
	CPoint currentPoint;
	BOOL startDrawing;
	BOOL finishDrawing;

	std::vector<Shape*> shapes;

	Shape *shape;

};

