
// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "mfcVectorGraphics.h"
#include "ChildView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_BUTTON_1, OnToolBarButton1)
	ON_COMMAND(ID_BUTTON_2, OnToolBarButton2)
	ON_COMMAND(ID_BUTTON_3, OnToolBarButton3)
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs)
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1), NULL);

	return TRUE;
}

void CChildView::OnPaint()
{
	CPaintDC dc(this); // device context for painting


	for (int i = 0; i < shapes.size(); i++) {
		shapes[i]->drawShape(m_hWnd);
	}

}

void CChildView::OnToolBarButton1() {

	Type = LineG;

}

void CChildView::OnToolBarButton2() {

	Type = RectangleG;
}

void CChildView::OnToolBarButton3() {

	Type = EllipseG;
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{

	if (startDrawing) {

		pressedPoint = point;

		switch (Type)
		{
		case CChildView::LineG:
			shape = new WLine(pressedPoint, pressedPoint);
			shapes.push_back(shape);
			break;

		case CChildView::RectangleG:
			shape = new WRectangle(pressedPoint, pressedPoint);
			shapes.push_back(shape);
			break;

		case CChildView::EllipseG:
			shape = new WEllipse(pressedPoint, pressedPoint);
			shapes.push_back(shape);
			break;

		default:
			MessageBox(_T("Choose an object!"));
			return;
			break;
		}


		Invalidate();
		UpdateWindow();


		startDrawing = false;
		finishDrawing = true;

	}
	else if (finishDrawing) {

		startDrawing = true;
		finishDrawing = false;

	}



}

void CChildView::OnMouseMove(UINT nFlags, CPoint point) {

	currentPoint = point;

	if (!startDrawing && finishDrawing) {

		shape->resizeShape(currentPoint);
		Invalidate();
		UpdateWindow();
	}

}